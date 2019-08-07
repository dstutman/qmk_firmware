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

#define ____ KC_TRNS

enum {
  _BASE = 0,
  _ENTRY = 1,
  _UP = 2
};

// Defines the keycodes used by our macros in process_record_user
enum {
    TD_CTRL_ALT = 0,
    TD_SPACE_TAB = 1,
    TD_SHIFT_ENTRY = 2,
    TD_BACKSPACE_ENTER = 3,
    TD_COMMA_BSLASH = 4,
    TD_DOT_SLASH = 5
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRL_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_LALT),
    [TD_SPACE_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_TAB),
    [TD_BACKSPACE_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_BSPACE, KC_ENTER),
    [TD_SHIFT_ENTRY] = ACTION_TAP_DANCE_DUAL_ROLE(KC_RSHIFT, _ENTRY),
    [TD_COMMA_BSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_BSLASH),
    [TD_DOT_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_SLASH)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = { \
    // Left
    { KC_Q, KC_W, KC_E, KC_R, KC_T, KC_GRAVE, KC_NO }, \
    { KC_A, KC_S, KC_D, KC_F, KC_G, KC_ESC, KC_NO }, \
    { KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TD(TD_CTRL_ALT), TD(TD_BACKSPACE_ENTER)}, \
    // Right
    { KC_NO, KC_QUOT, KC_Y, KC_U, KC_I, KC_O, KC_P }, \
    { KC_NO, KC_DELETE, KC_LBRACKET, KC_H, KC_J, KC_K, KC_L},\
    { KC_NO, KC_NO, KC_RBRACKET, KC_N, KC_M, TD(TD_COMMA_BSLASH), TD(TD_DOT_SLASH)}, \
    { TD(TD_SPACE_TAB), TD(TD_SHIFT_ENTRY), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  },
  [_ENTRY] = { \
    // Left
    { KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, ____ }, \
    { KC_1, KC_2, KC_3, KC_4, KC_5, TO(_BASE), ____ }, \
    { ____, ____, ____, ____, ____, ____, ____ }, \
    { ____, ____, ____, ____, ____, TD(TD_CTRL_ALT), KC_MINUS }, \
    // Right
    { ____, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12 }, \
    { ____, KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0 },\
    { ____, ____, ____, ____, ____, ____, ____ }, \
    { KC_EQUAL, KC_RSHIFT, ____, ____, ____, ____, ____ }, \
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
