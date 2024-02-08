// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


const uint16_t PROGMEM both_combo[] = {KC_MS_BTN1, KC_MS_BTN2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(both_combo, C(KC_V))
};


enum {
    TD_MY_COPY,
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_MY_COPY] = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_V)),
};


enum custom_keycodes {
  MY_KEY = SAFE_RANGE,
  MY_URL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // LAYOUT_ortho_1x2(KC_GRV, MY_KEY)
  // LAYOUT_ortho_1x2(KC_MS_BTN2, MY_KEY)
    // [0] = LAYOUT_ortho_1x2(KC_MS_BTN1, KC_LALT),
    [0] = LAYOUT_ortho_1x2(KC_MS_BTN1, LT(1,KC_MS_BTN2)),
    [1] = LAYOUT_ortho_1x2(TD_MY_COPY, KC_TRNS),
    [2] = LAYOUT_ortho_1x2(KC_TRNS, KC_TRNS)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MY_KEY:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("QMK is the best thing ever!");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case MY_URL:
        if (record->event.pressed) {
            SEND_STRING("http://poorbaba.ca");
        } else { // RELEASE
        }
    }
    return true;
};
