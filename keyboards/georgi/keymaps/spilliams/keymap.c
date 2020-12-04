/*
 * Good on you for modifying your layout, this is the most nonQMK layout you will come across
 * There are three modes, Steno (the default), QWERTY (Toggleable) and a Momentary symbol layer
 *
 * Don't modify the steno layer directly, instead add chords using the keycodes and macros
 * from sten.h to the layout you want to modify.
 *
 * Observe the comment above processQWERTY!
 *
 * http://docs.gboards.ca
 */

#include QMK_KEYBOARD_H
#include "sten.h"
#include "keymap_steno.h"
#define IGNORE_MOD_TAP_INTERRUPT

// Proper Layers
#define FUNCT   (LSD | LK | LP | LH)
#define MEDIA   (LSD | LK | LW | LR)
#define MOVE    (ST1 | ST2)

/* Keyboard Layout
 * ,---------------------------------.    ,------------------------------.
 * | FN  | LSU | LFT | LP | LH | ST1 |    | ST3 | RF | RP | RL | RT | RD |
 * |-----+-----+-----+----+----|-----|    |-----|----+----+----+----+----|
 * | PWR | LSD | LK  | LW | LR | ST2 |    | ST4 | RR | BB | RG | RS | RZ |
 * `---------------------------------'    `------------------------------'
 *                   ,---------------,    .---------------.
 *                   | LNO | LA | LO |    | RE | RU | RNO |
 *                   `---------------'    `---------------'
 */

// Note: You can only use basic keycodes here!
// P() is just a wrapper to make your life easier.
//
// http://docs.gboards.ca
uint32_t processQwerty(bool lookup) {
    SEND_STRING("v4.0.1 spilliams ");
    SEND_STRING(__DATE__);
    return 0;
}

// "Layers"
// Steno layer should be first in your map.
// When PWR | FN | ST3 | ST4 is pressed, the
// If you need more space for chords, remove the two gaming layers.
// Note: If using NO_ACTION_TAPPING, LT will not work!

// "Layers", cont'd (by spilliams)
// I modified this to take the leftmost two keys away from STN_FN and STN_PWR,
// so I could have real qmk layers again.

// QMK Layers
#define L0 0
#define L1 1
#define L2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Main layer, everything goes through here
    [L0] = LAYOUT_georgi(
    KC_ESC,  STN_S1,  STN_TL,   STN_PL,   STN_HL,   STN_ST1,     STN_ST3,  STN_FR,  STN_PR,   STN_LR,  STN_TR,   STN_DR,
    OSL(L1), STN_S2,  STN_KL,   STN_WL,   STN_RL,   STN_ST2,     STN_ST4,  STN_RR,  STN_BR,   STN_GR,  STN_SR,   STN_ZR,
                                STN_N1,   STN_A,    STN_O,       STN_E,    STN_U,   STN_N7
    ),
    [L1] = LAYOUT_georgi(
    TO(L0),  KC_1,    KC_2,     KC_3,     KC_4,     KC_5,        KC_NO,    KC_6,    KC_7,     KC_8,    KC_9,     KC_0,
    KC_TRNS, KC_TAB,  KC_GRV,   KC_ESC,   KC_NO,    KC_NO,       KC_MINS,  KC_PLUS, KC_COMM,  KC_DOT,  KC_SLSH,  KC_BSLS,
                                KC_LSFT,  KC_LCTL,  KC_LALT,     KC_LGUI,  KC_NO,   OSL(L2)
    ),
    [L2] = LAYOUT_georgi(
    KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,       KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,   KC_F12,
    KC_NO,   KC_MPRV, KC_MPLY,  KC_MNXT,  KC_VOLD,  KC_VOLU,     KC_MUTE,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_SYSTEM_SLEEP,
                                KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS
    )
};
// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
