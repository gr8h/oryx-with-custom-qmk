// Custom QMK features layered on top of the Oryx export.
//
// This file is not compiled on its own: rules.mk sets INTROSPECTION_KEYMAP_C so
// QMK includes it right after keymap.c (needed for key_overrides). Keep the
// Oryx-generated keymap.c untouched so Oryx exports keep merging cleanly.
//
// Keys are identified by *physical position* (matrix row/col), not keycode, so
// the logic keeps working whatever keycodes Oryx generates for each thumb.
// Layout design and reasoning: docs/layout-review/

#include QMK_KEYBOARD_H
#include "keymap_introspection.h"

// ---------------------------------------------------------------------------
// Layer numbers (must match the layer order in Oryx)
// ---------------------------------------------------------------------------
#define NUM_LAYER 1 // Numbers + IDE   (hold L-inner thumb)
#define SYM_LAYER 2 // Symbols         (hold R-inner thumb)
#define NAV_LAYER 3 // Nav             (hold L-outer thumb / Space)
#define FN_LAYER 5  // F-keys + media  (press both inner thumbs together)

#define FN_CHORD_TERM 35  // ms: both inner thumbs must go down within this window
#define NUM_GUARD_TERM 150 // ms: see the Numbers guard below

// ---------------------------------------------------------------------------
// Physical key positions on the Voyager matrix (from keyboard.json)
// ---------------------------------------------------------------------------
#define POS(r, c) ((keypos_t){.row = (r), .col = (c)})
#define L_OUTER_THUMB POS(5, 0)   // Space / Nav
#define L_INNER_THUMB POS(5, 1)   // Shift+Enter / Numbers
#define R_INNER_THUMB POS(11, 5)  // Tab / Symbols
#define R_OUTER_THUMB POS(11, 6)  // Esc / Shift
#define HRM_A POS(2, 2)           // A / Ctrl
#define HRM_S POS(2, 3)           // S / Alt
#define HRM_D POS(2, 4)           // D / Cmd
#define HRM_K POS(8, 2)           // K / Cmd
#define HRM_L POS(8, 3)           // L / Alt
#define HRM_COLON POS(8, 4)       // : / Ctrl

static inline bool pos_is(const keyrecord_t *record, keypos_t pos) {
    return record->event.key.row == pos.row && record->event.key.col == pos.col;
}

static bool is_thumb(const keyrecord_t *record) {
    return pos_is(record, L_OUTER_THUMB) || pos_is(record, L_INNER_THUMB) || pos_is(record, R_INNER_THUMB) || pos_is(record, R_OUTER_THUMB);
}

static bool is_home_row_mod(const keyrecord_t *record) {
    return pos_is(record, HRM_A) || pos_is(record, HRM_S) || pos_is(record, HRM_D) || pos_is(record, HRM_K) || pos_is(record, HRM_L) || pos_is(record, HRM_COLON);
}

// ---------------------------------------------------------------------------
// Chordal Hold: a home-row mod only becomes a modifier when the next key is on
// the other hand, so fast same-hand rolls stay letters. Thumbs are '*'
// (exempt), otherwise e.g. right-thumb Shift + right-hand letter would resolve
// as Esc + lowercase.
// ---------------------------------------------------------------------------
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R', 'R',
                        '*', '*',      '*', '*'
);

// ---------------------------------------------------------------------------
// Tap-hold tuning
// ---------------------------------------------------------------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (pos_is(record, R_OUTER_THUMB)) {
        return 160; // a real Esc tap is <100 ms; lets a lingering capital resolve as Shift
    }
    if (pos_is(record, HRM_A) || pos_is(record, HRM_S) || pos_is(record, HRM_L) || pos_is(record, HRM_COLON)) {
        return 230; // ring and pinky fingers lift more slowly
    }
    return TAPPING_TERM;
}

// Set in pre_process_record_user (which runs before the tap-hold decision):
// true when the key just released is the R-inner thumb.
static bool last_release_was_r_inner = false;

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (pos_is(record, L_OUTER_THUMB)) {
        // Space stays strict so fast typing never opens Nav by accident...
        // ...except Space + tap R-inner, which is Enter on Nav: fire it at once.
        return last_release_was_r_inner;
    }
    return true; // home-row mods, Numbers, Symbols, Esc/Shift
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Symbols thumb only: a rolled symbol never leaks a Tab.
    return pos_is(record, R_INNER_THUMB);
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    // Thumbs: tap-then-hold gives the layer/modifier, never auto-repeat.
    return is_thumb(record) ? 0 : QUICK_TAP_TERM;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    // Flow Tap only on the home-row mods: mid-word they always type letters.
    // Never on thumbs: Space must still reach Nav right after typing (send a
    // message), and Oryx's placeholder for the Numbers thumb is a letter key.
    if (is_home_row_mod(record) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// Key override: Shift + ; types ?  (the ANSI '/' spot, where Mac hands expect it)
// ---------------------------------------------------------------------------
const key_override_t shift_semicolon_question = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_QUES);
const key_override_t *key_overrides[]         = {&shift_semicolon_question};

