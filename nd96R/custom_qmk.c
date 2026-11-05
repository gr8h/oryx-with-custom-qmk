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
