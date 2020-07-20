#include "njdoyle.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	NJDOYLE_LAYOUT_BASE,

	// LOWER - Mostly numbers and their shifted symbol counterparts
	[_LOWER] = LAYOUT_kc(
		____, EXLM, AT  , HASH, DLR , PERC, CIRC, AMPR, ASTR, BSLS, PIPE, ____,
		____, 1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 0   , ____,
		LALT, PLUS, MINS, ASTR, SLSH, UNDS, COLN, EQL , COMM, DOT , SLSH, DEL ,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
	),

	// RAISE - Mostly paired enclosures and common programming symbols
	[_RAISE] = LAYOUT_kc(
		____, XXXX, EXLM, ASTR, PLUS, XXXX, XXXX, MINS, EQL , UNDS, XXXX, ____,
		____, LBRC, RBRC, LCBR, RCBR, DLR , HASH, LPRN, RPRN, LT  , GT  , ____,
		LALT, XXXX, XXXX, GRV , QUOT, XXXX, XXXX, DQUO, TILD, XXXX, XXXX, DEL ,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
	),

	// NAVIGATION
	[_NAVIGATION] = LAYOUT_planck_grid(
		_______, XXXXXXX, XXXXXXX, DE_LEFT, DE_RGHT, KC_HOME, XXXXXXX, TB_LEFT, TB_RGHT, TB_NEW , KC_PGUP, _______,
		_______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_END , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, _______,
		KC_CAPS, DE_MENU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BR_BACK, BR_FRWD, XXXXXXX, BR_TOOL, KC_CAPS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	),

	// FUNCTION - F keys, media controls, default layout selection
	[_FUNCTION] = LAYOUT_planck_grid(
		KC_LGUI, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX, D_QWRTY, D_DVRAK, D_COLEM, D_C_DH , D_C_DHM, D_WORKM,
		KC_LCTL, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_LSFT, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, E_SHRUG, E_TFLIP, E_DERP , E_DAPRV, E_SMILE, XXXXXXX,
		_______, _______, _______, _______, _______, KC_MPLY, KC_MUTE, _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _LOWER, _RAISE, _NAVIGATION);
}

