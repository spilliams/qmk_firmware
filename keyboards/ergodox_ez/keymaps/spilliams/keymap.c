#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    GAME, // for the lulz
    APPL, // swap the meta
    // STEN, // gotta type fast
    SYMB, // all the squiggly ones
    XTRA, // computer control
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * | Esc    |   1  |   2  |   3  |   4  |   5  |      |           |   -  |   6  |   7  |   8  |   9  |   0  |   =    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Grave  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
    * |--------+------+------+------+------+------|      |           | GAME |------+------+------+------+------+--------|
    * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           | APPL |   N  |   M  |   ,  |   .  |   /  | RShift |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | LCtrl|(SYMB)|      | LGui | LAlt |                                       | Left | Down |  Up  | Right|(XTRA)|
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        | LAlt | LGui |       | Alt  |Ctrl/Esc|
    *                                 ,------|------|------|       |------+--------+------.
    *                                 |Back- |      | Home |       | PgUp |        |      |
    *                                 | space| Del  |------|       |------| Enter  |Space |
    *                                 |      |      | End  |       | PgDn |        |      |
    *                                 `--------------------'       `----------------------'
    */
    [BASE] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_1,     KC_2,  KC_3,    KC_4,    KC_5,    KC_NO,     KC_MINS,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_EQL,
    KC_GRV,  KC_Q,     KC_W,  KC_E,    KC_R,    KC_T,    KC_NO,     TG(GAME), KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_BSLS,
    KC_TAB,  KC_A,     KC_S,  KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,     KC_X,  KC_C,    KC_V,    KC_B,    KC_NO,     TG(APPL), KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
    KC_LCTL, MO(SYMB), KC_NO, KC_LGUI, KC_LALT,                                        KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, MO(XTRA),
                                             KC_LALT,  KC_LGUI,     KC_LALT,  CTL_T(KC_ESC),
                                                       KC_HOME,     KC_PGUP,
                                     KC_BSPC, KC_DEL,   KC_END,     KC_PGDN, KC_ENT, KC_SPC
    ),
    /* Gaming Layer (blank keys are transparent to lower layers)
    *
    * ,---------------------------------------------------.           ,--------------------------------------------------.
    * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
    * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
    * |---------+------+------+------+------+------|  I   |           | Exit |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |  M   |           |      |      |      |      |      |      |        |
    * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |       |      |      | LAlt | Space|                                       |      |      |      |      |      |
    *   `-----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 | Space| Down |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    [GAME] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_I,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_CIRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_M,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_SPC,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                          KC_TRNS,     KC_TRNS,
                                        KC_SPC, KC_DOWN,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* Apple Layer (blank keys are transparent to lower layers)
    *
    * ,---------------------------------------------------.           ,--------------------------------------------------.
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |      |      |      |      |      |      |           | Exit |      |      |      |      |      |        |
    * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |       |      |      | LAlt | LGui |                                       |      |      |      |      |      |
    *   `-----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    [APPL] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_CIRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_LGUI,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                          KC_TRNS,     KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* Symbol Layer
    *
    * ,---------------------------------------------------.           ,--------------------------------------------------.
    * |   Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
    * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
    * |         |   !  |   @  |   {  |   }  |   |  |      |           |      | num7 | num8 | num9 | num/ | numLk|   F12  |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| num4 | num5 | num6 | num* | num, | numEnt |
    * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      | num1 | num2 | num3 | num- | num= | numEnt |
    * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |       | Exit |      |      |      |                                       | num0 | num. | num+ | num= |      |
    *   `-----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    [SYMB] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_P7, KC_P8, KC_P9,   KC_PSLS, KC_NLCK, KC_F12,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_P4, KC_P5, KC_P6,   KC_PAST, KC_PCMM, KC_PENT,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_P1, KC_P2, KC_P3,   KC_PMNS, KC_PEQL, KC_PENT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_P0, KC_PDOT, KC_PPLS, KC_PEQL, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                          KC_TRNS,     KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* Extra stuff. Media, computer control, etc
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * | Version|      |      |      |      |      |      |           |      |      |      |      |      |      |  Sleep |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Reset  |      |      |      |      |      |      |           |      |      |      | Mute | Play |      | Wake   |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |      |      |                                       | Prev | VolDn| VolUp| Next | Exit |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      | www  | www  |
    *                                 |      |      |------|       |------| Back |  Fwd |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    [XTRA] = LAYOUT_ergodox_pretty(
    VRSN,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_MPLY, KC_TRNS, KC_WAKE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                          KC_TRNS,     KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_WBAK, KC_WFWD
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
