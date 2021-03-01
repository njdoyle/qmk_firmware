#pragma once

#include QMK_KEYBOARD_H

// LAYERS
#define _QWERTY        0
#define _DVORAK        1
#define _COLEMAK       2
#define _COLEMAK_DH    3
#define _COLEMAK_DHK   4
#define _WORKMAN       5
#define _LINUX         6
#define _LOWER         7
#define _RAISE         8
#define _NAVIGATION_M  9
#define _NAVIGATION_L 10
#define _MOUSE        11
#define _FUNCTION     12

// KEY ALIASES
#define L_LOWER MO(_LOWER)
#define L_RAISE MO(_RAISE)
#define L_FUNC  MO(_FUNCTION)
#define L_MOUSE TG(_MOUSE)
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

// MAC ALIASES
#define DM_LEFT LCTL(KC_LEFT)
#define DM_RGHT LCTL(KC_RIGHT)
#define DM_MENU LCTL(KC_F2)
#define TM_LEFT SGUI(KC_LBRC)
#define TM_RGHT SGUI(KC_RBRC)
#define TM_NEW  LGUI(KC_T)
#define BM_BACK RGUI(KC_LBRC)
#define BM_FRWD RGUI(KC_RBRC)
#define BM_TOOL LCAG(KC_SLSH)

// LINUX ALIASES
#define DL_LEFT LGUI(KC_PGUP)
#define DL_RGHT LGUI(KC_PGDN)
#define TL_LEFT LCTL(KC_PGUP)
#define TL_RGHT LCTL(KC_PGDN)
#define TL_NEW  LCTL(KC_T)
#define BL_BACK LALT(KC_LEFT)
#define BL_FRWD LALT(KC_RGHT)

enum njdoyle_keycodes {
	// DEFAULT LAYERS
	D_QWRTY = SAFE_RANGE, // QWERTY
	D_DVRAK,              // Dvorak
	D_COLEM,              // Colemak
	D_C_DH ,              // Colemak Mod-DH
	D_C_DHK,              // Colemak Mod-DHk
	D_WORKM,              // Workman

	// MODES
	L_LINUX,

	// UTILITY
	NJDOYLE_SAFE_RANGE
};

bool          process_record_njdoyle (uint16_t, keyrecord_t*) __attribute__((weak));
layer_state_t layer_state_set_njdoyle(layer_state_t         ) __attribute__((weak));

