#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};



#define DUAL_FUNC_0 LT(5, KC_F9)
#define DUAL_FUNC_1 LT(3, KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F24,                                         LGUI(LCTL(LSFT(KC_4))),KC_NO,          KC_NO,          KC_NO,          KC_NO,          RGUI(RCTL(KC_Q)),
    CW_TOGG,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    OSM(MOD_LSFT),  MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),KC_F,           KC_G,                                           KC_H,           KC_J,           MT(MOD_RGUI, KC_K),MT(MOD_RALT, KC_L),DUAL_FUNC_1,    KC_QUOTE,       
    KC_BSPC,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SCLN,        KC_EQUAL,       
                                                    LT(2, KC_SPACE),DUAL_FUNC_0,                                    LT(1, KC_TAB),  MT(MOD_RSFT, KC_ESCAPE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          LGUI(KC_BSLS),  LGUI(LSFT(KC_E)),KC_NO,          LCTL(KC_GRAVE),                                 KC_PLUS,        KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_NO,          LCTL(LSFT(KC_G)),                                KC_MINUS,       KC_4,           KC_5,           KC_6,           KC_SLASH,       KC_COLN,        
    KC_TRANSPARENT, LGUI(KC_DOT),   LALT(LGUI(KC_C)),LALT(LGUI(LSFT(KC_C))),KC_NO,          KC_NO,                                          KC_0,           KC_1,           KC_2,           KC_3,           KC_DOT,         KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LBRC,        KC_RBRC,        KC_PERC,                                        KC_CIRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_AMPR,        KC_LABK,        KC_RABK,        KC_HASH,                                        KC_QUES,        KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_BSLS,        KC_DQUO,        
    KC_TRANSPARENT, KC_TILD,        KC_GRAVE,       KC_LPRN,        KC_RPRN,        KC_DLR,                                         ST_MACRO_0,     ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ENTER,       KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          LGUI(LSFT(KC_LBRC)),LGUI(LSFT(KC_RBRC)),LCTL(KC_MINUS), LCTL(LSFT(KC_MINUS)),                                RALT(KC_P),     RALT(KC_H),     RALT(KC_L),     RALT(KC_N),     KC_NO,          KC_DELETE,      
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_NO,          KC_NO,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_NO,                                          KC_F5,          KC_F10,         KC_F11,         LSFT(KC_F11),   LGUI(LSFT(KC_F5)),LSFT(KC_F5),    
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ENTER,       KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    QK_BOOT,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_LLCK,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_NO,          KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_NO,                                          KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_NO,          KC_NO,          
    KC_NO,          KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_NO,                                          KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_NO,          
    KC_NO,          KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_NO,                                          LGUI(LSFT(KC_4)),RGB_TOG,        RGB_VAD,        RGB_VAI,        KC_NO,          KC_NO,          
                                                    KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO
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
    [0] = { {0,0,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,102}, {86,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,102}, {86,255,102}, {86,255,102}, {86,255,102}, {0,0,0}, {0,0,0}, {0,0,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {215,255,255}, {129,255,255}, {172,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,102}, {0,0,0}, {0,0,0}, {86,255,102}, {86,255,102}, {86,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {21,255,255}, {86,255,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,102}, {0,0,0}, {0,0,0}, {172,255,102}, {172,255,102}, {0,0,0}, {172,255,102}, {0,0,0}, {86,255,102}, {86,255,102}, {86,255,102}, {0,0,0}, {172,255,102}, {0,0,0}, {172,255,102}, {172,255,102}, {172,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {21,255,102}, {21,255,255}, {21,255,255}, {21,255,255}, {21,255,102}, {0,0,0}, {21,255,102}, {21,255,255}, {21,255,255}, {21,255,255}, {21,255,102}, {21,255,102}, {21,255,255}, {21,255,255}, {21,255,255}, {21,255,255}, {21,255,102}, {0,0,0}, {21,255,255}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,102}, {0,0,0}, {215,255,102}, {215,255,102}, {215,255,255}, {215,255,255}, {215,255,102}, {0,0,0}, {215,255,102}, {215,255,102}, {215,255,255}, {215,255,255}, {215,255,102}, {0,0,0}, {215,255,102}, {215,255,102}, {215,255,255}, {215,255,255}, {215,255,102}, {215,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {215,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {215,255,102}, {215,255,255}, {215,255,255}, {215,255,102}, {215,255,102}, {215,255,102}, {215,255,255}, {215,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,102}, {0,0,0}, {0,0,0}, {172,255,102}, {172,255,102}, {172,255,102}, {172,255,102}, {0,0,0}, {86,255,102}, {86,255,102}, {86,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,102}, {129,255,102}, {129,255,102}, {129,255,102}, {0,0,0}, {0,0,0}, {129,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,102}, {172,255,102}, {172,255,102}, {172,255,102}, {0,0,0}, {0,0,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,0,0}, {0,0,0}, {215,255,102}, {215,255,102}, {215,255,102}, {215,255,102}, {215,255,102}, {215,255,102}, {0,0,255}, {0,0,0} },

    [4] = { {0,0,102}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {129,255,102}, {0,0,0}, {21,255,255}, {21,255,255}, {21,255,255}, {21,255,255}, {0,0,0}, {0,0,0}, {21,255,255}, {21,255,255}, {21,255,255}, {21,255,255}, {0,0,0}, {0,0,0}, {21,255,255}, {21,255,255}, {21,255,255}, {21,255,255}, {0,0,0}, {0,0,0}, {21,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,102}, {172,255,102}, {172,255,102}, {172,255,102}, {172,255,102}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,102}, {86,255,102}, {86,255,102}, {86,255,102}, {0,0,0}, {172,255,102}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,0}, {0,0,0}, {21,255,255}, {0,0,0} },

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
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS)SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT)));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL)SS_DELAY(100)  SS_LSFT(SS_TAP(X_DOT)));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LSFT(KC_ENTER));
        } else {
          unregister_code16(LSFT(KC_ENTER));
        }
      } else {
        if (record->event.pressed) {
          layer_on(3);
        } else {
          if (!is_layer_locked(3)) {
          layer_off(3);
          }
        }  
      }  
      return false;
    case DUAL_FUNC_1:
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
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
