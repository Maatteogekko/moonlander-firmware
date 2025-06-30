#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  MAC_LOCK,
};

// --- custom starts here ---
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t repeat_key_override = ko_make_basic(MOD_MASK_SHIFT, QK_REPEAT_KEY, QK_ALT_REPEAT_KEY);

const key_override_t *key_overrides[] = {
	&delete_key_override,
	&repeat_key_override
};
// --- custom ends here ---

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};

#define DUAL_FUNC_0 LT(5, KC_8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    TG(5),          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           LALT(LGUI(KC_SPACE)),                                LGUI(KC_SPACE), KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_INSERT,      
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_HYPR,                                        KC_HYPR,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_TRANSPARENT, 
    TT(2),          MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_S),MT(MOD_LCTL, KC_T),KC_G,           TD(DANCE_0),                                                                    MEH_T(KC_DELETE),KC_M,           MT(MOD_RCTL, KC_N),MT(MOD_RSFT, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RGUI, KC_O),TT(1),          
    KC_CAPS,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_QUOTE,       CW_TOGG,        
    LGUI(LCTL(KC_SPACE)),KC_SLASH,       KC_BSLS,        KC_GRAVE,       KC_BSPC,        KC_TRANSPARENT,                                                                                                 OSL(4),         KC_MINUS,       KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, 
    TD(DANCE_1),    KC_LEFT_SHIFT,  OSL(1),                         DUAL_FUNC_0,    KC_ESCAPE,      KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_LABK,        KC_RABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TILD,        KC_SLASH,       KC_ASTR,        KC_MINUS,       KC_PERC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_CIRC,        KC_PIPE,        KC_EXLM,        KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_HASH,        KC_AMPR,        KC_QUES,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_COMMA,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_AT,          KC_DLR,         KC_LBRC,        KC_RBRC,                                        KC_DOT,         KC_1,           KC_2,           KC_3,           LALT(LSFT(KC_RBRC)),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SLASH,       KC_BSLS,        KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_0,           ST_MACRO_0,     LALT(KC_LBRC),  LALT(LSFT(KC_LBRC)),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 MAC_LOCK,       RGB_SLD,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        
    KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        KC_NO,          KC_NO,          QK_DYNAMIC_TAPPING_TERM_UP,KC_TRANSPARENT,                                 KC_TRANSPARENT, RGB_MODE_FORWARD,RGB_TOG,        RGB_VAD,        RGB_VAI,        KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_SPD,        RGB_SPI,        KC_NO,          KC_NO,          QK_DYNAMIC_TAPPING_TERM_DOWN,KC_TRANSPARENT,                                                                 KC_TRANSPARENT, TOGGLE_LAYER_COLOR,KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_HUD,        RGB_HUI,        KC_NO,          KC_NO,          QK_DYNAMIC_TAPPING_TERM_PRINT,                                KC_NO,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          MU_NEXT,        MU_TOGG,        AU_TOGG,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_LEFT,  KC_NO,          KC_TRANSPARENT,                                 KC_HOME,        KC_PAGE_UP,     KC_H,           KC_J,           KC_K,           KC_L,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_LEFT),  KC_TRANSPARENT,                                                                 KC_END,         KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    LGUI(KC_RIGHT),                                 KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_SPACE,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MS_BTN4,     KC_MS_BTN5,     KC_MS_BTN6,     KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, TD(DANCE_2),    KC_MS_BTN1
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_F,           KC_E,           KC_R,           KC_T,           KC_H,                                           KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_W,           KC_D,           KC_G,           KC_B,                                                                           KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_BSLS,        KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_ESCAPE,                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_LEFT_SHIFT,  KC_LEFT_CTRL,                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_QUOTE,       KC_LCBR,        KC_RCBR,        KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PLUS,        KC_MINUS,       KC_LABK,        KC_RABK,        KC_HASH,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_QUES,        KC_DQUO,        KC_LPRN,        KC_RPRN,        KC_SLASH,       KC_BSLS,                                                                        KC_AT,          KC_COLN,        KC_SCLN,        KC_COMMA,       KC_DOT,         KC_EQUAL,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AMPR,        KC_LBRC,        KC_RBRC,        KC_PIPE,                                        KC_PERC,        KC_UNDS,        KC_DLR,         KC_CIRC,        KC_ASTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
                 'L', 'L', 'L', 'R', 'R', 'R'
);



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {138,243,204}, {0,0,0}, {207,220,206}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,253,206}, {0,0,0}, {206,219,204}, {91,253,206}, {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {207,220,206}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,253,206}, {91,253,206}, {0,0,0}, {7,255,207}, {0,0,0}, {7,250,163} },

    [1] = { {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,250,121}, {0,251,136}, {0,0,253}, {0,0,0}, {0,0,0}, {45,251,141}, {45,251,141}, {69,117,187}, {0,0,0}, {170,251,132}, {170,251,132}, {170,251,132}, {170,251,132}, {0,0,0}, {170,251,132}, {170,251,132}, {170,251,132}, {170,251,132}, {0,0,0}, {0,0,0}, {0,0,0}, {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,255,255}, {25,255,255}, {25,255,255}, {0,0,0}, {0,0,0}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {0,0,0}, {25,255,255}, {25,255,255}, {25,255,255}, {25,255,255}, {0,0,38}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,242,190}, {35,242,190}, {35,242,190}, {0,0,0}, {0,0,0}, {35,242,190}, {35,242,190}, {35,242,190}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {95,251,134}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,65,204}, {0,0,0}, {20,255,255}, {20,170,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,242,190}, {35,251,248}, {139,65,204}, {95,251,134}, {0,0,0}, {35,242,190}, {35,251,248}, {139,65,204}, {95,251,134}, {0,0,0}, {35,242,190}, {0,0,0}, {139,65,204}, {95,251,134}, {35,242,190}, {35,242,190}, {35,242,190}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,204}, {0,0,0}, {0,0,0}, {172,212,248}, {0,0,0}, {0,0,204}, {0,0,0}, {0,0,0}, {172,212,248}, {0,0,0}, {0,0,204}, {0,0,0}, {0,0,0}, {172,212,248}, {0,0,0}, {0,0,204}, {0,0,0}, {0,0,0}, {172,212,248}, {219,146,248}, {0,0,204}, {138,243,204}, {138,243,204}, {138,243,204}, {0,0,204}, {0,0,0}, {0,0,0}, {206,219,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,204}, {0,0,0}, {172,212,248}, {0,0,0}, {250,229,206}, {0,0,204}, {0,0,0}, {172,212,248}, {113,255,255}, {250,229,206}, {0,0,204}, {0,0,0}, {172,212,248}, {113,205,255}, {250,229,206}, {0,0,204}, {0,0,0}, {172,212,248}, {113,129,255}, {250,229,206}, {0,0,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,204}, {0,0,0}, {0,0,0}, {250,229,206}, {250,229,206}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,38}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {37,255,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
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
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_0)SS_DELAY(100)  SS_TAP(X_0));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE))SS_DELAY(100)  SS_TAP(X_K)SS_DELAY(100)  SS_TAP(X_I)SS_DELAY(100)  SS_TAP(X_T)SS_DELAY(100)  SS_TAP(X_T)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case MAC_LOCK:
      HCS(0x19E);

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DELETE);
        } else {
          unregister_code16(KC_DELETE);
        }  
      }  
      return false;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[3];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_GRAVE));
        tap_code16(LALT(KC_GRAVE));
        tap_code16(LALT(KC_GRAVE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_GRAVE));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LALT(KC_GRAVE)); break;
        case DOUBLE_TAP: register_code16(LALT(KC_E)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_GRAVE)); register_code16(LALT(KC_GRAVE));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_GRAVE)); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_E)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_GRAVE)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: layer_on(3); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_HOLD: layer_on(1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD:
          layer_off(3);
        break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
              case DOUBLE_HOLD: 
                layer_off(1);
                break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
    }
    if(state->count > 3) {
        tap_code16(KC_MS_BTN2);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: register_code16(KC_MS_BTN3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN2); register_code16(KC_MS_BTN2);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: unregister_code16(KC_MS_BTN3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
