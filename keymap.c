#include "string.h"
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

extern uint8_t is_master;

enum layouts {
  _QWERTY = 0,
  _WORKMAN,
  _MAC,
  _MACWORK,
  _CS,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  MAC,
  MACWORK,
  CS,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,---------------------ss-------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LGUI_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, JP_COLN, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  LCTL_T(JP_MHEN),   KC_SPC,  LOWER,      RAISE,  KC_ENT, LALT_T(JP_HENK) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_WORKMAN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                         KC_J,    KC_F,    KC_U,    KC_P, KC_MINS,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LGUI_T(KC_TAB), KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                         KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT,   KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  LCTL_T(JP_MHEN),   KC_SPC,  LOWER,      RAISE,  KC_ENT, LALT_T(JP_HENK) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MAC] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LCTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, JP_COLN, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 LGUI_T(JP_MEISU),   KC_SPC,  LOWER,      RAISE,  KC_ENT, LALT_T(JP_MKANA) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MACWORK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                         KC_J,    KC_F,    KC_U,    KC_P, JP_COLN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  LCTL_T(KC_TAB), KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                         KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT,   KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 LGUI_T(JP_MEISU),   KC_SPC,  LOWER,      RAISE,  KC_ENT, LALT_T(JP_MKANA) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_CS] = LAYOUT( \
  //,---------------------ss-------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, JP_COLN, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT,   KC_1,    KC_2,    KC_3,    KC_4,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTRL,   KC_SPC,   KC_V,     QWERTY,  KC_ENT, KC_LGUI \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT, KC_LEFT,   KC_UP, KC_DOWN,KC_RIGHT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_SPC,   LOWER,      RAISE,  KC_ENT, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,  JP_GRV, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      JP_TILD,  JP_EQL, JP_PLUS, JP_ASTR,   JP_AT, JP_CIRC,                      JP_LCBR, JP_LBRC, JP_LPRN, JP_QUOT, JP_SCLN, JP_UNDS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_LT,   KC_GT, JP_COMM,  JP_DOT, JP_PIPE,                      JP_RCBR, JP_RBRC, JP_RPRN,  JP_DQT, JP_BSLS, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_SPC,   LOWER,      RAISE,  KC_ENT, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  QWERTY, WORKMAN,     MAC, MACWORK,      CS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            RESET, XXXXXXX,   LOWER,      RAISE, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};

char keylog[18];
const char code_to_name[83][18] = {
    "Undef", "Error", "Fail", "EUndef", "A", "B", "C", "D", "E", "F",
    "G", "H", "I", "J", "K", "L", "M", "N", "O", "P",
    "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "Enter", "Esc", "BSpace", "Tab", "Space", "-", "=", "[", "]", "\\",
    "~", ";", "'", "Accent", ",", ".", "/", "CapsL", "F1", "F2",
    "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12",
    "PScr", "ScrL", "Pause", "Insert", "Home", "PageU", "Delete", "End", "PageD", "Right",
    "Left", "Down", "Up"};
void set_keylog(uint16_t keycode, keyrecord_t *record) {
  if (keycode < 83) {
    strcpy(keylog, code_to_name[keycode]);
  } else {
    sprintf(keylog, "KC_%d", keycode);
  }
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void check_adjust(void) {
  if (IS_LAYER_ON(_LOWER) && IS_LAYER_ON(_RAISE)) {
    layer_on(_ADJUST);
  } else {
    layer_off(_ADJUST);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1 << _QWERTY);
      }
      return false;
    case WORKMAN:
      if (record->event.pressed) {
        persistent_default_layer_set(1 << _WORKMAN);
      }
      return false;
    case MAC:
      if (record->event.pressed) {
        persistent_default_layer_set(1 << _MAC);
      }
      return false;
    case MACWORK:
      if (record->event.pressed) {
        persistent_default_layer_set(1 << _MACWORK);
      }
      return false;
    case CS:
      if (record->event.pressed) {
        persistent_default_layer_set(1 << _CS);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        check_adjust();
      } else {
        layer_off(_LOWER);
        check_adjust();
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        check_adjust();
      } else {
        layer_off(_RAISE);
        check_adjust();
      }
      return false;
  }
  return true;
}

void matrix_init_user(void) {
  iota_gfx_init(!has_usb());   // turns on the display
}

void matrix_scan_user(void) {
   iota_gfx_task();
}

char windows_logo[2][3] = {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}};
char mac_logo[2][3] = {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}};
void write_os(struct CharacterMatrix *matrix) {
  matrix->cursor = &matrix->display[0][0];
  switch (eeconfig_read_default_layer()) {
    case 1 << _QWERTY:
    case 1 << _WORKMAN:
      matrix_write(matrix, windows_logo[0]);
      matrix->cursor = &matrix->display[1][0];
      matrix_write(matrix, windows_logo[1]);
    break;
    case 1 << _MAC:
    case 1 << _MACWORK:
      matrix_write(matrix, mac_logo[0]);
      matrix->cursor = &matrix->display[1][0];
      matrix_write(matrix, mac_logo[1]);
    break;
  }
}

void write_layout(struct CharacterMatrix *matrix) {
  matrix->cursor = &matrix->display[0][3];
  switch (eeconfig_read_default_layer()) {
    case 1 << _QWERTY:
    case 1 << _MAC:
      matrix_write(matrix, "QWERTY");
      break;
    case 1 << _WORKMAN:
    case 1 << _MACWORK:
      matrix_write(matrix, "WORKMAN");
      break;
  }
}

void write_keylog(struct CharacterMatrix *matrix) {
  matrix->cursor = &matrix->display[1][3];
  matrix_write(matrix, keylog);
}

char thinking_face[2][3] = {{0xde, 0xdf, 0}, {0xfe, 0xff, 0}};
void write_thinking_face(struct CharacterMatrix *matrix) {
  matrix->cursor = &matrix->display[2][19];
  matrix_write(matrix, thinking_face[0]);
  matrix->cursor = &matrix->display[3][19];
  matrix_write(matrix, thinking_face[1]);
}

static char logo[] = {
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4,
  0};

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    write_os(matrix);
    write_layout(matrix);
    write_keylog(matrix);
  } else {
    matrix_write(matrix, logo);
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}