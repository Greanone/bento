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
    /*.  
        |                  |                  | Knob 2: Vol Up/Dn |
        |  RGB Cycle       |    RGB Reverse   |    Press: Mute    |
        |  Decrease Brightness  |   Increase Brightness   |   Layer Up        |
     */
    [0] = LAYOUT(
        RGB_MOD, RGB_RMOD, KC_MUTE,
        RGB_VAD , RGB_VAI  , DF(1)
    ),
    /*
        |  Hue down  |  Hue up  |     Mute   |
        |    Sat Increase  |   Sat Decrease   |  Layer Up  |
     */
    [1] = LAYOUT(
        RGB_HUD, RGB_HUI, KC_MUTE,
        RGB_SAI, RGB_SAD, DF(2)
    ),
 /* 
        |            |             | Knob 2: Attempt at Zoom In/Out |
        |  Rainbow   |  Breathing  |     RGB Cycle   |
        |    RGB on/off  |   Knight Rider  |  Layer Up  |
     */
    [2] = LAYOUT(
        RGB_M_R, RGB_M_B, RGB_MOD,
        RGB_TOG, RGB_M_K, DF(3)
    ),
 /*
       |            |          | Knob 2: Braces for Brush Size |
        |  Left Brace  |  Right Brace  |     Mute   |
        |    RGB Cycle  |   Decrease Brightness  |  Reset Layer  |
     */
    [3] = LAYOUT(
        KC_LBRC, KC_RBRC, KC_MUTE,
        RGB_SAI, RGB_SAD, DF(0)
    ),

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    else if (index == 2) {
        if (clockwise) {
            tap_code(KC_LGUI | KC_EQL);
        } else {
            tap_code(KC_LGUI | KC_MINS);
        }
    }else if (index == 3) {
        if (clockwise) {
            tap_code(KC_LBRC);
        } else {
            tap_code(KC_RBRC);
        }
    }
}
