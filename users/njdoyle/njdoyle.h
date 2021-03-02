#pragma once

#include QMK_KEYBOARD_H

/* LAYERS */
#define NJD_L_QWERTY        0
#define NJD_L_DVORAK        1
#define NJD_L_COLEMAK       2
#define NJD_L_COLEMAK_DH    3
#define NJD_L_COLEMAK_DHK   4
#define NJD_L_WORKMAN       5
#define NJD_L_LOWER         6
#define NJD_L_RAISE         7
#define NJD_L_NAVIGATION    8
#define NJD_L_MOUSE         9
#define NJD_L_FUNCTION     10

/* KEY ALIASES */
#define NJD_K_LOWER      MO(NJD_L_LOWER     )
#define NJD_K_RAISE      MO(NJD_L_RAISE     )
#define NJD_K_NAVIGATION MO(NJD_L_NAVIGATION)
#define NJD_K_FUNCTION   MO(NJD_L_FUNCTION  )
#define NJD_K_MOUSE      TG(NJD_L_MOUSE     )
#define KC_____          KC_TRNS
#define KC_XXXX          KC_NO

enum njd_keycodes {
	NJD_K_QWERTY = SAFE_RANGE,
	NJD_K_DVORAK,
	NJD_K_COLEMAK,
	NJD_K_COLEMAK_DH ,
	NJD_K_COLEMAK_DHK,
	NJD_K_WORKMAN,

	NJD_K_RMAMOD,
	NJD_K_LMAMOD,
	NJD_K_LMIMOD,
	NJD_K_OSMODE,
	NJD_K_MENU,

	NJD_K_NV_MOD1,
	NJD_K_NV_MOD2,
	NJD_K_NV_MOD3,
	NJD_K_DM_PREV,
	NJD_K_DM_NEXT,
	NJD_K_TB_PREV,
	NJD_K_TB_NEXT,
	NJD_K_TB_NEW,
	NJD_K_BR_BACK,
	NJD_K_BR_FORWARD,
	NJD_K_SS_ALL,
	NJD_K_SS_WINDOW,
	NJD_K_SS_AREA,

	NJD_SAFE_RANGE
};

void njd_toggle_linux_mode(void);
bool njd_is_linux_mode    (void);

bool          process_record_njd    (uint16_t, keyrecord_t*);
layer_state_t layer_state_set_njd   (layer_state_t         );
void          keyboard_post_init_njd(void                  );
