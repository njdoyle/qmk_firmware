#include "njdoyle.h"

#ifdef OLED_DRIVER_ENABLE

static void njd_oled_render_layout_state(void) {
	oled_write_P(PSTR("Layout: "), false);
	switch (get_highest_layer(default_layer_state)) {
		case NJD_L_QWERTY     : oled_write_ln_P(PSTR("QWERTY"     ), false); break;
		case NJD_L_DVORAK     : oled_write_ln_P(PSTR("Dvorak"     ), false); break;
		case NJD_L_COLEMAK    : oled_write_ln_P(PSTR("Colemak"    ), false); break;
		case NJD_L_COLEMAK_DH : oled_write_ln_P(PSTR("Colemak DH" ), false); break;
		case NJD_L_COLEMAK_DHK: oled_write_ln_P(PSTR("Colemak DHk"), false); break;
		case NJD_L_WORKMAN    : oled_write_ln_P(PSTR("Workman"    ), false); break;
		default               : oled_write_ln_P(PSTR("UNKNOWN"    ), false); break;
	}
}

static void njd_oled_render_os_mode(void) {
	oled_write_P(PSTR("  Mode: "), false);
	switch (njd_get_os_mode()) {
		case NJD_OS_MACOS  : oled_write_ln_P(PSTR("macOS"  ), false); break;
		case NJD_OS_LINUX  : oled_write_ln_P(PSTR("Linux"  ), false); break;
		case NJD_OS_WINDOWS: oled_write_ln_P(PSTR("Windows"), false); break;
		default            : oled_write_ln_P(PSTR("UNKNOWN"), false); break;
	}
}

static void njd_oled_render_layer_state(void) {
	oled_write_P(PSTR(" Layer: "), false);
	switch (get_highest_layer(layer_state)) {
		case 0               : oled_write_ln_P(PSTR("Base"      ), false); break;
		case NJD_L_LOWER     : oled_write_ln_P(PSTR("Lower"     ), false); break;
		case NJD_L_RAISE     : oled_write_ln_P(PSTR("Raise"     ), false); break;
		case NJD_L_NAVIGATION: oled_write_ln_P(PSTR("Navigation"), false); break;
		case NJD_L_MOUSE     : oled_write_ln_P(PSTR("Mouse"     ), false); break;
		case NJD_L_FUNCTION  : oled_write_ln_P(PSTR("Function"  ), false); break;
		default              : oled_write_ln_P(PSTR("UNKNOWN"   ), false); break;
	}
}

static void njd_oled_render_host_led_state(void) {
	uint8_t leds = host_keyboard_leds();
	oled_write_P   (PSTR(" Locks: "), false);
	oled_write_P   ((leds & (1 << USB_LED_CAPS_LOCK  )) ? PSTR("C") : PSTR("-"), false);
	oled_write_P   ((leds & (1 << USB_LED_NUM_LOCK   )) ? PSTR("N") : PSTR("-"), false);
	oled_write_ln_P((leds & (1 << USB_LED_SCROLL_LOCK)) ? PSTR("S") : PSTR("-"), false);
}

static void njd_oled_render_logo(void) {
	static const char PROGMEM logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
		0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
		0};
	oled_write_P(logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return is_master ? rotation : OLED_ROTATION_180;
}

void oled_task_user(void) {
	if (is_master) {
		njd_oled_render_layout_state  ();
		njd_oled_render_os_mode       ();
		njd_oled_render_layer_state   ();
		njd_oled_render_host_led_state();
	} else {
		njd_oled_render_logo();
	}
}

#endif /* def OLED_DRIVER_ENABLE */
