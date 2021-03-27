#include "njdoyle.h"

#ifdef OLED_DRIVER_ENABLE

#ifndef NJD_OLED_NEW

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
		case NJD_L_OPTIONS   : oled_write_ln_P(PSTR("Options"   ), false); break;
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
		0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,0x90,0x91,0x92,0x93,0x94,
		0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,
		0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,0xD0,0xD1,0xD2,0xD3,0xD4,
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

#else


/* SPRITES */

static const char PROGMEM njd_sprite_logo[4*16] = {
	0x20,0x36,0x3A,0x3A,0x3A,0x20,0x30,0x3A,0x3A,0x3C,0x20,0x3A,0x3E,0x3A,0x3C,0x20,
	0x20,0x35,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x35,0x20,0x20,0x35,0x20,0x35,0x20,
	0x20,0x35,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x35,0x20,0x20,0x35,0x20,0x35,0x20,
	0x20,0x33,0x3A,0x3A,0x3A,0x20,0x20,0x20,0x32,0x39,0x20,0x20,0x33,0x3A,0x39,0x20
};

static const char PROGMEM njd_sprite_layout[4*12] = {
	/* QWERTY  Dvorak     Colemak    ColemakDH  ColemakDHk Workman */
	0x12,0x5A, 0x12,0x2C, 0x16,0x1C, 0x54,0x58, 0x55,0x59, 0x16,0x1C,
	0x12,0x5E, 0x12,0x29, 0x13,0x19, 0x50,0x5C, 0x51,0x5D, 0x13,0x19,
	0x16,0x1E, 0x26,0x2C, 0x14,0x14, 0x14,0x14, 0x14,0x14, 0x12,0x5A,
	0x13,0x19, 0x13,0x19, 0x13,0x19, 0x13,0x19, 0x13,0x19, 0x12,0x5E
};

static const char PROGMEM njd_sprite_os_space[6] = {
	0x20,0x20,0x20,0x20,0x20,0x20
};

static const char PROGMEM njd_sprite_os[2*18] = {
	/* macOS                       Linux                          Windows */
	0x56,0x18,0x26,0x18,0x14,0x14, 0x16,0x18,0x79,0x78,0x57,0x5B, 0x12,0x5A,0x79,0x78,0x16,0x18,
	0x52,0x18,0x23,0x18,0x13,0x19, 0x13,0x18,0x71,0x70,0x53,0x5F, 0x12,0x5E,0x71,0x70,0x13,0x18
};

static const char PROGMEM njd_sprite_layers[4*28] = {
	/* Alpha             Numbers              Symbols              Navigation           Mouse                Function             Options */
	0x20,0x14,0x75,0x7D, 0x64,0x6A,0x66,0x68, 0x87,0x8E,0x16,0x1C, 0x26,0x2C,0x44,0x2C, 0x26,0x1E,0x1A,0x2C, 0x12,0x1C,0x14,0x14, 0x26,0x2C,0x20,0x20,
	0x12,0x19,0x74,0x7C, 0x61,0x6F,0x63,0x6D, 0x86,0x8F,0x53,0x5F, 0x42,0x48,0x41,0x29, 0x7B,0x7A,0x20,0x15, 0x12,0x19,0x13,0x19, 0x13,0x1B,0x79,0x8B,
	0x26,0X18,0x26,0x2C, 0x65,0x6B,0x67,0x69, 0x64,0x68,0x57,0x5B, 0x26,0x44,0x42,0x48, 0x73,0x72,0x20,0x15, 0x14,0x20,0x16,0x18, 0x16,0x1C,0x71,0x82,
	0x23,0x18,0x13,0x1B, 0X60,0X6E,0x62,0x6C, 0x60,0x6C,0x13,0x19, 0x23,0x41,0x23,0x29, 0x23,0x1B,0x1A,0x29, 0x51,0x7C,0x13,0x18, 0x13,0x19,0x20,0x20
};

static const char PROGMEM njd_sprite_locks[2*6] = {
	/* Off     Caps       Num */
	0x84,0x88, 0x14,0x14, 0x16,0x18,
	0x80,0x8C, 0x13,0x19, 0x13,0x18
};


/* LOGIC */

void njd_oled_write_chars_P(const char* data, uint8_t count) {
	uint8_t c;
	while (count--) {
		c = pgm_read_byte(data++);
		oled_write_char(c, false);
	}
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

void oled_task_user(void) {
	if (is_master) {
		uint8_t          layout   = get_highest_layer(default_layer_state);
		uint8_t          layer    = get_highest_layer(        layer_state);
		enum njd_os_mode os       = njd_get_os_mode();
		uint8_t          leds     = host_keyboard_leds();
		uint8_t          capslock = (0 != (leds & (1 << USB_LED_CAPS_LOCK))) ? 2 : 0;
		uint8_t          numlock  = (0 != (leds & (1 << USB_LED_NUM_LOCK ))) ? 4 : 0;

		if (0 != layer) layer -= NJD_L_LOWER - 1;

		for (uint8_t row = 0; row < 4; ++row) {
			// LAYOUT
			njd_oled_write_chars_P(
				njd_sprite_layout +
				(row    * 12)     +
				(layout *  2)     ,
				2                 );

			// OS
			if (0 == row || 3 == row)
				njd_oled_write_chars_P(njd_sprite_os_space, 6);
			else
				njd_oled_write_chars_P(
					njd_sprite_os    +
					((row - 1) * 18) +
					(os        *  6) ,
					6                );

			// SPACE
			oled_write_char(0x20, false);

			// LAYER
			njd_oled_write_chars_P(
				njd_sprite_layers +
				(row   * 28)      +
				(layer *  4)      ,
				4                 );

			// SPACE
			oled_write_char(0x20, false);

			// LOCKS
			njd_oled_write_chars_P(
				njd_sprite_locks                 +
				((row & 1) * 6)                  +
				((row & 2) ? capslock : numlock) ,
				2                                );
		}
	} else {
		njd_oled_write_chars_P(njd_sprite_logo, 4 * 16);
	}
}

#endif /* ndef NJD_OLED_NEW */

#endif /* def OLED_DRIVER_ENABLE */