// ---------------------------------------------------------------------------
// Leader: in Oryx put F24 on the Leader key; tap it, then one letter.
// ---------------------------------------------------------------------------
bool leader_add_user(uint16_t keycode) {
    return true; // every sequence is one key long: finish immediately
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_M)) {
        SEND_STRING("&mut ");
    } else if (leader_sequence_one_key(KC_S)) {
        SEND_STRING("&mut self");
    } else if (leader_sequence_one_key(KC_D)) {
        SEND_STRING("#[derive(Debug, Clone)]");
    } else if (leader_sequence_one_key(KC_T)) {
        SEND_STRING("#[test]");
    } else if (leader_sequence_one_key(KC_C)) {
        SEND_STRING("#[cfg(test)]");
    } else if (leader_sequence_one_key(KC_U)) {
        SEND_STRING(".unwrap()");
    } else if (leader_sequence_one_key(KC_E)) {
        SEND_STRING(".expect(\"\")" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    } else if (leader_sequence_one_key(KC_O)) {
        SEND_STRING("Ok(())");
    } else if (leader_sequence_one_key(KC_P)) {
        SEND_STRING("println!(\"{:?}\", );" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
}

// ---------------------------------------------------------------------------
// Lights: calm Base, one colour per layer. Preview and reasoning are on the
// "Lights" tab of docs/layout-review/index.html.
//
// This runs after Oryx's own layer colours, so it wins on every layer listed
// in light_map below. The Mouse layer keeps its Oryx colours. Brightness still
// follows the Bri -/+ keys, and Oryx's "toggle layer colours" key and live
// training mode still work.
// ---------------------------------------------------------------------------
#define MOUSE_LAYER 4
#define LIGHT_DIM_PERCENT 40 // brightness of the "dim" keys; bright keys use 100%

enum light_role { LR_OFF, LR_LETTERS, LR_MOD, LR_EDIT, LR_NAV, LR_NUM, LR_SYM, LR_APP, LR_FN, LR_LOCK, LR_DANGER, LR_COUNT };
#define LIGHT_BRIGHT 0x80

// Palette: change a role's colour here. Hue and saturation use QMK's 0-255
// scale (sat 0 = white). on = false switches the role off.
typedef struct {
    uint8_t h, s;
    bool    on;
} light_color_t;
static const light_color_t light_colors[LR_COUNT] = {
    [LR_OFF]     = {0, 0, false},
    [LR_LETTERS] = {0, 0, false},   // Base letters: off
    [LR_MOD]     = {85, 255, true},  // green:   modifiers on every layer
    [LR_EDIT]    = {0, 0, true},     // white:   Esc, Tab, Bspc, Enter, Del, clipboard, Leader, Caps Word
    [LR_NAV]     = {128, 255, true}, // cyan:    Nav layer + the Space thumb
    [LR_NUM]     = {21, 255, true},  // amber:   Numbers layer + the newline thumb
    [LR_SYM]     = {213, 255, true}, // magenta: Symbols layer + the Tab thumb
    [LR_APP]     = {170, 255, true}, // blue:    VS Code / app shortcuts, media, screenshots
    [LR_FN]      = {21, 255, true},  // amber:   F-keys (same shape as the digits)
    [LR_LOCK]    = {0, 0, true},     // white:   Layer Lock (bright while locked)
    [LR_DANGER]  = {0, 0, true},     // white:   Boot and Lock screen
};

// Lower case = dim, upper case = bright, __ = off
#define __ LR_OFF
#define ab LR_LETTERS
#define md LR_MOD
#define MD (LR_MOD | LIGHT_BRIGHT)
#define ed LR_EDIT
#define ED (LR_EDIT | LIGHT_BRIGHT)
#define nv LR_NAV
#define NV (LR_NAV | LIGHT_BRIGHT)
#define nm LR_NUM
#define NM (LR_NUM | LIGHT_BRIGHT)
#define sy LR_SYM
#define SY (LR_SYM | LIGHT_BRIGHT)
#define ap LR_APP
#define AP (LR_APP | LIGHT_BRIGHT)
#define fk LR_FN
#define FK (LR_FN | LIGHT_BRIGHT)
#define lk LR_LOCK
#define dg LR_DANGER

// clang-format off
static const uint8_t PROGMEM light_map[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base
    [0] = LAYOUT(
        ed, __, __, __, __, ed,      ed, __, __, __, __, ap,
        ed, ab, ab, ab, ab, ab,      ab, ab, ab, ab, ab, ed,
        md, md, md, md, ab, ab,      ab, ab, md, md, md, ab,
        ed, ab, ab, ab, ab, ab,      ab, ab, ab, ab, ab, ab,
                            NV, NM,      SY, MD
    ),
    // Numbers + IDE
    [1] = LAYOUT(
        __, __, __, __, __, __,      __, __, __, __, __, __,
        __, lk, ap, ap, ap, ap,      nm, NM, NM, NM, nm, __,
        __, md, md, md, ap, ap,      nm, NM, NM, NM, nm, nm,
        __, ap, ap, ap, ap, ap,      NM, NM, NM, NM, nm, __,
                            __, NM,      __, __
    ),
    // Symbols
    [2] = LAYOUT(
        __, __, __, __, __, __,      __, __, __, __, __, __,
        __, sy, sy, SY, SY, sy,      sy, SY, SY, __, __, __,
        __, sy, sy, SY, SY, sy,      sy, SY, SY, sy, sy, sy,
        __, sy, sy, SY, SY, sy,      __, __, __, __, __, __,
                            __, __,      SY, __
    ),
    // Nav
    [3] = LAYOUT(
        __, __, __, __, __, __,      __, __, __, __, __, __,
        __, __, ap, ap, ap, ap,      ap, ap, ap, ap, __, ED,
        __, md, md, md, md, lk,      NV, NV, NV, NV, __, __,
        __, ed, ed, ed, ed, ed,      nv, nv, nv, nv, __, __,
                            NV, __,      ED, __
    ),
    // F-keys + media
    [5] = LAYOUT(
        dg, __, __, __, __, __,      __, __, __, __, __, dg,
        __, FK, FK, FK, FK, __,      ap, ap, ap, ap, __, __,
        __, FK, FK, FK, FK, __,      __, md, md, md, md, __,
        __, FK, FK, FK, FK, lk,      ap, ed, ed, ed, __, __,
                            __, FK,      FK, __
    ),
};
// clang-format on

#undef __
#undef ab
#undef md
#undef MD
#undef ed
#undef ED
#undef nv
#undef NV
#undef nm
#undef NM
#undef sy
#undef SY
#undef ap
#undef AP
#undef fk
#undef FK
#undef lk
#undef dg

#define CAPS_WORD_SHIFT_KEY POS(2, 1) // one-shot Shift on Base
#define CAPS_WORD_KEY POS(6, 0)       // Caps Word key (number row, right inner)

// The light map describes the new layout. Until Oryx has it (Space on Base
// holds the Nav layer), keep Oryx's own colours so nothing is mislabelled.
static bool new_layout_in_oryx(void) {
    static int8_t cached = -1;
    if (cached < 0) {
        cached = keymap_key_to_keycode(0, L_OUTER_THUMB) == LT(NAV_LAYER, KC_SPACE);
    }
    return cached;
}

static RGB light_rgb(uint8_t code, uint8_t brightness) {
    const uint8_t role = code & (uint8_t)~LIGHT_BRIGHT;
    if (role >= LR_COUNT || !light_colors[role].on) {
        return (RGB){0, 0, 0};
    }
    const uint8_t v   = (code & LIGHT_BRIGHT) ? 255 : (uint8_t)(255 * LIGHT_DIM_PERCENT / 100);
    RGB           rgb = hsv_to_rgb((HSV){light_colors[role].h, light_colors[role].s, v});
    rgb.r             = (uint16_t)rgb.r * brightness / 255;
    rgb.g             = (uint16_t)rgb.g * brightness / 255;
    rgb.b             = (uint16_t)rgb.b * brightness / 255;
    return rgb;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (rawhid_state.rgb_control || keyboard_config.disable_layer_led || !new_layout_in_oryx()) {
        return true; // live training, layer colours switched off, or old layout
    }
    const uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    if (layer == MOUSE_LAYER || layer >= ARRAY_SIZE(light_map)) {
        return true; // keep Oryx's colours
    }
    const uint8_t brightness = rgb_matrix_get_val();
    const bool    locked     = is_layer_locked(layer);
    const bool    caps_word  = is_caps_word_on();
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            const uint8_t led = g_led_config.matrix_co[row][col];
            if (led == NO_LED || led < led_min || led >= led_max) {
                continue;
            }
            uint8_t code = pgm_read_byte(&light_map[layer][row][col]);
            if (locked && (code & (uint8_t)~LIGHT_BRIGHT) == LR_LOCK) {
                code |= LIGHT_BRIGHT;
            }
            if (caps_word && layer == 0) {
                const keypos_t here = POS(row, col);
                if ((here.row == CAPS_WORD_SHIFT_KEY.row && here.col == CAPS_WORD_SHIFT_KEY.col) || (here.row == CAPS_WORD_KEY.row && here.col == CAPS_WORD_KEY.col)) {
                    code = LR_EDIT | LIGHT_BRIGHT;
                }
            }
            const RGB c = light_rgb(code, brightness);
            rgb_matrix_set_color(led, c.r, c.g, c.b);
        }
    }
    return false;
}

