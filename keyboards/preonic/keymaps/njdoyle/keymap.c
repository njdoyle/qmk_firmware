#include "njdoyle.h"

#define LAYOUT_preonic_grid_kc( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b \
) { \
    { KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05 }, \
    { KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15 }, \
    { KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25 }, \
    { KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35 }, \
    { KC_##k06, KC_##k07, KC_##k08, KC_##k09, KC_##k0a, KC_##k0b }, \
    { KC_##k16, KC_##k17, KC_##k18, KC_##k19, KC_##k1a, KC_##k1b }, \
    { KC_##k26, KC_##k27, KC_##k28, KC_##k29, KC_##k2a, KC_##k2b }, \
    { KC_##k36, KC_##k37, KC_##k38, KC_##k39, KC_##k3a, KC_##k3b }, \
    { KC_##k40, KC_##k41, KC_##k42, KC_##k49, KC_##k4a, KC_##k4b }, \
    { KC_##k46, KC_##k47, KC_##k48, KC_##k43, KC_##k44, KC_##k45 } \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	NJDOYLE_LAYOUT_BASE,

	// LOWER - Mostly numbers and their shifted symbol counterparts
	[_LOWER] = LAYOUT_preonic_grid_kc(
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, EXLM, AT  , HASH, DLR , PERC, CIRC, AMPR, ASTR, BSLS, PIPE, ____,
		____, 1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 0   , ____,
		LALT, PLUS, MINS, ASTR, SLSH, UNDS, COLN, EQL , COMM, DOT , SLSH, DEL ,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
	),

	// RAISE - Mostly paired enclosures and common programming symbols
	[_RAISE] = LAYOUT_preonic_grid_kc(
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, XXXX, EXLM, ASTR, PLUS, XXXX, XXXX, MINS, EQL , UNDS, XXXX, ____,
		____, LBRC, RBRC, LCBR, RCBR, DLR , HASH, LPRN, RPRN, LT  , GT  , ____,
		LALT, XXXX, XXXX, GRV , QUOT, XXXX, XXXX, DQUO, TILD, XXXX, XXXX, DEL ,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
	),

	// NAVIGATION
	[_NAVIGATION] = LAYOUT_preonic_grid(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, XXXXXXX, XXXXXXX, DE_LEFT, DE_RGHT, KC_HOME, XXXXXXX, TB_LEFT, TB_RGHT, TB_NEW , KC_PGUP, _______,
		_______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_END , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, _______,
		KC_CAPS, DE_MENU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BR_BACK, BR_FRWD, XXXXXXX, BR_TOOL, KC_CAPS,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	),

	// FUNCTION - F keys, media controls, default layout selection
	[_FUNCTION] = LAYOUT_preonic_grid(
		NJM_1  , NJM_2  , NJM_3  , NJM_4  , NJM_5  , NJM_6  , NJM_7  , NJM_8  , NJM_9  , NJM_0  , _______, RGB_TOG,
		KC_LGUI, KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX, D_QWRTY, D_DVRAK, D_COLEM, D_C_DH , D_C_DHM, D_WORKM,
		KC_LCTL, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_LSFT, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		_______, _______, _______, _______, _______, KC_MPLY, KC_MUTE, _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD
	)
};


// UNDERGLOW

#define COLOUR_IDLE       HSV_RED
#define COLOUR_LOWER      HSV_ORANGE
#define COLOUR_RAISE      HSV_PURPLE
#define COLOUR_NAVIGATION HSV_CYAN
#define COLOUR_FUNCTION   HSV_PINK
#define COLOUR_CAPS       HSV_WHITE

const rgblight_segment_t PROGMEM colour_layer_idle      [] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, COLOUR_IDLE      } );
const rgblight_segment_t PROGMEM colour_layer_lower     [] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, COLOUR_LOWER     } );
const rgblight_segment_t PROGMEM colour_layer_raise     [] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, COLOUR_RAISE     } );
const rgblight_segment_t PROGMEM colour_layer_navigation[] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, COLOUR_NAVIGATION} );
const rgblight_segment_t PROGMEM colour_layer_function  [] = RGBLIGHT_LAYER_SEGMENTS( {0, 9, COLOUR_FUNCTION  } );
const rgblight_segment_t PROGMEM colour_layer_capslock  [] = RGBLIGHT_LAYER_SEGMENTS( {3, 1, COLOUR_CAPS      } );

const rgblight_segment_t* const PROGMEM colour_layers[] =
	RGBLIGHT_LAYERS_LIST(
		colour_layer_idle      ,
		colour_layer_lower     ,
		colour_layer_raise     ,
		colour_layer_navigation,
		colour_layer_function  ,
		colour_layer_capslock
	);


// LAYERS

layer_state_t layer_state_set_user(layer_state_t state) {
	layer_state_t newState = update_tri_layer_state(state, _LOWER, _RAISE, _NAVIGATION);
	rgblight_set_layer_state(1, layer_state_cmp(newState, _LOWER     ));
	rgblight_set_layer_state(2, layer_state_cmp(newState, _RAISE     ));
	rgblight_set_layer_state(3, layer_state_cmp(newState, _NAVIGATION));
	rgblight_set_layer_state(4, layer_state_cmp(newState, _FUNCTION  ));
	return newState;
}


// INITIALIZATION
void keyboard_post_init_user(void) {
	rgblight_layers = colour_layers;
	rgblight_set_layer_state(0, true);
}

bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(5, led_state.caps_lock);
	return true;
}
