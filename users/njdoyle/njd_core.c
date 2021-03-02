#include "njdoyle.h"

typedef union {
	uint32_t raw;
	struct {
		bool is_linux :1;
	};
} njd_config_t;
njd_config_t njd_config;

void njd_toggle_linux_mode(void) {
	clear_keyboard();
	njd_config.is_linux = !njd_config.is_linux;
	eeconfig_update_user(njd_config.raw);
}

bool njd_is_linux_mode(void) {
	return njd_config.is_linux;
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
			case NJD_K_OSMODE: njd_toggle_linux_mode(); return false;
		}
	}
	return true;
}

uint16_t keymap_key_to_keycode(uint8_t layer, keypos_t key) {
	uint16_t keycode = pgm_read_word(&keymaps[(layer)][(key.row)][(key.col)]);
	switch (keycode) {
		case NJD_K_RMAMOD    : return njd_config.is_linux ?       (KC_RCTL ) :       (KC_RGUI );
		case NJD_K_LMAMOD    : return njd_config.is_linux ? LCTL_T(KC_TAB  ) : LGUI_T(KC_TAB  );
		case NJD_K_LMIMOD    : return njd_config.is_linux ? LGUI_T(KC_ESC  ) : LCTL_T(KC_ESC  );
		case NJD_K_MENU      : return njd_config.is_linux ?       (KC_APP  ) : LCTL  (KC_F2   );
		case NJD_K_NV_MOD1   : return njd_config.is_linux ?       (KC_LGUI ) :       (KC_LCTL );
		case NJD_K_NV_MOD2   : return njd_config.is_linux ?       (KC_LALT ) :       (KC_LGUI );
		case NJD_K_NV_MOD3   : return njd_config.is_linux ?       (KC_LCTL ) :       (KC_LALT );
		case NJD_K_DM_PREV   : return njd_config.is_linux ? LGUI  (KC_PGUP ) : LCTL  (KC_LEFT );
		case NJD_K_DM_NEXT   : return njd_config.is_linux ? LGUI  (KC_PGDN ) : LCTL  (KC_RIGHT);
		case NJD_K_TB_PREV   : return njd_config.is_linux ? LCTL  (KC_PGUP ) : SGUI  (KC_LBRC );
		case NJD_K_TB_NEXT   : return njd_config.is_linux ? LCTL  (KC_PGDN ) : SGUI  (KC_RBRC );
		case NJD_K_TB_NEW    : return njd_config.is_linux ? LCTL  (KC_T    ) : LGUI  (KC_T    );
		case NJD_K_BR_BACK   : return njd_config.is_linux ? LALT  (KC_LEFT ) : LGUI  (KC_LBRC );
		case NJD_K_BR_FORWARD: return njd_config.is_linux ? LALT  (KC_RIGHT) : LGUI  (KC_RBRC );
		case NJD_K_SS_ALL    : return njd_config.is_linux ?       (KC_PSCR ) : SGUI  (KC_3    );
		case NJD_K_SS_AREA   : return njd_config.is_linux ? LSFT  (KC_PSCR ) : SGUI  (KC_4    );
		case NJD_K_SS_WINDOW : return njd_config.is_linux ? LCTL  (KC_PSCR ) : SGUI  (KC_4    );
	}
	return keycode;
}

/* WEAK DEFAULT IMPLEMENTATIONS */
__attribute__((weak)) bool          process_record_njd    (uint16_t keycode, keyrecord_t* record) { return true ; }
__attribute__((weak)) layer_state_t layer_state_set_njd   (layer_state_t state                  ) { return state; }
__attribute__((weak)) void          keyboard_post_init_njd(void                                 ) { return      ; }
