#include QMK_KEYBOARD_H

#define _BL 0
#define _NL 1
#define _SL 2
#define _FL 3
#define _ML 4
#define _CL 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer
    [_BL] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MO(_NL),
        KC_LCTL, KC_LGUI, KC_LALT, MO(_NL), KC_BSPC, KC_SPC,  MO(_FL), MO(_CL), MO(_ML), MO(_SL)
    ),

    // number layer
    [_NL] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_GRV,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // symbol layer
    [_SL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______,
        KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // Function layer
    [_FL] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
        _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // Media layer
    [_ML] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MPLY, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
        _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    // Control layer
    [_CL] = LAYOUT(
        KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS,
        RESET,   _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
    
    // [] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    // ),
};

void matrix_scan_user(void) {
  // Layer LED indicators
  // ESC led on when in function layer, WASD cluster leds enabled when on arrow cluster
  uint32_t layer = layer_state;
  if (layer & (1 << 1)) {
      //gh60_wasd_leds_on();
  } else {
      //gh60_wasd_leds_off();
  }

  if (layer & (1 << 2)) {
      //gh60_esc_led_on();
  } else {
      //gh60_esc_led_off();
  }
};