// ---------------------------------------------------------------------------
// Event hooks that run before the tap-hold logic
// ---------------------------------------------------------------------------

// F-keys chord: both inner thumbs pressed within FN_CHORD_TERM opens FN_LAYER
// while held. A rolling overlap (e.g. typing `[0]`) is slower than that, so it
// never opens the layer. Layer Lock keeps it on after the thumbs are released.
static bool     l_inner_down = false, r_inner_down = false, fn_chord_active = false;
static uint16_t l_inner_time = 0, r_inner_time = 0;

static void handle_fn_chord(keyrecord_t *record) {
    const bool left = pos_is(record, L_INNER_THUMB);
    if (record->event.pressed) {
        if (left) {
            l_inner_down = true;
            l_inner_time = record->event.time;
        } else {
            r_inner_down = true;
            r_inner_time = record->event.time;
        }
        if (l_inner_down && r_inner_down && !fn_chord_active && FN_LAYER < keymap_layer_count()) {
            const uint16_t gap = left ? TIMER_DIFF_16(l_inner_time, r_inner_time) : TIMER_DIFF_16(r_inner_time, l_inner_time);
            if (gap <= FN_CHORD_TERM) {
                fn_chord_active = true;
                layer_on(FN_LAYER);
            }
        }
    } else {
        if (left) {
            l_inner_down = false;
        } else {
            r_inner_down = false;
        }
        if (fn_chord_active) {
            fn_chord_active = false;
            if (!is_layer_locked(FN_LAYER)) {
                layer_off(FN_LAYER);
            }
        }
    }
}

