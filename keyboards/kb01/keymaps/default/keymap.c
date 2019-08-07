/* Copyright 2019 Daniel Stutman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum kb01_layers {
  _QWERTY = 0
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = { \
    { KC_Q, KC_W, KC_E, KC_R, KC_T, KC_GRAVE, KC_NO}, \
    { KC_A, KC_S, KC_D, KC_F, KC_G, KC_ESC, KC_NO}, \
    { KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_BSPACE}, \
    { KC_NO, KC_QUOT, KC_Y, KC_U, KC_I, KC_O, KC_P }, \
    { KC_NO, KC_DELETE, KC_LBRACKET, KC_H, KC_J, KC_K, KC_L},\
    { KC_NO, KC_NO, KC_RBRACKET, KC_N, KC_M, KC_COMMA, KC_DOT}, \
    { KC_SPACE, KC_LSHIFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
