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

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
  rgb_matrix_enable();
};

/* Indices of the LED arrays
* ,---------------------------------------------------.           ,--------------------------------------------------.
* |         |  28  |  27  |  26  |  25  |  24  |      |           |      |  0   |   1  |   2  |   3  |   4  |        |
* |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
* |         |  32  |  31  |  30  |  29  |      |      |           |      |  5   |   6  |   7  |   8  |   9  |        |
* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |         |  36  |  35  |  34  |  33  |      |------|           |------|  10  |  11  |  12  |  13  |  14  |        |
* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |         |  40  |  39  |  38  |  37  |      |      |           |      |  15  |  16  |  17  |  18  |  19  |        |
* `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |       |  44  |  43  |  42  |  41  |                                       |  20  |  21  |  22  |  23  |      |
*   `-----------------------------------'                                       `----------------------------------'
*/
// 255=red
// 201=purple
// 78=green
// 145=blue
// 26=yellow
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BASE] = { {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255}, {201,255,255} },
    [GAME] = { {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255}, {78,255,255} },
    [APPL] = { {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255}, {145,255,255} },
    [SYMB] = { {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255}, {26,255,255} },
    [XTRA] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,205,155}, {0,205,155}, {0,205,155}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
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
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
