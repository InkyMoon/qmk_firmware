#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _COLEMAK,
  _FUNC
};

enum codes {
  SD_LTOG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_INS, KC_GESC,    KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  XXXXXX,  KC_BSPC, \
 KC_PGUP,  KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS, \
 KC_PGDN, KC_CAPS,    KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,           KC_ENT, \
          KC_LSFT,    KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_RGUI, \
          KC_LCTL,          KC_LAPO,       KC_BSPC,        MO(1),          KC_SPC,         KC_RAPC,                           KC_RCTRL \
   ),
[_COLEMAK] = LAYOUT(
  KC_INS, KC_GESC,    KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  XXXXXX,  KC_BSPC, \
 KC_PGUP,  KC_TAB,    KC_Q,    KC_W,    KC_F,   KC_P,     KC_G,    KC_J,    KC_L,    KC_U,    KC_I, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, \
 KC_PGDN, KC_CAPS,    KC_A,    KC_R,    KC_S,   KC_T,     KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,           KC_ENT, \
          KC_LSFT,    KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_RGUI, \
          KC_LCTL,          KC_LAPO,       KC_BSPC,        MO(1),          KC_SPC,         KC_RAPC,                           KC_RCTRL \
   ),
[_FUNC] = LAYOUT(
 RGB_TOG, VLK_TOG,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, RESET, \
 RGB_MOD, SD_LTOG, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
RGB_RMOD, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, \
          KC_LSFT, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
          _______,          KC_LALT, _______, _______,          _______,                   KC_RALT,                            _______ \
   )
};

#ifdef USE_LEDS_FOR_LAYERS
// example of how to use LEDs as layer indicators
static uint8_t top = 1;
static uint8_t middle = 0;
static uint8_t bottom = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
    top = middle = bottom = 0;
    switch (get_highest_layer(state)) {
    case _BASE:
        top = 1;
        break;
    case _FUNC:
        middle = 1;
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}

// override kb level function
bool led_update_user(led_t usb_led) {
    writePin(B1, !top);
    writePin(B2, !middle);
    writePin(B3, !bottom);
    return false; // we are using LEDs for something else override kb
}
#endif

static uint8_t layer = _QWERTY

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SD_QWRT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case SD_CLMK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case SD_DVRK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
