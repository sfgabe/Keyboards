#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOUS 2 // mouse keys
#define MDIA 3 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_ergodox_pretty_80(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC, KC_BSLS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(1), TG(2), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, OSL(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_TAB, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_LCTL, KC_LALT, KC_LGUI, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_RCTL, LGUI(KC_C), LGUI(KC_V), KC_LBRC, KC_RBRC, KC_BRIU, KC_BRID, OSM(MOD_HYPR), KC_PGUP, KC_VOLD, KC_VOLU, KC_SPC, KC_TAB, OSM(MOD_MEH), KC_PGDN, KC_BSPC, KC_ENT),
	[SYMB] = LAYOUT_ergodox_pretty_80(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PEQL, KC_TRNS, BL_INC, BL_DEC, BL_ON, BL_OFF, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_RMOD, RGB_VAI, RGB_VAD, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PAST, KC_TRNS, KC_TRNS, RGB_M_B, RGB_M_R, RGB_M_T, NK_TOGG, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_PENT, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[MOUS] = LAYOUT_ergodox_pretty_80(KC_TRNS, KC_F13, KC_F16, KC_F17, KC_F18, KC_F19, KC_NO, KC_NO, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN2, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_MS_L, KC_MS_U, KC_MS_R, KC_WH_R, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, TG(3), KC_NO, KC_NO, KC_MS_D, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[MDIA] = LAYOUT_ergodox_pretty_80(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_WHOM, KC_WBAK, KC_WFWD, KC_WSCH, KC_WREF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_MFFD, KC_MRWD, KC_MPLY, KC_MSTP, KC_MUTE, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
		  ergodox_right_led_2_off();
		  ergodox_right_led_3_off();
      break;
    case MOUS:
      ergodox_right_led_2_on();
		  ergodox_right_led_1_off();
		  ergodox_right_led_3_off();
      break;
    case MDIA:
      ergodox_right_led_3_on();
		  ergodox_right_led_1_off();
		  ergodox_right_led_2_off();
      break;
    default:
      // none
      break;
  }

};
