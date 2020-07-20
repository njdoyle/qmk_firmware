#include "njdoyle.h"
#include <stdio.h>


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_MAC] = LAYOUT( \
		LGUI_T(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC      , \
		LCTL_T(KC_ESC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI      , \
		OSM(MOD_LSFT) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_RSFT), \
		                                  KC_LALT, L_LOWER, KC_SPC ,      KC_ENT , L_RAISE, L_FUNC \
	),

	[_LINUX] = LAYOUT( \
		LCTL_T(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC      , \
		LGUI_T(KC_ESC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL      , \
		OSM(MOD_LSFT) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_RSFT), \
		                                  KC_LALT, L_LOWER, KC_SPC ,      KC_ENT , L_RAISE, L_FUNC \
	),

	NJDOYLE_LAYOUT_BASE,

	// LOWER - Mostly numbers and their shifted symbol counterparts
	[_LOWER] = LAYOUT_kc( \
		____, EXLM, AT  , HASH, DLR , PERC,      CIRC, AMPR, ASTR, BSLS, PIPE, ____, \
		____, 1   , 2   , 3   , 4   , 5   ,      6   , 7   , 8   , 9   , 0   , ____, \
		LALT, PLUS, MINS, ASTR, SLSH, UNDS,      COLN, EQL , COMM, DOT , SLSH, DEL , \
		                  ____, ____, ____,      ____, ____, ____ \
	),

	// RAISE - Mostly paired enclosures and common programming symbols
	[_RAISE] = LAYOUT_kc( \
		____, XXXX, EXLM, ASTR, PLUS, XXXX,      XXXX, MINS, EQL , UNDS, XXXX, ____, \
		____, LBRC, RBRC, LCBR, RCBR, DLR ,      HASH, LPRN, RPRN, LT  , GT  , ____, \
		LALT, XXXX, XXXX, GRV , QUOT, XXXX,      XXXX, DQUO, TILD, XXXX, XXXX, DEL , \
		                  ____, ____, ____,      ____, ____, ____ \
	),

	// NAVIGATION
	[_NAVIGATION_M] = LAYOUT( \
		_______, XXXXXXX, XXXXXXX, DM_LEFT, DM_RGHT, KC_HOME,      XXXXXXX, TM_LEFT, TM_RGHT, TM_NEW , KC_PGUP, _______, \
		_______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_END ,      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, _______, \
		KC_CAPS, DM_MENU, XXXXXXX, XXXXXXX, L_MOUSE, XXXXXXX,      XXXXXXX, BM_BACK, BM_FRWD, XXXXXXX, BM_TOOL, KC_CAPS, \
		                           _______, _______, _______,      _______, _______, _______ \
	),
	[_NAVIGATION_L] = LAYOUT( \
		_______, XXXXXXX, XXXXXXX, DL_LEFT, DL_RGHT, KC_HOME,      XXXXXXX, TL_LEFT, TL_RGHT, TL_NEW , KC_PGUP, _______, \
		_______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_END ,      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, _______, \
		KC_CAPS, KC_APP , XXXXXXX, XXXXXXX, L_MOUSE, XXXXXXX,      XXXXXXX, BL_BACK, BL_FRWD, XXXXXXX, XXXXXXX, KC_CAPS, \
		                           _______, _______, _______,      _______, _______, _______ \
	),

	// MOUSE
	[_MOUSE] = LAYOUT( \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_WH_L, KC_WH_R, XXXXXXX, KC_WH_U, XXXXXXX, \
		L_MOUSE, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, \
		                           KC_ACL1, KC_ACL2, KC_BTN1,     KC_BTN2, KC_ACL1, KC_ACL2 \
	),

	// FUNCTION - F keys, media controls, default layout selection
	[_FUNCTION] = LAYOUT( \
		KC_LGUI, KC_F1, KC_F2 , KC_F3 , KC_F4 , L_LINUX,     D_QWRTY, D_DVRAK, D_COLEM, D_C_DH , D_C_DHK, D_WORKM, \
		KC_LCTL, KC_F5, KC_F6 , KC_F7 , KC_F8 , XXXXXXX,     KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, KC_MUTE, \
		KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,     NJM_1  , NJM_2  , NJM_3  , NJM_4  , NJM_5  , XXXXXXX, \
		                      _______, _______, _______,     _______, _______, _______ \
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
	if (layer_state & 1UL << _LINUX)
		return update_tri_layer_state(state, _LOWER, _RAISE, _NAVIGATION_L);
	return update_tri_layer_state(state, _LOWER, _RAISE, _NAVIGATION_M);
}



#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return is_master ? rotation : OLED_ROTATION_180;
}

void oled_render_layout_state(void) {
	oled_write_P(PSTR("Layout: "), false);
	if      (default_layer_state & 1UL << _QWERTY     ) oled_write_ln_P(PSTR("QWERTY"     ), false);
	else if (default_layer_state & 1UL << _DVORAK     ) oled_write_ln_P(PSTR("Dvorak"     ), false);
	else if (default_layer_state & 1UL << _COLEMAK    ) oled_write_ln_P(PSTR("Colemak"    ), false);
	else if (default_layer_state & 1UL << _COLEMAK_DH ) oled_write_ln_P(PSTR("Colemak DH" ), false);
	else if (default_layer_state & 1UL << _COLEMAK_DHK) oled_write_ln_P(PSTR("Colemak DHk"), false);
	else if (default_layer_state & 1UL << _WORKMAN    ) oled_write_ln_P(PSTR("Workman"    ), false);
	else                                                oled_write_ln_P(PSTR("UNKNOWN"    ), false);
}

void oled_render_os_mode(void) {
	oled_write_P(PSTR("  Mode: "), false);
	if   (layer_state & 1UL << _LINUX) oled_write_ln_P(PSTR("Linux"), false);
	else                               oled_write_ln_P(PSTR("macOS"), false);
}

void oled_render_layer_state(void) {
	oled_write_P(PSTR(" Layer: "), false);
	if      ( layer_state & 1UL << _FUNCTION    ) oled_write_ln_P(PSTR("Function"  ), false);
	else if ( layer_state & 1UL << _MOUSE       ) oled_write_ln_P(PSTR("Mouse"     ), false);
	else if ( layer_state & 1UL << _NAVIGATION_L) oled_write_ln_P(PSTR("Navigation"), false);
	else if ( layer_state & 1UL << _NAVIGATION_M) oled_write_ln_P(PSTR("Navigation"), false);
	else if ( layer_state & 1UL << _RAISE       ) oled_write_ln_P(PSTR("Raise"     ), false);
	else if ( layer_state & 1UL << _LOWER       ) oled_write_ln_P(PSTR("Lower"     ), false);
	else if (
			 layer_state & 1UL << _LINUX ||
			!layer_state                 )
		oled_write_ln_P(PSTR("Base"   ), false);
	else
		oled_write_ln_P(PSTR("UNKNOWN"), false);
}

void oled_render_host_led_state(void) {
	uint8_t leds = host_keyboard_leds();
	oled_write_P   (PSTR(" Locks: "), false);
	oled_write_P   ((leds & (1 << USB_LED_CAPS_LOCK  )) ? PSTR("C") : PSTR("-"), false);
	oled_write_P   ((leds & (1 << USB_LED_NUM_LOCK   )) ? PSTR("N") : PSTR("-"), false);
	oled_write_ln_P((leds & (1 << USB_LED_SCROLL_LOCK)) ? PSTR("S") : PSTR("-"), false);
}

void oled_render_logo(void) {
	static const char PROGMEM crkbd_logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
		0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
		0};
	oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
	if (is_master) {
		oled_render_layout_state  ();
		oled_render_os_mode       ();
		oled_render_layer_state   ();
		oled_render_host_led_state();
	} else {
		oled_render_logo();
	}
}

#endif // OLED_DRIVER_ENABLE

