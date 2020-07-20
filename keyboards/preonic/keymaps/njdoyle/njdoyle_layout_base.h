#pragma once

#define \
	NJDOYLE_LAYOUT_BASE_KC( \
		K_0_0, K_0_1, K_0_2, K_0_3, K_0_4, K_0_5, K_0_6, K_0_7, K_0_8, K_0_9, \
		K_1_0, K_1_1, K_1_2, K_1_3, K_1_4, K_1_5, K_1_6, K_1_7, K_1_8, K_1_9, \
		K_2_0, K_2_1, K_2_2, K_2_3, K_2_4, K_2_5, K_2_6, K_2_7, K_2_8, K_2_9  \
	) \
	LAYOUT_preonic_grid( \
		KC_F1         , KC_F2     , KC_F3     , KC_F4     , KC_F5     , KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_F11    , KC_F12       , \
		LGUI_T(KC_TAB), KC_##K_0_0, KC_##K_0_1, KC_##K_0_2, KC_##K_0_3, KC_##K_0_4, KC_##K_0_5, KC_##K_0_6, KC_##K_0_7, KC_##K_0_8, KC_##K_0_9, KC_BSPC      , \
		LCTL_T(KC_ESC), KC_##K_1_0, KC_##K_1_1, KC_##K_1_2, KC_##K_1_3, KC_##K_1_4, KC_##K_1_5, KC_##K_1_6, KC_##K_1_7, KC_##K_1_8, KC_##K_1_9, KC_RGUI      , \
		OSM(MOD_LSFT) , KC_##K_2_0, KC_##K_2_1, KC_##K_2_2, KC_##K_2_3, KC_##K_2_4, KC_##K_2_5, KC_##K_2_6, KC_##K_2_7, KC_##K_2_8, KC_##K_2_9, OSM(MOD_RSFT), \
		L_FUNC        , KC_LCTL   , KC_LGUI   , KC_LALT   , L_LOWER   , KC_SPC    , KC_ENT    , L_RAISE   , KC_LEFT   , KC_DOWN   , KC_UP     , KC_RIGHT       \
	)

