#include QMK_KEYBOARD_H
#include "../../rgb.c"

enum combo_events {
  COMBO_ESC,
  COMBO_QUES,
  COMBO_CAPSLOCK,
  COMBO_QUOT,
  COMBO_LCBR,
  COMBO_RCBR,
  COMBO_LBRC,
  COMBO_RBRC,
  COMBO_LPRN,
  COMBO_RPRN
};

#define KC_SN LT(2,KC_SPACE)
#define KC_EC LT(1,KC_ENTER)
#define KC_ZL LT(RAISE,KC_0)

#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)

#define KC_GTB LGUI_T(KC_TAB)
#define KC_A4 LALT_T(KC_4)
#define KC_C5 LCTL_T(KC_5)
#define KC_S6 LSFT_T(KC_6)
#define KC_SQUOT LSFT_T(KC_QUOT)
#define KC_QBSPC LSFT_T(KC_BSPC)
#define KC_SD RSFT_T(KC_DOWN)
#define KC_SU RCTL_T(KC_UP)
#define KC_CR RALT_T(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,      KC_MUTE,     KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,
         KC_GA,  KC_AS,  KC_CD,  KC_SF,  KC_G,                   KC_H,   KC_SJ,  KC_CK,   KC_AL,  KC_GSCLN,
         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,
                              XXXXXXX,  KC_SN,                   KC_EC, XXXXXXX
    ),

    [1] = LAYOUT(
         KC_GRAVE, KC_AMPR,  KC_ASTR,  KC_TILD,  KC_CIRC,  QK_BOOT,  _______,  _______,  _______,  _______,  _______,
         KC_MINS,  KC_DLR,   KC_PERC,  KC_EQL,   KC_PLUS,            KC_LEFT,  KC_SD,    KC_SU,    KC_CR,    KC_BSPC,
         KC_UNDS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,            _______,  _______,  _______,  _______,  _______,
                                       _______,  _______,            _______,  _______
    ),

    [2] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  QK_BOOT,  _______,  KC_7,  KC_8,  KC_9,  KC_TAB,
         _______,  _______,  _______,  _______,  _______,            KC_LEFT,  KC_A4, KC_C5, KC_S6, KC_QBSPC,
         _______,  _______,  _______,  _______,  _______,            _______,  KC_1,  KC_2,  KC_3,  _______,
                                       _______,  _______,            KC_0,     _______
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

#ifdef COMBO_ENABLE

const uint16_t PROGMEM combo_esc[] =  {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_quot[] =  {KC_AL, KC_GSCLN, COMBO_END};
const uint16_t PROGMEM combo_capslock[] =  {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM combo_ques[] = {KC_COMMA, KC_DOT, COMBO_END};

const uint16_t PROGMEM combo_lcbr[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_lbrc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_lprn[] = {KC_E, KC_R, COMBO_END};

const uint16_t PROGMEM combo_rcbr[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_rbrc[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
  [COMBO_QUOT] = COMBO(combo_quot, KC_QUOT),
  [COMBO_CAPSLOCK] = COMBO(combo_capslock, KC_CAPS_LOCK),
  [COMBO_QUES] = COMBO(combo_ques, KC_QUES),

  [COMBO_LCBR] = COMBO(combo_lcbr, KC_LCBR),
  [COMBO_RCBR] = COMBO(combo_rcbr, KC_RCBR),

  [COMBO_LBRC] = COMBO(combo_lbrc, KC_LBRC),
  [COMBO_RBRC] = COMBO(combo_rbrc, KC_RBRC),

  [COMBO_LPRN] = COMBO(combo_lprn, KC_LPRN),
  [COMBO_RPRN] = COMBO(combo_rprn, KC_RPRN)
};
#endif
