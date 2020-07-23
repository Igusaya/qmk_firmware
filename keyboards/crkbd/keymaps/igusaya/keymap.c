#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "keymap_igusaya.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAME 1
#define _MAC 2
#define _LOWER 3
#define _RAISE 4
#define _GAME_LOWER 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  MAC,
  LOWER,
  RAISE,
  GAME_LOWER,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define _____ KC_TRNS
#define XXXXX KC_NO
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LSMOD RGB_SMOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)
#define KC_EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERY
     * ,-------------------------------------.                            ,------------------------------------.
     * | ESC   |  Q  |  W  |  E  |  R  |  T  |                            |  Y  |  U  |  I  |  O  |  P  |  BS  |
     * |-------------------------------------|                            |------------------------------------|
     * | CTAB  |  A  |  S  |  D  |  F  |  G  |                            |  H  |  J  |  K  |  L  |  ;  |  '   |
     * |-------------------------------------|                            |------------------------------------|
     * | SHIFT |  Z  |  X  |  C  |  V  |  B  |                            |  N  |  M  |  ,  |  .  |  /  | EISU |
     * ,------------------------------------------------.       ,----------------------------------------------.
     *                           | GUI | LOWER | Space |        | Enter | RAISE | ALT |
     *                           ,----------------------.       ,---------------------.
     */

    [_QWERTY] = LAYOUT( \
          KC_ESC, KC_Q, KC_W, KC_E,    KC_R,  KC_T,                      KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC, \
        KC_CTLTB, KC_A, KC_S, KC_D,    KC_F,  KC_G,                      KC_H,  KC_J,   KC_K,    KC_L,   JP_SCLN, JP_QUOT, \
         KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,  KC_B,                      KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_EISU, \
                                    KC_LGUI, LOWER, KC_SPC,      KC_ENT, RAISE, KC_LALT                                    \
    ),

    /* GAME
     * ,-------------------------------------.                            ,------------------------------------.
     * | ESC   |  Q  |  W  |  E  |  R  |  T  |                            |  Y  |  U  |  I  |  O  |  P  |  BS  |
     * |-------------------------------------|                            |------------------------------------|
     * |  CTL  |  A  |  S  |  D  |  F  |  G  |                            |  H  |  J  |  K  |  L  |  ;  |  '   |
     * |-------------------------------------|                            |------------------------------------|
     * | SHIFT |  Z  |  X  |  C  |  V  |  B  |                            |  N  |  M  |  ,  |  .  |  /  | EISU |
     * ,------------------------------------------------.       ,----------------------------------------------.
     *                           | TAB | LOWER | Space |        | Enter | RAISE | ALT |
     *                           ,----------------------.       ,---------------------.
     */

    [_GAME] = LAYOUT( \
          KC_ESC, KC_Q, KC_W, KC_E,    KC_R,  KC_T,                      KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC, \
         KC_LCTL, KC_A, KC_S, KC_D,    KC_F,  KC_G,                      KC_H,  KC_J,   KC_K,    KC_L,   JP_SCLN, JP_QUOT, \
         KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,  KC_B,                      KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_EISU, \
                                     KC_TAB, LOWER, KC_SPC,      KC_ENT, RAISE, KC_LALT                                    \
    ),

    /* MAC
     * ,-------------------------------------.                            ,------------------------------------.
     * | ESC   |  Q  |  W  |  E  |  R  |  T  |                            |  Y  |  U  |  I  |  O  |  P  |  BS  |
     * |-------------------------------------|                            |------------------------------------|
     * | CTAB  |  A  |  S  |  D  |  F  |  G  |                            |  H  |  J  |  K  |  L  |  ;  |  '   |
     * |-------------------------------------|                            |------------------------------------|
     * | SHIFT |  Z  |  X  |  C  |  V  |  B  |                            |  N  |  M  |  ,  |  .  |  /  | EISU |
     * ,------------------------------------------------.       ,----------------------------------------------.
     *                           | GUI | LOWER | Space |        | Enter | RAISE | ALT |
     *                           ,----------------------.       ,---------------------.
     */

    [_MAC] = LAYOUT( \
          KC_ESC, KC_Q, KC_W, KC_E,    KC_R,  KC_T,                      KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC, \
         KC_LGUI, KC_A, KC_S, KC_D,    KC_F,  KC_G,                      KC_H,  KC_J,   KC_K,    KC_L,   JP_SCLN, JP_QUOT, \
         KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,  KC_B,                      KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, LGUI(KC_SPC), \
                                   KC_CTLTB,  GAME_LOWER, KC_SPC,    KC_ENT, RAISE,  KC_ALTKN                                    \
    ),

    /* LOWER
     *         ,-----------------------------------.                        ,-----------------------------------.
     *         |  ~  |  !  |  @  |  #  |  $  |  %  |                        |  ^  |  &  |  *  |  (  |  )  |  |  |
     *         |-----------------------------------|                        |-----------------------------------|
     *         |     |     |     |     |  _  |  -  |                        |  =  |  +  |     |     |  :  |  "  |
     *         |-----------------------------------|                        |-----------------------------------|
     *         |     |     |     |     |  {  |  [  |                        |  ]  |  }  |  <  |  >  |  ?  |     |
     *         ,-------------------------------------------.       ,--------------------------------------------.
     *                                 | GUI | LOWER | DEL |       |  BS  | RAISE | ALT |
     *                                 ,-------------------.       ,--------------------.
     */

  [_LOWER] = LAYOUT( \
      JP_TILD, JP_EXLM, JP_AT, JP_HASH,  JP_DLR, JP_PERC,                      JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_PIPE, \
        XXXXX,   XXXXX, XXXXX,   XXXXX, JP_UNDS, JP_MINS,                      JP_EQL,  JP_PLUS, XXXXX,   XXXXX,   JP_COLN, JP_DQT,  \
        XXXXX,   XXXXX, XXXXX,   XXXXX, JP_LCBR, JP_LBRC,                      JP_RBRC, JP_RCBR, KC_LT,   KC_GT,   KC_QUES, XXXXX,   \
                                        KC_LGUI,   LOWER, KC_DEL,     KC_BSPC, RAISE,   KC_LALT                                      \
  ),

    /* RAISE
     * ,------------------------------------.                           ,-------------------------------------.
     * |  ESC |  1  |  2  |  3  |  4  |  5  |                           |  6  |  7  |   8  |   9  |  0  |  \  |
     * |------------------------------------|                           |-------------------------------------|
     * |  F1  | F2  | F3  | F4  | F5  | F6  |                           | Left| Down|  Up  | Right| TABL| TABR|
     * |------------------------------------|                           |-------------------------------------|
     * |  F7  | F8  | F9  | F10 | F11 | F12 |                           | HOME| END |PageUp|PageDn| DEL |     |
     * ,--------------------------------------------.          ,----------------------------------------------.
     *                          | GUI | LOWER | DEL |          |  BS  | RAISE | ALT |
     *                          ,-------------------.          ,--------------------.
     */

  [_RAISE] = LAYOUT( \
      KC_ESC,   KC_1,  KC_2,  KC_3,    KC_4,   KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   JP_YEN, \
      KC_F1,   KC_F2, KC_F3, KC_F4,   KC_F5,  KC_F6,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TABL,   TABR,   \
      KC_F7,   KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                      KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_DEL, XXXXX,  \
                                   KC_LGUI,  LOWER, KC_DEL,     KC_BSPC, RAISE,   KC_LALT                                    \
  ),

    /* GAME_LOWER
     * ,------------------------------------.                           ,-------------------------------------.
     * |  ESC |  1  |  2  |  3  |  4  |  5  |                           |  6  |  7  |   8  |   9  |  0  |  \  |
     * |------------------------------------|                           |-------------------------------------|
     * |  F1  |  6  |  7  |  8  |  9  |  0  |                           | Left| Down|  Up  | Right| TABL| TABR|
     * |------------------------------------|                           |-------------------------------------|
     * |  F7  | F8  | F9  | F10 | F11 | F12 |                           | HOME| END |PageUp|PageDn| DEL |     |
     * ,--------------------------------------------.          ,----------------------------------------------.
     *                          | GUI | LOWER | DEL |          |  BS  | RAISE | ALT |
     *                          ,-------------------.          ,--------------------.
     */

  [_GAME_LOWER] = LAYOUT( \
      KC_ESC,  KC_1,  KC_2,  KC_3,    KC_4,   KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   JP_YEN, \
      KC_F1,   KC_6,  KC_7,  KC_8,    KC_9,  KC_0,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TABL,   TABR,   \
      KC_F7,   KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                      KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_DEL, XXXXX,  \
                                   KC_LGUI,  LOWER, KC_DEL,     KC_BSPC, RAISE,   KC_LALT                                    \
  ),


    /* ADJUST
     * ,------------------------------------.                           ,-------------------------------------.
     * |  DF  |GAME | MAC |     |     |     |                           |     |     |      |      |     |     |
     * |------------------------------------|                           |-------------------------------------|
     * |      |     |     |     |     |     |                           |     |     |      |      |     |     |
     * |------------------------------------|                           |-------------------------------------|
     * |      |     |     |     |     |     |                           |     |     |      |      |     |     |
     * ,--------------------------------------------.          ,----------------------------------------------.
     *                          |     |     |       |          |        |     |     |
     *                          ,-------------------.          ,--------------------.
     */

  [_ADJUST] = LAYOUT( \
    DF(_QWERTY), DF(_GAME), DF(_MAC), XXXXX, XXXXX, XXXXX,        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, \
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                 XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, \
    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                 XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, \
                              KC_TAB, LOWER, KC_SPC,      KC_ENT, RAISE, KC_LALT                                    \
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
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
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case GAME_LOWER:
      if (record->event.pressed) {
        layer_on(_GAME_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_GAME_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

