#include "njdoyle.h"

/* MACRO FOR DEFAULT LAYERS */
#define \
	NJD_BASE_LAYOUT_DEFAULT( \
		K_0_0, K_0_1, K_0_2, K_0_3, K_0_4, K_0_5, K_0_6, K_0_7, K_0_8, K_0_9, \
		K_1_0, K_1_1, K_1_2, K_1_3, K_1_4, K_1_5, K_1_6, K_1_7, K_1_8, K_1_9, \
		K_2_0, K_2_1, K_2_2, K_2_3, K_2_4, K_2_5, K_2_6, K_2_7, K_2_8, K_2_9  \
	) \
	NJD_BASE_LAYOUT( \
		KC_##K_0_0, KC_##K_0_1, KC_##K_0_2, KC_##K_0_3, KC_##K_0_4, KC_##K_0_5, KC_##K_0_6, KC_##K_0_7, KC_##K_0_8, KC_##K_0_9, \
		KC_##K_1_0, KC_##K_1_1, KC_##K_1_2, KC_##K_1_3, KC_##K_1_4, KC_##K_1_5, KC_##K_1_6, KC_##K_1_7, KC_##K_1_8, KC_##K_1_9, \
		KC_##K_2_0, KC_##K_2_1, KC_##K_2_2, KC_##K_2_3, KC_##K_2_4, KC_##K_2_5, KC_##K_2_6, KC_##K_2_7, KC_##K_2_8, KC_##K_2_9, \
		LGUI_T(KC_TAB), KC_BSPACE    , \
		LCTL_T(KC_ESC), KC_RGUI      , \
		OSM(MOD_LSFT) , OSM(MOD_RSFT), \
		KC_SPACE      , KC_ENTER     , \
		L_LOWER       , L_RAISE      , \
		KC_LALT       , L_FUNC         \
	)

/* MACROS FOR LAYER LAYRES */
#ifndef NJD_LAYER_LAYOUT
#	define \
		NJD_LAYER_LAYOUT( \
			NJD_K_Q, NJD_K_W, NJD_K_E, NJD_K_R, NJD_K_T, NJD_K_Y, NJD_K_U, NJD_K_I    , NJD_K_O  , NJD_K_P     , \
			NJD_K_A, NJD_K_S, NJD_K_D, NJD_K_F, NJD_K_G, NJD_K_H, NJD_K_J, NJD_K_K    , NJD_K_L  , NJD_K_SCOLON, \
			NJD_K_Z, NJD_K_X, NJD_K_C, NJD_K_V, NJD_K_B, NJD_K_N, NJD_K_M, NJD_K_COMMA, NJD_K_DOT, NJD_K_SLASH , \
			NJD_K_TAB     , NJD_K_BSPACE   , \
			NJD_K_LANY    , NJD_K_RANY     , \
			NJD_K_LSHIFT  , NJD_K_RSHIFT   , \
			NJD_K_SPACE   , NJD_K_ENTER    , \
			NJD_K_LOWER   , NJD_K_RAISE    , \
			NJD_K_LALT    , NJD_K_FUNCTION   \
		) \
		NJD_BASE_LAYOUT( \
			NJD_K_Q, NJD_K_W, NJD_K_E, NJD_K_R, NJD_K_T, NJD_K_Y, NJD_K_U, NJD_K_I    , NJD_K_O  , NJD_K_P     , \
			NJD_K_A, NJD_K_S, NJD_K_D, NJD_K_F, NJD_K_G, NJD_K_H, NJD_K_J, NJD_K_K    , NJD_K_L  , NJD_K_SCOLON, \
			NJD_K_Z, NJD_K_X, NJD_K_C, NJD_K_V, NJD_K_B, NJD_K_N, NJD_K_M, NJD_K_COMMA, NJD_K_DOT, NJD_K_SLASH , \
			NJD_K_TAB     , NJD_K_BSPACE   , \
			NJD_K_LANY    , NJD_K_RANY     , \
			NJD_K_LSHIFT  , NJD_K_RSHIFT   , \
			NJD_K_SPACE   , NJD_K_ENTER    , \
			NJD_K_LOWER   , NJD_K_RAISE    , \
			NJD_K_LALT    , NJD_K_FUNCTION   \
		)
