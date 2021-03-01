#pragma once

// SPLIT
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
#define USE_SERIAL_PD2


// OLED
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"


// BASE LAYOUT
#define \
	NJD_BASE_LAYOUT( \
		NJD_K_Q, NJD_K_W, NJD_K_E, NJD_K_R, NJD_K_T, NJD_K_Y, NJD_K_U, NJD_K_I    , NJD_K_O  , NJD_K_P     , \
		NJD_K_A, NJD_K_S, NJD_K_D, NJD_K_F, NJD_K_G, NJD_K_H, NJD_K_J, NJD_K_K    , NJD_K_L  , NJD_K_SCOLON, \
		NJD_K_Z, NJD_K_X, NJD_K_C, NJD_K_V, NJD_K_B, NJD_K_N, NJD_K_M, NJD_K_COMMA, NJD_K_DOT, NJD_K_SLASH , \
		NJD_K_TAB  , NJD_K_BSPACE  , \
		NJD_K_LANY , NJD_K_RANY    , \
		NJD_K_LSFT , NJD_K_RSFT    , \
		NJD_K_SPACE, NJD_K_ENTER   , \
		NJD_K_LOWER, NJD_K_RAISE   , \
		NJD_K_LALT , NJD_K_FUNCTION  \
	) \
	LAYOUT( \
		NJD_K_TAB , NJD_K_Q, NJD_K_W, NJD_K_E, NJD_K_R, NJD_K_T,      NJD_K_Y, NJD_K_U, NJD_K_I    , NJD_K_O  , NJD_K_P     , NJD_K_BSPACE, \
		NJD_K_LANY, NJD_K_A, NJD_K_S, NJD_K_D, NJD_K_F, NJD_K_G,      NJD_K_H, NJD_K_J, NJD_K_K    , NJD_K_L  , NJD_K_SCOLON, NJD_K_RANY  , \
		NJD_K_LSFT, NJD_K_Z, NJD_K_X, NJD_K_C, NJD_K_V, NJD_K_B,      NJD_K_N, NJD_K_M, NJD_K_COMMA, NJD_K_DOT, NJD_K_SLASH , NJD_K_RSFT  , \
		                   NJD_K_LALT, NJD_K_LOWER, NJD_K_SPACE,      NJD_K_ENTER, NJD_K_RAISE, NJD_K_FUNCTION \
	)

