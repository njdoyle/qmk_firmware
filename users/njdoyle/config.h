#pragma once

// GENERAL
#define FORCE_NKRO
#define ONESHOT_TAP_TOGGLE 0
#define TAPPING_TERM 200
//#define TAPPING_FORCE_HOLD

// MOUSE
//#define MK_COMBINED
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MOUSEKEY_DELAY      100
#define MOUSEKEY_INTERVAL    10
#define MOUSEKEY_MAX_SPEED    8
#define MK_C_OFFSET_UNMOD    16
#define MK_C_INTERVAL_UNMOD  16
#define MK_C_OFFSET_0         1
#define MK_C_INTERVAL_0      16
#define MK_C_OFFSET_1         4
#define MK_C_INTERVAL_1      16
#define MK_C_OFFSET_2        32
#define MK_C_INTERVAL_2      16

// AUDIO
#ifdef AUDIO_ENABLE
#	define DEFAULT_LAYER_SONGS { \
		SONG(QWERTY_SOUND ), \
		SONG(DVORAK_SOUND ), \
		SONG(COLEMAK_SOUND), \
		SONG(COLEMAK_SOUND), \
		SONG(COLEMAK_SOUND), \
		SONG(WORKMAN_SOUND)  \
	}
#endif
