#include "njdoyle.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// OS BASE - The base mod layouts for each OS
	[_MAC] = LAYOUT_planck_grid(
		LGUI_T(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC      , \
		LCTL_T(KC_ESC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI      , \
		OSM(MOD_LSFT) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_RSFT), \
		L_FUNC        , KC_LCTL, KC_LGUI, KC_LALT, L_LOWER, KC_SPC , KC_ENT , L_RAISE, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT        \
	),
	[_LINUX] = LAYOUT_planck_grid(
		LCTL_T(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC      , \
		LGUI_T(KC_ESC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL      , \
		OSM(MOD_LSFT) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_RSFT), \
		L_FUNC        , KC_LCTL, KC_LGUI, KC_LALT, L_LOWER, KC_SPC , KC_ENT , L_RAISE, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT        \
	),

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
	[_NAVIGATION_M] = LAYOUT_planck_grid(
		_______, XXXXXXX, XXXXXXX, DM_LEFT, DM_RGHT, KC_HOME, XXXXXXX, TM_LEFT, TM_RGHT, TM_NEW , KC_PGUP, _______,
		_______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_END , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, _______,
		KC_CAPS, DM_MENU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BM_BACK, BM_FRWD, XXXXXXX, BM_TOOL, KC_CAPS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	),
	[_NAVIGATION_L] = LAYOUT_planck_grid(
		_______, XXXXXXX, XXXXXXX, DL_LEFT, DL_RGHT, KC_HOME, XXXXXXX, TL_LEFT, TL_RGHT, TL_NEW , KC_PGUP, _______,
		_______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_END , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, _______,
		KC_CAPS, KC_MENU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_BACK, BL_FRWD, XXXXXXX, XXXXXXX, KC_CAPS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	),

	// FUNCTION - F keys, media controls, default layout selection
	[_FUNCTION] = LAYOUT_planck_grid(
		KC_LGUI, KC_F1  , KC_F2  , KC_F3  , KC_F4  , L_LINUX, D_QWRTY, D_DVRAK, D_COLEM, D_C_DH , D_C_DHK, D_WORKM,
		KC_LCTL, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_LSFT, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, NJM_1  , NJM_2  , NJM_3  , NJM_4  , NJM_5  , XXXXXXX,
		_______, _______, _______, _______, _______, KC_MPLY, KC_MUTE, _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
	if (layer_state & 1UL << _LINUX)
		return update_tri_layer_state(state, _LOWER, _RAISE, _NAVIGATION_L);
	return update_tri_layer_state(state, _LOWER, _RAISE, _NAVIGATION_M);
}

