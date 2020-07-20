#include "njdoyle.h"

bool njdoyle_process_record_user(uint16_t keycode, keyrecord_t* record) {
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	if (record->event.pressed) {
		switch (keycode) {
			// DEFAULT LAYERS
			case D_QWRTY: set_single_persistent_default_layer(_QWERTY     ); return false;
			case D_DVRAK: set_single_persistent_default_layer(_DVORAK     ); return false;
			case D_COLEM: set_single_persistent_default_layer(_COLEMAK    ); return false;
			case D_C_DH : set_single_persistent_default_layer(_COLEMAK_DH ); return false;
			case D_C_DHM: set_single_persistent_default_layer(_COLEMAK_DHM); return false;
			case D_WORKM: set_single_persistent_default_layer(_WORKMAN    ); return false;
		}

	}

	return njdoyle_process_record_user(keycode, record);
}
