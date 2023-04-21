/* Copyright 2020 Dennis Nguyen <u/nguyedt>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                  |                  | Knob 2: Vol Up/Dn |
        |  RGB Cycle       |    RGB Reverse   |    Press: Mute    |
        |  Decrease Brightness  |   Increase Brightness   |   Layer Up        |
     */
    [0] = LAYOUT(
       RGB_MOD, RGB_RMOD, KC_MUTE,
        RGB_VAD , RGB_VAI  , DF(1)
    ),
    /*
        |               |   Increase Brightness  |     Mute   |
        |    RGB Cycle  |   Decrease Brightness  |  Hue Cycle |
     */
    [1] = LAYOUT(
       RGB_HUD, RGB_HUI, KC_MUTE,
        RGB_SAI, RGB_SAD, DF(2)

    ),
 /*
        |               |   Increase Brightness  |     Mute   |
        |    RGB Cycle  |   Decrease Brightness  |  Hue Cycle |
     */
    [2] = LAYOUT(
       RGB_M_R, RGB_M_K, RGB_M_B,
        RGB_TOG, RGB_M_SW, DF(0)

    )


};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }

    }
    return true;
}
