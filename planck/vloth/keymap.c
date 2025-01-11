#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define KC_SN LT(_RAISE,KC_SPACE)
#define KC_EC LT(_LOWER,KC_ENTER)

#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL LALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)

#define KC_A4 LALT_T(KC_4)
#define KC_C5 LCTL_T(KC_5)
#define KC_S6 LSFT_T(KC_6)
#define KC_QBSPC LSFT_T(KC_BSPC)
#define KC_SD RSFT_T(KC_DOWN)
#define KC_SU RCTL_T(KC_UP)
#define KC_CR RALT_T(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_GA,   KC_AS,   KC_CD,   KC_SF,   KC_G,    _______, _______, KC_H,    KC_SJ,   KC_CK,   KC_AL,   KC_GSCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    _______, _______, _______, KC_SN,   KC_QUOT, _______, _______, KC_BSPC, KC_EC,   _______, _______, _______
),

[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_AMPR, KC_ASTR, KC_TILD, KC_CIRC, _______, _______, _______, _______, _______, _______, _______,
    KC_MINS, KC_DLR,  KC_PERC, KC_EQL,  KC_PLUS, _______, _______, KC_LEFT, KC_SD,   KC_SU,   KC_CR,   KC_BSPC,
    KC_UNDS, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    _______, KC_F8,   KC_F7,   KC_F9,   _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_TAB,
    _______, KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_A4,   KC_C5,   KC_S6,   KC_QBSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______, _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif


#ifdef COMBO_ENABLE

const uint16_t PROGMEM combo_esc[] =  {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_quot[] =  {KC_L, KC_SCLN, COMBO_END};
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
  [COMBO_CAPSLOCK] = COMBO(combo_capslock, KC_CAPS),
  [COMBO_QUES] = COMBO(combo_ques, KC_QUES),

  [COMBO_LCBR] = COMBO(combo_lcbr, KC_LCBR),
  [COMBO_RCBR] = COMBO(combo_rcbr, KC_RCBR),

  [COMBO_LBRC] = COMBO(combo_lbrc, KC_LBRC),
  [COMBO_RBRC] = COMBO(combo_rbrc, KC_RBRC),

  [COMBO_LPRN] = COMBO(combo_lprn, KC_LPRN),
  [COMBO_RPRN] = COMBO(combo_rprn, KC_RPRN)
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
