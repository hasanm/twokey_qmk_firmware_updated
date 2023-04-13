// Copyright 2020 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_MY_KEY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // LAYOUT_ortho_1x2(KC_GRV, MY_KEY)
  // LAYOUT_ortho_1x2(KC_MS_BTN2, MY_KEY)
  LAYOUT_ortho_1x2(KC_MS_BTN1, KC_MS_BTN2)
};



bool process_record_user (uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
  case KC_MY_KEY:
      if (record->event.pressed) {
          SEND_STRING("Test String");
      }
      return false;
  }
  return true; 
}