#endif /* ndef NJD_LAYER_LAYOUT */
#define \
	NJD_LAYER_LAYOUT_KC( \
		K_0_0, K_0_1, K_0_2, K_0_3, K_0_4, K_0_5, K_0_6, K_0_7, K_0_8, K_0_9, \
		K_1_0, K_1_1, K_1_2, K_1_3, K_1_4, K_1_5, K_1_6, K_1_7, K_1_8, K_1_9, \
		K_2_0, K_2_1, K_2_2, K_2_3, K_2_4, K_2_5, K_2_6, K_2_7, K_2_8, K_2_9, \
		NJD_K_TAB     , NJD_K_BSPACE   , \
		NJD_K_LANY    , NJD_K_RANY     , \
		NJD_K_LSHIFT  , NJD_K_RSHIFT   , \
		NJD_K_SPACE   , NJD_K_ENTER    , \
		NJD_K_LOWER   , NJD_K_RAISE    , \
		NJD_K_LALT    , NJD_K_FUNCTION   \
	) \
	NJD_BASE_LAYOUT( \
		KC_##K_0_0, KC_##K_0_1, KC_##K_0_2, KC_##K_0_3, KC_##K_0_4, KC_##K_0_5, KC_##K_0_6, KC_##K_0_7, KC_##K_0_8, KC_##K_0_9, \
		KC_##K_1_0, KC_##K_1_1, KC_##K_1_2, KC_##K_1_3, KC_##K_1_4, KC_##K_1_5, KC_##K_1_6, KC_##K_1_7, KC_##K_1_8, KC_##K_1_9, \
		KC_##K_2_0, KC_##K_2_1, KC_##K_2_2, KC_##K_2_3, KC_##K_2_4, KC_##K_2_5, KC_##K_2_6, KC_##K_2_7, KC_##K_2_8, KC_##K_2_9, \
		KC_##NJD_K_TAB   , KC_##NJD_K_BSPACE  , \
		KC_##NJD_K_LANY  , KC_##NJD_K_RANY    , \
		KC_##NJD_K_LSHIFT, KC_##NJD_K_RSHIFT  , \
		KC_##NJD_K_SPACE , KC_##NJD_K_ENTER   , \
		KC_##NJD_K_LOWER , KC_##NJD_K_RAISE   , \
		KC_##NJD_K_LALT  , KC_##NJD_K_FUNCTION  \
	)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* DEFAULT LAYERS */
	[_QWERTY] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, E, R, T, Y, U, I   , O  , P   , \
		A, S, D, F, G, H, J, K   , L  , SCLN, \
		Z, X, C, V, B, N, M, COMM, DOT, SLSH  ),
	[_DVORAK] = NJD_BASE_LAYOUT_DEFAULT( \
		SLSH, COMM, DOT, P, Y, F, G, C, R, L, \
		A   , O   , E  , U, I, D, H, T, N, S, \
		SCLN, Q   , J  , K, X, B, M, W, V, Z  ),
	[_COLEMAK] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, F, P, G, J, L, U   , Y  , SCLN, \
		A, R, S, T, D, H, N, E   , I  , O   , \
		Z, X, C, V, B, K, M, COMM, DOT, SLSH  ),
	[_COLEMAK_DH] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, F, P, B, J, L, U   , Y  , SCLN, \
		A, R, S, T, G, M, N, E   , I  , O   , \
		Z, X, C, D, V, K, H, COMM, DOT, SLSH  ),
	[_COLEMAK_DHK] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, F, P, B, J, L, U   , Y  , SCLN, \
		A, R, S, T, G, K, N, E   , I  , O   , \
		Z, X, C, D, V, M, H, COMM, DOT, SLSH  ),
	[_WORKMAN] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, D, R, W, B, J, F, U   , P  , SCLN, \
		A, S, H, T, G, Y, N, E   , O  , I   , \
		Z, X, M, C, V, K, L, COMM, DOT, SLSH  ),

	/* LINUX ADJUSTMENTS */
	[_LINUX] = NJD_LAYER_LAYOUT( \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		LCTL_T(KC_TAB), _______, \
		LGUI_T(KC_ESC), KC_RCTL, \
		_______       , _______, \
		_______       , _______, \
		_______       , _______, \
		_______       , _______  ),

	/* LOWER - Mostly numbers and their shifted symbol counterparts */
	[_LOWER] = NJD_LAYER_LAYOUT_KC( \
		EXLM, AT  , HASH, DLR , PERC, CIRC, AMPR, ASTR, BSLS, PIPE, \
		1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 0   , \
		PLUS, MINS, ASTR, SLSH, UNDS, COLN, EQL , COMM, DOT , SLSH, \
		____, ____, \
		____, ____, \
		LALT, DEL , \
		____, ____, \
		____, ____, \
		____, ____  ),

	/* RAISE - Mostly paired enclosures and common programming symbols */
	[_RAISE] = NJD_LAYER_LAYOUT_KC( \
		XXXX, EXLM, ASTR, PLUS, XXXX, XXXX, MINS, EQL , UNDS, XXXX, \
		LBRC, RBRC, LCBR, RCBR, DLR , HASH, LPRN, RPRN, LT  , GT  , \
		XXXX, XXXX, GRV , QUOT, XXXX, XXXX, DQUO, TILD, XXXX, XXXX, \
		____, ____, \
		____, ____, \
		LALT, DEL , \
		____, ____, \
		____, ____, \
		____, ____  ),

	/* NAVIGATION */
	[_NAVIGATION_M] = NJD_LAYER_LAYOUT( \
		XXXXXXX, XXXXXXX, DM_LEFT, DM_RGHT, KC_HOME, XXXXXXX, TM_LEFT, TM_RGHT, TM_NEW , KC_PGUP, \
		KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_END , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, \
		DM_MENU, XXXXXXX, XXXXXXX, L_MOUSE, XXXXXXX, XXXXXXX, BM_BACK, BM_FRWD, XXXXXXX, BM_TOOL, \
		_______, _______, \
		_______, _______, \
		KC_CAPS, KC_CAPS, \
		_______, _______, \
		_______, _______, \
		_______, _______  ),
	[_NAVIGATION_L] = NJD_LAYER_LAYOUT( \
		XXXXXXX, XXXXXXX, DL_LEFT, DL_RGHT, KC_HOME, XXXXXXX, TL_LEFT, TL_RGHT, TL_NEW , KC_PGUP, \
		KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_END , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, \
		KC_APP , XXXXXXX, XXXXXXX, L_MOUSE, XXXXXXX, XXXXXXX, BL_BACK, BL_FRWD, XXXXXXX, XXXXXXX, \
		_______, _______, \
		_______, _______, \
		KC_CAPS, KC_CAPS, \
		_______, _______, \
		_______, _______, \
		_______, _______  ),

	/* MOUSE */
	[_MOUSE] = NJD_LAYER_LAYOUT( \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_R, XXXXXXX, KC_WH_U, \
		KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, \
		XXXXXXX, XXXXXXX, \
		L_MOUSE, XXXXXXX, \
		XXXXXXX, XXXXXXX, \
		KC_BTN1, KC_BTN2, \
		KC_ACL2, KC_ACL1, \
		XXXXXXX, XXXXXXX  ),

	/* FUNCTION - F keys, media controls, default layout selection */
	[_FUNCTION] = NJD_LAYER_LAYOUT( \
		KC_F1, KC_F2 , KC_F3 , KC_F4 , L_LINUX, D_QWRTY, D_DVRAK, D_COLEM, D_C_DH , D_C_DHK, \
		KC_F5, KC_F6 , KC_F7 , KC_F8 , KC_NLCK, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, \
		KC_F9, KC_F10, KC_F11, KC_F12, KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, \
		KC_LGUI, D_WORKM, \
		KC_LCTL, KC_MUTE, \
		KC_LSFT, XXXXXXX, \
		_______, _______, \
		_______, _______, \
		_______, _______  )
};
