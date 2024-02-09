// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


enum custom_keycodes {
  MY_KEY = SAFE_RANGE,
  MY_URL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x2(KC_MS_BTN1, LT(1,KC_MS_BTN2)),
    [1] = LAYOUT_ortho_1x2(MY_KEY, KC_TRNS),
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
