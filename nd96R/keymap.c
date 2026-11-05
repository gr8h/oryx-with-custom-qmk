// Originally exported from Oryx (layout nd96R). The key layout is now
// maintained in this file, not in Oryx: editing the layout in Oryx would
// overwrite or conflict with it on the next "Fetch and build layout" run.
// Design and reasoning: docs/layout-review/. Custom behaviour: custom_qmk.c.
#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ARROW_R,   // types ->
  FAT_ARROW, // types =>
};



#define DUAL_FUNC_0 LT(3, KC_X)     // tap :, hold Right Ctrl (handled below)
#define NUM_NEWLINE LT(1, KC_ENTER) // tap Shift+Enter, hold Numbers (handled below)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base
  [0] = LAYOUT_voyager(
    KC_ESCAPE, KC_NO, KC_NO, KC_NO, KC_NO, QK_LEAD,                    CW_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(LGUI(LSFT(KC_4))),
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    OSM(MOD_LSFT), MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), KC_F, KC_G,                    KC_H, KC_J, MT(MOD_RGUI, KC_K), MT(MOD_RALT, KC_L), DUAL_FUNC_0, KC_QUOTE,
    KC_BSPC, KC_Z, KC_X, KC_C, KC_V, KC_B,                    KC_N, KC_M, KC_COMMA, KC_DOT, KC_SCLN, KC_EQUAL,
                                    LT(3, KC_SPACE), NUM_NEWLINE,                    LT(2, KC_TAB), MT(MOD_RSFT, KC_ESCAPE)
  ),
  // Numbers + IDE
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT,
    KC_TRANSPARENT, QK_LLCK, LGUI(KC_BSLS), LGUI(LSFT(KC_E)), LGUI(LSFT(KC_H)), LCTL(KC_GRAVE),                    KC_PLUS, KC_7, KC_8, KC_9, KC_ASTR, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, LGUI(LSFT(KC_F)), LCTL(LSFT(KC_G)),                    KC_MINUS, KC_4, KC_5, KC_6, KC_DOT, KC_COLN,
    KC_TRANSPARENT, LALT(LGUI(KC_C)), LALT(LGUI(LSFT(KC_C))), LGUI(LSFT(KC_P)), LALT(KC_SPACE), LGUI(KC_DOT),                    KC_0, KC_1, KC_2, KC_3, KC_SLASH, KC_TRANSPARENT,
                                    KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Symbols
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_PERC,                    KC_CIRC, ARROW_R, FAT_ARROW, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_UNDS, KC_AMPR, KC_LABK, KC_RABK, KC_HASH,                    KC_QUES, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, KC_DQUO,
    KC_TRANSPARENT, KC_TILD, KC_GRAVE, KC_LPRN, KC_RPRN, KC_DLR,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                    KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Nav
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO, LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), LCTL(KC_MINUS), LCTL(LSFT(KC_MINUS)),                    RALT(KC_P), RALT(KC_H), RALT(KC_L), RALT(KC_N), KC_NO, KC_DELETE,
    KC_TRANSPARENT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, KC_LEFT_SHIFT, QK_LLCK,                    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,
    KC_TRANSPARENT, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(LSFT(KC_Z)),                    KC_HOME, KC_PGDN, KC_PAGE_UP, KC_END, KC_NO, KC_NO,
                                    KC_TRANSPARENT, KC_TRANSPARENT,                    KC_ENTER, KC_TRANSPARENT
  ),
  // Mouse (automouse) - unchanged from Oryx
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          DRAG_SCROLL,    TOGGLE_SCROLL,                                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          QK_LLCK,        NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,                                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // F-keys + media
  [5] = LAYOUT_voyager(
    QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(LGUI(KC_Q)),
    KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,                    KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_NO, KC_NO,
    KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,                    KC_NO, KC_LEFT_SHIFT, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_NO,
    KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, QK_LLCK,                    LGUI(LSFT(KC_4)), RM_TOGG, RM_VALD, RM_VALU, KC_NO, KC_NO,
                                    KC_NO, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_NO
  ),
};





extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {70,255,255}, {70,255,255}, {70,255,255}, {70,255,255}, {152,255,255}, {152,255,255}, {70,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {70,255,255}, {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {70,255,255}, {152,255,255}, {152,255,255}, {70,255,255}, {70,255,255}, {70,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {70,255,255}, {70,255,255} },

    [1] = { {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {70,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {41,255,255}, {234,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {70,255,255}, {70,255,255}, {70,255,255} },

    [2] = { {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {41,255,255}, {41,255,255}, {217,255,255}, {217,255,255}, {41,255,255}, {70,255,255}, {41,255,255}, {41,255,255}, {217,255,255}, {217,255,255}, {41,255,255}, {70,255,255}, {41,255,255}, {41,255,255}, {217,255,255}, {217,255,255}, {41,255,255}, {70,255,255}, {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {217,255,255}, {217,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {70,255,255}, {70,255,255}, {70,255,255} },

    [3] = { {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {0,0,0}, {133,255,193}, {124,255,137}, {124,255,137}, {133,255,193}, {70,255,255}, {0,0,0}, {133,255,193}, {133,255,193}, {133,255,193}, {133,255,193}, {206,200,170}, {133,255,193}, {133,255,193}, {133,255,193}, {133,255,193}, {0,0,0}, {70,255,255}, {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {25,255,255}, {25,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,255,255}, {206,200,170}, {70,255,255}, {70,255,255} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,101}, {0,255,101}, {0,0,0}, {0,0,0}, {0,0,0}, {37,255,255}, {37,255,255}, {37,255,255}, {70,255,255}, {70,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {217,255,255}, {217,255,255}, {217,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {70,255,255}, {70,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COLN);
        } else {
          unregister_code16(KC_COLN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case NUM_NEWLINE:
      if (record->tap.count > 0) {
        // Tap: Shift+Enter (new line in chat apps). Hold: Numbers layer.
        if (record->event.pressed) {
          register_code16(S(KC_ENTER));
        } else {
          unregister_code16(S(KC_ENTER));
        }
        return false;
      }
      break;
    case ARROW_R:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
    case FAT_ARROW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
