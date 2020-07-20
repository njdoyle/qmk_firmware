#include "njdoyle.h"
#include <stdio.h>

extern uint8_t is_master;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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
	[_NAVIGATION] = LAYOUT( \
		_______, XXXXXXX, XXXXXXX, DE_LEFT, DE_RGHT, KC_HOME,      XXXXXXX, TB_LEFT, TB_RGHT, TB_NEW , KC_PGUP, _______, \
		_______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_END ,      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, _______, \
		KC_CAPS, DE_MENU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, BR_BACK, BR_FRWD, XXXXXXX, BR_TOOL, KC_CAPS, \
		                           _______, _______, _______,      _______, _______, _______ \
	),

	// FUNCTION - F keys, media controls, default layout selection
	[_FUNCTION] = LAYOUT( \
		KC_LGUI, KC_F1, KC_F2 , KC_F3 , KC_F4 , XXXXXXX,     D_QWRTY, D_DVRAK, D_COLEM, D_C_DH , D_C_DHM, D_WORKM, \
		KC_LCTL, KC_F5, KC_F6 , KC_F7 , KC_F8 , XXXXXXX,     KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, KC_MUTE, \
		KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,     NJM_1  , NJM_2  , NJM_3  , NJM_4  , NJM_5  , XXXXXXX, \
		                      _______, _______, _______,     _______, _______, _______ \
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _LOWER, _RAISE, _NAVIGATION);
}


// ********** OLED STUFF **********

void matrix_init_user(void) {
#ifdef SSD1306OLED
	//SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
	iota_gfx_init(!has_usb());   // turns on the display
#endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
const char *read_host_led_state(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);
//const char *read_mode_icon(bool swap);
//void set_timelog(void);
//const char *read_timelog(void);

char layout_state_str[24];

const char *read_layout_state(void) {
	if      ( default_layer_state & 1UL << _QWERTY     ) snprintf(layout_state_str, sizeof(layout_state_str), "Layout: QWERTY"     );
	else if ( default_layer_state & 1UL << _DVORAK     ) snprintf(layout_state_str, sizeof(layout_state_str), "Layout: Dvorak"     );
	else if ( default_layer_state & 1UL << _COLEMAK    ) snprintf(layout_state_str, sizeof(layout_state_str), "Layout: Colemak"    );
	else if ( default_layer_state & 1UL << _COLEMAK_DH ) snprintf(layout_state_str, sizeof(layout_state_str), "Layout: Colemak DH" );
	else if ( default_layer_state & 1UL << _COLEMAK_DHM) snprintf(layout_state_str, sizeof(layout_state_str), "Layout: Colemak DHm");
	else if ( default_layer_state & 1UL << _WORKMAN    ) snprintf(layout_state_str, sizeof(layout_state_str), "Layout: Workman"    );
	else                                                 snprintf(layout_state_str, sizeof(layout_state_str), "Layout: UNKNOWN"    );
	return layout_state_str;
}


char layer_state_str[24];

const char *read_layer_state(void) {
	if      ( layer_state & 1UL << _FUNCTION  ) snprintf(layer_state_str, sizeof(layer_state_str), " Layer: Function"  );
	else if ( layer_state & 1UL << _NAVIGATION) snprintf(layer_state_str, sizeof(layer_state_str), " Layer: Navigation");
	else if ( layer_state & 1UL << _RAISE     ) snprintf(layer_state_str, sizeof(layer_state_str), " Layer: Raise"     );
	else if ( layer_state & 1UL << _LOWER     ) snprintf(layer_state_str, sizeof(layer_state_str), " Layer: Lower"     );
	else if (!layer_state                     ) snprintf(layer_state_str, sizeof(layer_state_str), " Layer: Base"      );
	else                                        snprintf(layer_state_str, sizeof(layer_state_str), " Layer: Undef-%ld", layer_state);
	return layer_state_str;
}

char host_led_state_str[24];

const char *read_host_led_state(void) {
	uint8_t leds = host_keyboard_leds();
	snprintf(
		host_led_state_str, sizeof(host_led_state_str),
		" Locks: %s%s%s",
		(leds & (1 << USB_LED_CAPS_LOCK  )) ? "C" : "-",
		(leds & (1 << USB_LED_NUM_LOCK   )) ? "N" : "-",
		(leds & (1 << USB_LED_SCROLL_LOCK)) ? "S" : "-");
	return host_led_state_str;
}

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
	if (is_master) {
		// If you want to change the display of OLED, you need to change here
		matrix_write_ln(matrix, read_layout_state  ());
		matrix_write_ln(matrix, read_layer_state   ());
		matrix_write_ln(matrix, read_host_led_state());
		//matrix_write_ln(matrix, "");
		//matrix_write_ln(matrix, read_keylog());
		//matrix_write_ln(matrix, read_keylogs());
		//matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
		//matrix_write_ln(matrix, read_timelog());
	} else {
		matrix_write(matrix, read_logo());
	}
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
	if (memcmp(dest->display, source->display, sizeof(dest->display))) {
		memcpy(dest->display, source->display, sizeof(dest->display));
		dest->dirty = true;
	}
}

void iota_gfx_task_user(void) {
	struct CharacterMatrix matrix;
	matrix_clear(&matrix);
	matrix_render_user(&matrix);
	matrix_update(&display, &matrix);
}
#endif //SSD1306OLED

