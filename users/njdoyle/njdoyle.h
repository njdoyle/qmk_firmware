#pragma once

#include QMK_KEYBOARD_H

// LAYERS
#define _MAC           0
#define _LINUX         1
#define _QWERTY        2
#define _DVORAK        3
#define _COLEMAK       4
#define _COLEMAK_DH    5
#define _COLEMAK_DHK   6
#define _WORKMAN       7
#define _LOWER         8
#define _RAISE         9
#define _NAVIGATION_M 10
#define _NAVIGATION_L 11
#define _MOUSE        12
#define _FUNCTION     13

// KEY ALIASES
#define NJM_1   LSA(KC_P1)
#define NJM_2   LSA(KC_P2)
#define NJM_3   LSA(KC_P3)
#define NJM_4   LSA(KC_P4)
#define NJM_5   LSA(KC_P5)
#define NJM_6   LSA(KC_P6)
#define NJM_7   LSA(KC_P7)
#define NJM_8   LSA(KC_P8)
#define NJM_9   LSA(KC_P9)
#define NJM_0   LSA(KC_P0)
#define L_LINUX TG(_LINUX)
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

	// UTILITY
	NJDOYLE_SAFE_RANGE
};

#include "njdoyle_layout_base.h"

#define NJDOYLE_LAYOUT_BASE \
	[_QWERTY] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, W, E, R, T, Y, U, I   , O  , P   , \
		A, S, D, F, G, H, J, K   , L  , SCLN, \
		Z, X, C, V, B, N, M, COMM, DOT, SLSH  \
	), \
	[_DVORAK] = NJDOYLE_LAYOUT_BASE_KC( \
		SLSH, COMM, DOT, P, Y, F, G, C, R, L, \
		A   , O   , E  , U, I, D, H, T, N, S, \
		SCLN, Q   , J  , K, X, B, M, W, V, Z  \
	), \
	[_COLEMAK] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, W, F, P, G, J, L, U   , Y  , SCLN, \
		A, R, S, T, D, H, N, E   , I  , O   , \
		Z, X, C, V, B, K, M, COMM, DOT, SLSH  \
	), \
	[_COLEMAK_DH] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, W, F, P, B, J, L, U   , Y  , SCLN, \
		A, R, S, T, G, M, N, E   , I  , O   , \
		Z, X, C, D, V, K, H, COMM, DOT, SLSH  \
	), \
	[_COLEMAK_DHK] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, W, F, P, B, J, L, U   , Y  , SCLN, \
		A, R, S, T, G, K, N, E   , I  , O   , \
		Z, X, C, D, V, M, H, COMM, DOT, SLSH  \
	), \
	[_WORKMAN] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, D, R, W, B, J, F, U   , P  , SCLN, \
		A, S, H, T, G, Y, N, E   , O  , I   , \
		Z, X, M, C, V, K, L, COMM, DOT, SLSH  \
	)

bool njdoyle_process_record_user(uint16_t, keyrecord_t*) __attribute__((weak));