// Numbers guard: the left hand of the Numbers layer holds VS Code shortcuts.
// If one of those (any key that sends a modifier combo) is hit within
// NUM_GUARD_TERM of a right-hand key, the thumb was simply released late
// (`-r`, `3rd`, `0x`), so type the Base-layer letter instead.
static uint16_t last_right_press_time = 0;
static keypos_t guarded_key;
static bool     guarded_key_down = false;

static bool handle_num_guard(uint16_t keycode, keyrecord_t *record) {
    if (guarded_key_down && !record->event.pressed && record->event.key.row == guarded_key.row && record->event.key.col == guarded_key.col) {
        guarded_key_down = false;
        return false; // swallow the release of the key we replaced
    }
    if (!record->event.pressed) {
        return true;
    }
    const char hand = chordal_hold_handedness(record->event.key);
    if (hand == 'R') {
        last_right_press_time = record->event.time;
        return true;
    }
    if (hand == 'L' && get_highest_layer(layer_state) == NUM_LAYER && IS_QK_MODS(keycode) && TIMER_DIFF_16(record->event.time, last_right_press_time) < NUM_GUARD_TERM) {
        uint16_t base = keymap_key_to_keycode(0, record->event.key);
        if (IS_QK_MOD_TAP(base)) {
            base = QK_MOD_TAP_GET_TAP_KEYCODE(base);
        } else if (IS_QK_LAYER_TAP(base)) {
            base = QK_LAYER_TAP_GET_TAP_KEYCODE(base);
        }
        if (IS_BASIC_KEYCODE(base)) {
            tap_code(base);
            guarded_key      = record->event.key;
            guarded_key_down = true;
            return false;
        }
    }
    return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!IS_KEYEVENT(record->event)) {
        return true;
    }

    if (!record->event.pressed) {
        last_release_was_r_inner = pos_is(record, R_INNER_THUMB);
    }

    if (pos_is(record, L_INNER_THUMB) || pos_is(record, R_INNER_THUMB)) {
        handle_fn_chord(record);
    }

    // Leader key (F24 placeholder set in Oryx)
    if (keycode == KC_F24) {
        if (record->event.pressed) {
            leader_start();
        }
        return false;
    }

    return handle_num_guard(keycode, record);
}
