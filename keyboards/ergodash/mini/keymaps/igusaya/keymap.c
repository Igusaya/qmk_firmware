#include QMK_KEYBOARD_H

/*
 * macOS 用キーマップ (US 配列)
 * 前提: macOS 側でこのキーボードの種類が「ANSI(US)」になっていること
 *       (システム設定 > キーボード > キーボードの種類を変更...)
 * 英数/かな は KC_LANG2/KC_LANG1 なのでキーボードの種類に関係なく動作する
 */

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  M_YEN,    // ¥ (Option+Y)。Shift と同時押しなら | (JIS の ¥ キーと同じ動き)
};

// Fillers to make layering more clear
#define _______ KC_TRNS

// macOS 用キー
#define M_EISU  KC_LANG2              // 英数
#define M_KANA  KC_LANG1              // かな
#define M_FQUIT LGUI(LALT(KC_ESC))    // 強制終了 (Windows の Ctrl+Alt+Del の代わり)
#define M_COPY  LGUI(KC_C)
#define M_PAST  LGUI(KC_V)
#define M_CUT   LGUI(KC_X)
#define M_UNDO  LGUI(KC_Z)
#define M_REDO  LGUI(LSFT(KC_Z))
#define M_SELAL LGUI(KC_A)
#define M_SAVE  LGUI(KC_S)
#define M_GREP  LGUI(KC_G)
#define M_FIND  LGUI(KC_F)
#define M_RESH  LGUI(KC_R)
#define M_TABR  LCTL(KC_TAB)          // 次のタブ
#define M_TABL  LCTL(LSFT(KC_TAB))    // 前のタブ
#define M_DESK  KC_F11                // デスクトップを表示
#define M_MWIN  LCTL(KC_UP)           // Mission Control

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  ¥ | |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Caps |                    | FQuit|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------.      ,------+------+------+------+------+------+-------------|
   * |  Cmd |  Opt | Ctrl |   | 英数 |  | Lower| Space|Delete|      | Bksp | Enter| Raise|  | かな |   |  Cmd |  Opt | Ctrl |
   * ,-------------------------------------------------------.      ,-------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_YEN,   \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_CAPS,                        M_FQUIT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LGUI, KC_LALT, KC_LCTL, M_EISU,           LOWER,   KC_SPC , KC_DEL,        KC_BSPC,KC_ENT , RAISE,            M_KANA,  KC_RGUI, KC_RALT, KC_RCTL  \
  ),

  /* Lower
   * ,------------------------------------------------.                    ,------------------------------------------------.
   * |  ESC |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------.      ,------+------+------+------+------+------+-------------|
   * |  Cmd |  F11 |  F12 | 英数 |||||||| Lower| Space|Delete|      | Bksp | Enter| Raise|||||||| Home |PageUp|PageDn|  End |
   * ,-------------------------------------------------------.      ,-------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,  KC_PERC,   KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_LCBR,                        KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_COLN, KC_DQT , \
    KC_LSFT,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
    KC_LGUI, KC_F11,  KC_F12,  M_EISU,             LOWER,   KC_SPC , KC_DEL,        KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGUP, KC_PGDN , KC_END   \
  ),

  /* Raise
  * ,------------------------------------------------.                    ,------------------------------------------------.
  * |  ESC |   1  |   2  |   3  |   4  |   5  |   -  |                    |   +  |   6  |   7  |   8  |   9  |   0  |  \   |
  * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
  * | MCtl | SELAL| SAVE | DESK | FIND | GREP | RESH |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
  * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
  * | Shift| UNDO | CUT  | COPY | PAST | REDO | Space|                    | Enter|   N  |   M  |   <  |   >  |   /  | Shift|
  * |-------------+------+------+------+------+------+------.      ,------+------+------+------+------+------+-------------|
  * |  Cmd | TABL | TABR |   | 英数 |  | Lower| Space|Delete|      | Bksp | Enter| Raise|||||||| Home |PageUp|PageDn|  End |
  * ,-------------------------------------------------------.      ,-------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
     KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5, KC_MINS,                         KC_PLUS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
     M_MWIN, M_SELAL, M_SAVE, M_DESK, M_FIND, M_GREP,  M_RESH,                         KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_COLN, KC_DQT , \
    KC_LSFT,  M_UNDO,  M_CUT, M_COPY, M_PAST, M_REDO,  KC_SPC,                         KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_SLSH, KC_RSFT, \
    KC_LGUI,  M_TABL, M_TABR, M_EISU,         LOWER,   KC_SPC,  KC_DEL,        KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGUP, KC_PGDN, KC_END   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_YEN:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          tap_code(KC_BSLS);         // Shift + \ = |
        } else {
          tap_code16(LALT(KC_Y));    // Option + Y = ¥
        }
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
