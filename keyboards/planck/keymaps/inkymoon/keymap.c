// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NUMPAD,
  LOWER,
  RAISE,
  BACKLIT,
  ZELDA,
  EARTH,
  SSB64,
  UNDER
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom songs
#define NUMPAD_SOUND \
    H__NOTE(_G6 ),  \
    E__NOTE(_FS6),  \
    H__NOTE(_E6 ),
    
#define EARTHBOUND_LEVEL \
    H__NOTE(_DS7),  \
    H__NOTE(_AS7),  \
    H__NOTE(_G6 ),  \
    H__NOTE(_DS7),  \
    H__NOTE(_AS7),  \
    H__NOTE(_G6 ),  \
    H__NOTE(_DS7),  \
    H__NOTE(_AS7),  \
    H__NOTE(_GS6),  \
    H__NOTE(_DS7),  \
    H__NOTE(_AS7),  \
    H__NOTE(_GS6),
    
#define DREAMLAND \
    Q__NOTE(_C7  ),	\
    Q__NOTE(_REST),	\
    Q__NOTE(_C6  ),	\
    Q__NOTE(_REST),	\
    Q__NOTE(_DS6 ),	\
    Q__NOTE(_D6  ),	\
    Q__NOTE(_C6  ),	\
    Q__NOTE(_REST),	\
    Q__NOTE(_C6  ),	\
    Q__NOTE(_D6  ),	\
    Q__NOTE(_DS6 ),	\
    Q__NOTE(_C6  ),	\
    Q__NOTE(_AS5 ),	\
    Q__NOTE(_C6  ),	\
    Q__NOTE(_G5  ),	\
    Q__NOTE(_REST),	\
    Q__NOTE(_C7  ),	\
    Q__NOTE(_REST),	\
    Q__NOTE(_G6  ),	\
    Q__NOTE(_REST),	\
    Q__NOTE(_DS6 ),	\
    Q__NOTE(_D6  ),	\
    Q__NOTE(_C6  ),	\
    E__NOTE(_C6  ),	\
    E__NOTE(_D6  ),	\
    Q__NOTE(_DS6 ),	\
    Q__NOTE(_F6  ),	\
    Q__NOTE(_D6  ),	\
    Q__NOTE(_AS5 ),	\
    Q__NOTE(_C6  ),	\
    Q__NOTE(_G5  ),	\
    Q__NOTE(_C6  ),
    
#define MEGALOVANIA \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_AS5 ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_C6  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_AS5 ),  \
    Q__NOTE(_REST),  \
    SD_NOTE(_REST),  \
    E__NOTE(_C6  ),  \
    S__NOTE(_REST),  \
    Q__NOTE(_CS6 ),  \
    E__NOTE(_REST),  \
    E__NOTE(_D6  ),  \
    H__NOTE(_F6  ),  \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_AS5 ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_C6  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_AS5 ),  \
    Q__NOTE(_REST),  \
    SD_NOTE(_REST),  \
    E__NOTE(_C6  ),  \
    S__NOTE(_REST),  \
    Q__NOTE(_CS6 ),  \
    E__NOTE(_REST),  \
    E__NOTE(_D6  ),  \
    H__NOTE(_F6  ),  \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_AS5 ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_C6  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_AS5 ),  \
    Q__NOTE(_REST),  \
    SD_NOTE(_REST),  \
    E__NOTE(_C6  ),  \
    S__NOTE(_REST),  \
    Q__NOTE(_CS6 ),  \
    E__NOTE(_REST),  \
    E__NOTE(_D6  ),  \
    H__NOTE(_F6  ),  \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_AS5 ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_C6  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_G5  ),  \
    Q__NOTE(_REST),  \
    E__NOTE(_F5  ),  \
    S__NOTE(_REST),  \
    E__NOTE(_FS5 ),  \
    Q__NOTE(_REST),  \
    SD_NOTE(_REST),  \
    H__NOTE(_G5  ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sh/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {BACKLIT, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Sh/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC       },
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT       },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
  {BACKLIT, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT       }
},

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   +  |   -  |   7  |   8  |   9  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   *  |   /  |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {_______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_P7,   KC_P8,   KC_P9,   _______},
  {_______, _______, _______, _______, _______, _______, KC_PAST, KC_PSLS, KC_P4,   KC_P5,   KC_P6,   _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |PrnSc |Insert|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL },
  {KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR, KC_INS,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Mute | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MUTE, KC_MPLY, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT}
},

/* Adjust (Lower + Raise) 
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Zelda |Earth |SSB64 |Under |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |      |Qwerty|Colemk|Numpad|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   ZELDA,   EARTH,   SSB64,   UNDER,   _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, NUMPAD,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]     = SONG(STARTUP_SOUND);
float tone_qwerty[][2]      = SONG(QWERTY_SOUND);
float tone_colemak[][2]     = SONG(COLEMAK_SOUND);
float tone_numpad[][2]      = SONG(NUMPAD_SOUND);
float music_scale[][2]      = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2]     = SONG(GOODBYE_SOUND);
float zelda_puzzle[][2]     = SONG(ZELDA_PUZZLE);
float earth_level[][2]      = SONG(EARTHBOUND_LEVEL);
float dreamland_theme[][2]  = SONG(DREAMLAND);
float megalovania_int[][2]  = SONG(MEGALOVANIA);
#endif


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_numpad, false, 0);
        #endif
        layer_invert(_NUMPAD);
      }
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        #ifdef BACKLIGHT_ENABLE
          breathing_speed_set(2);
          breathing_pulse();
        #endif
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        #ifdef BACKLIGHT_ENABLE
          breathing_speed_set(2);
          breathing_pulse();
        #endif
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case ZELDA:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(zelda_puzzle, false, 0);
        #endif
      }
      return false;
      break;
    case EARTH:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(earth_level, false, 0);
        #endif
      }
      return false;
      break;
    case SSB64:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(dreamland_theme, false, 0);
        #endif
      }
      return false;
      break;
    case UNDER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          increase_tempo(100);
          PLAY_NOTE_ARRAY(megalovania_int, false, 0);
          decrease_tempo(100);
        #endif
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
