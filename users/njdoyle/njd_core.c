#include "njdoyle.h"

static void njd_set_default_layers(layer_state_t default_layers) {
	eeconfig_update_default_layer(default_layers);
	default_layer_set(default_layers);
}

#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
	extern float default_layer_songs[][16][2];
#endif
void njd_set_default_layout(uint8_t layout) {
#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
	PLAY_SONG(default_layer_songs[layout]);
#endif
	layer_state_t new_state =
		(default_layer_state & 1U << _LINUX) |
		(1U << layout)                       ;
	njd_set_default_layers(new_state);
}

uint8_t njd_get_default_layout(void) {
	return get_highest_layer(default_layer_state & ~(1U << _LINUX));
}

void njd_toggle_linux_mode(void) {
	layer_state_t new_state = default_layer_state ^ (1U << _LINUX);
	njd_set_default_layers(new_state);
}

bool njd_is_linux_mode(void) {
	return default_layer_state & 1U << _LINUX;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	if (!process_record_njdoyle(keycode, record)) return false;
	if (record->event.pressed) {
		switch (keycode) {
			/* DEFAULT LAYOUTS */
			case D_QWRTY: njd_set_default_layout(_QWERTY     ); return false;
			case D_DVRAK: njd_set_default_layout(_DVORAK     ); return false;
			case D_COLEM: njd_set_default_layout(_COLEMAK    ); return false;
			case D_C_DH : njd_set_default_layout(_COLEMAK_DH ); return false;
			case D_C_DHK: njd_set_default_layout(_COLEMAK_DHK); return false;
			case D_WORKM: njd_set_default_layout(_WORKMAN    ); return false;
			/* MODES */
			case L_LINUX: njd_toggle_linux_mode()             ; return false;
		}
	}
	return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	layer_state_t new_state = layer_state_set_njdoyle(state);
	return
		update_tri_layer_state(
			new_state, _LOWER, _RAISE,
			njd_is_linux_mode() ? _NAVIGATION_L : _NAVIGATION_M);
}


/* WEAK DEFAULT IMPLEMENTATIONS */
bool process_record_njdoyle(uint16_t keycode, keyrecord_t* record) {
	return true;
}

layer_state_t layer_state_set_njdoyle(layer_state_t state) {
	return state;
}
