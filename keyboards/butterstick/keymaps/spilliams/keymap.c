#include QMK_KEYBOARD_H

// Do not change QMK Layer 0! This is your main keyboard.
// Make your QMK modifications to the later layers, to add 
// keys/customize on the first layer modify processQwerty():
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_butter(
    KC_GESC,   KC_TAB,   KC_L,    KC_F,    KC_F5,        KC_R,     KC_E,    KC_F11,  KC_UP,   KC_F12,
    KC_LSHIFT, KC_LCTRL, KC_LALT, KC_LGUI, KC_SPACE,     KC_ENTER, OSL(1),  KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [1] = LAYOUT_butter(
    KC_F1,     KC_F2,    KC_F3,   KC_F4,   KC_F9,        KC_F6,    KC_F7,   KC_F8,   KC_PGUP, KC_F10,
    KC_MPRV,   KC_MPLY,  KC_MNXT, KC_MUTE, KC_VOLD,      KC_VOLU,  KC_TRNS, KC_HOME, KC_PGDN, KC_END
  )
};

// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
