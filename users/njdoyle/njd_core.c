#include "njdoyle.h"

typedef union {
	uint32_t raw;
	struct {
		unsigned int os_mode : 2;
	};
} njd_config_t;
njd_config_t njd_config;

enum njd_os_mode njd_cycle_os_mode(void) {
	clear_keyboard();
	njd_config.os_mode += 1;
	if (NJD_OS_END == njd_config.os_mode) njd_config.os_mode = 0;
	eeconfig_update_user(njd_config.raw);
	return njd_config.os_mode;
}

enum njd_os_mode njd_get_os_mode(void) {
	return njd_config.os_mode;
}

void keyboard_post_init_user(void) {
	njd_config.raw = eeconfig_read_user();
	keyboard_post_init_njd();
}

layer_state_t layer_state_set_user(layer_state_t state) {
	state = layer_state_set_njd(state);
	return update_tri_layer_state(state, NJD_L_LOWER, NJD_L_RAISE, NJD_L_NAVIGATION);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	if (!process_record_njd(keycode, record)) return false;
	if (record->event.pressed) {
		switch (keycode) {
			/* DEFAULT LAYOUTS */
			case NJD_K_QWERTY     : set_single_persistent_default_layer(NJD_L_QWERTY     ); return false;
			case NJD_K_DVORAK     : set_single_persistent_default_layer(NJD_L_DVORAK     ); return false;
			case NJD_K_COLEMAK    : set_single_persistent_default_layer(NJD_L_COLEMAK    ); return false;
			case NJD_K_COLEMAK_DH : set_single_persistent_default_layer(NJD_L_COLEMAK_DH ); return false;
			case NJD_K_COLEMAK_DHK: set_single_persistent_default_layer(NJD_L_COLEMAK_DHK); return false;
			case NJD_K_WORKMAN    : set_single_persistent_default_layer(NJD_L_WORKMAN    ); return false;
			/* MODES */
			case NJD_K_OS_MODE: njd_cycle_os_mode(); return false;
		}
	}
	return true;
}

const uint16_t PROGMEM njd_os_keycodes[][NJD_OS_END] = {
	[NJD_K_RMAMOD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_RGUI,
		[NJD_OS_LINUX  ] = KC_RCTL,
		[NJD_OS_WINDOWS] = KC_RCTL},
	[NJD_K_LMAMOD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI_T(KC_TAB),
		[NJD_OS_LINUX  ] = LCTL_T(KC_TAB),
		[NJD_OS_WINDOWS] = LCTL_T(KC_TAB)},
	[NJD_K_LMIMOD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL_T(KC_ESC),
		[NJD_OS_LINUX  ] = LGUI_T(KC_ESC),
		[NJD_OS_WINDOWS] = LGUI_T(KC_ESC)},
	[NJD_K_MENU - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL(KC_F2),
		[NJD_OS_LINUX  ] = KC_APP     ,
		[NJD_OS_WINDOWS] = KC_APP     },
	[NJD_K_NV_MOD1 - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_LCTL,
		[NJD_OS_LINUX  ] = KC_LGUI,
		[NJD_OS_WINDOWS] = KC_LGUI},
	[NJD_K_NV_MOD2 - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_LGUI,
		[NJD_OS_LINUX  ] = KC_LALT,
		[NJD_OS_WINDOWS] = KC_LALT},
	[NJD_K_NV_MOD3 - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_LALT,
		[NJD_OS_LINUX  ] = KC_LCTL,
		[NJD_OS_WINDOWS] = KC_LCTL},
	[NJD_K_DM_PREV - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL(     KC_LEFT ),
		[NJD_OS_LINUX  ] = LGUI(     KC_PGUP ),
		[NJD_OS_WINDOWS] = LGUI(LCTL(KC_LEFT))},
	[NJD_K_DM_NEXT - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL(     KC_RIGHT ),
		[NJD_OS_LINUX  ] = LGUI(     KC_PGDN  ),
		[NJD_OS_WINDOWS] = LGUI(LCTL(KC_RIGHT))},
	[NJD_K_TB_PREV - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_LBRC),
		[NJD_OS_LINUX  ] = LCTL(KC_PGUP),
		[NJD_OS_WINDOWS] = LCTL(KC_PGUP)},
	[NJD_K_TB_NEXT - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_RBRC),
		[NJD_OS_LINUX  ] = LCTL(KC_PGDN),
		[NJD_OS_WINDOWS] = LCTL(KC_PGDN)},
	[NJD_K_TB_NEW - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI(KC_T),
		[NJD_OS_LINUX  ] = LCTL(KC_T),
		[NJD_OS_WINDOWS] = LCTL(KC_T)},
	[NJD_K_BR_BACK - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI(KC_LBRC),
		[NJD_OS_LINUX  ] = LALT(KC_LEFT),
		[NJD_OS_WINDOWS] = LALT(KC_LEFT)},
	[NJD_K_BR_FORWARD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI(KC_RBRC ),
		[NJD_OS_LINUX  ] = LALT(KC_RIGHT),
		[NJD_OS_WINDOWS] = LALT(KC_RIGHT)},
	[NJD_K_SS_ALL - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_3),
		[NJD_OS_LINUX  ] = KC_PSCR   ,
		[NJD_OS_WINDOWS] = KC_PSCR   },
	[NJD_K_SS_AREA - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_4   ),
		[NJD_OS_LINUX  ] = LSFT(KC_PSCR),
		[NJD_OS_WINDOWS] = SGUI(KC_PSCR)},
	[NJD_K_SS_WINDOW - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_4   ),
		[NJD_OS_LINUX  ] = LCTL(KC_PSCR),
		[NJD_OS_WINDOWS] = LALT(KC_PSCR)}
};

uint16_t keymap_key_to_keycode(uint8_t layer, keypos_t key) {
	uint16_t keycode = pgm_read_word(&keymaps[(layer)][(key.row)][(key.col)]);
	if (keycode >= NJD_K_OS_START && keycode <= NJD_K_OS_END) {
		enum njd_os_mode os_mode = njd_get_os_mode();
		return pgm_read_word(&njd_os_keycodes[(keycode - NJD_K_OS_START)][(os_mode)]);
	}
	return keycode;
}

/* WEAK DEFAULT IMPLEMENTATIONS */
__attribute__((weak)) bool          process_record_njd    (uint16_t keycode, keyrecord_t* record) { return true ; }
__attribute__((weak)) layer_state_t layer_state_set_njd   (layer_state_t state                  ) { return state; }
__attribute__((weak)) void          keyboard_post_init_njd(void                                 ) { return      ; }
