/*
 * Modified from the ordinary layout (credit below), v6.9
 *
 * Updated to remove the special mod shifts, which are now implemented in QMK
 * directly <3
 *
 * Other updates to my preferences (@cscorley)
 */

/*
 * The Ordinary Layout for the Ergodox EZ keyboard, v4.20
 *
 * Modifications from default by Nicholas Keene ergodoxez@nicholaskeene.com
 *
 * No rights reserved. This software is in the public domain.
 * Credit me if you are friendly but if you're a jerk don't bother.
 * If you use or modify this layout I would love to hear from you.
 *
 * Details: readme.md
 *          https://github.com/nrrkeene/qmk_firmware/tree/master/keyboards/ergodox/keymaps/ordinary
 */

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "action_util.h"
#include "debug.h"
#include "ergodox_ez.h"
#include "led.h"
#include "mousekey.h"
#include "version.h"

#define _ KC_TRNS
#define __ KC_TRNS
#define ___ KC_TRNS
#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define _______ KC_TRNS

// Layers
enum {
    BASE = 0,
    SYMB,
    MDIA,
    SPEC
};

// Layer shift/tap keys
#define TAB_MDIA LT(MDIA, KC_TAB)
#define EQL_SPEC LT(SPEC, KC_EQL)
#define BSL_MDIA LT(MDIA, KC_BSLS)
#define QUOT_SYM LT(SYMB, KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/******* Base Layer ****************************************************************************************************
 *
 * ,------------------------------------------------------.       ,------------------------------------------------------.
 * | Escape     |   1  |   2  |   3  |   4  |   5  | `~Sp |       |   6  |   7  |   8  |   9  |   0  |  -   | =+ Special |
 * |------------+------+------+------+------+-------------|       |------+------+------+------+------+------+------------|
 * | Tab  Media |   Q  |   W  |   E  |   R  |   T  |   [  |       |  ]   |   Y  |   U  |   I  |   O  |   P  | \|   Media |
 * |------------+------+------+------+------+------|      |       |      |------+------+------+------+------+------------|
 * | LCtrl      |   A  |   S  |   D  |   F  |   G  |------|       |------|   H  |   J  |   K  |   L  |  ;   | '"  Symbol |
 * |------------+------+------+------+------+------|   {  |       |  }   |------+------+------+------+------+------------|
 * | (   LShift |   Z  |   X  |   C  |   V  |   B  |      |       |      |   N  |   M  |   ,  |   .  |  /   | )   RShift |
 * `------------+------+------+------+------+-------------'       `-------------+------+------+------+------+------------'
 *      | Symbol| Meh  |Hyper | LAlt | LGui |                                   | Left | Down | Up   | Right| RCtrl |
 *      `-----------------------------------'                                   `-----------------------------------'
 *                                          ,-------------.       ,-------------.
 *                                          | Home | End  |       | RGui | Meh  |
 *                                   ,------|------|------|       |------+------+------.
 *                                   |      |      | PgUp |       | Hyper|      |      |
 *                                   |Backsp| Del  |------|       |------| Enter| Space|
 *                                   |      |      | PgDn |       | Enter|      |      |
 *                                   `--------------------'       `--------------------'
 *
 */
[BASE] = KEYMAP(

// left hand
KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_GRV,
TAB_MDIA, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,
KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LCBR,
MO(SYMB), KC_MEH, KC_HYPR, KC_LALT, KC_LGUI,
                                                     KC_HOME, KC_END,
                                                              KC_PGUP,
                                             KC_BSPC, KC_DEL, KC_PGDN,

                                                                  // right hand
                 KC_6, KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS, EQL_SPEC,
              KC_RBRC, KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    BSL_MDIA,
                       KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, QUOT_SYM,
              KC_RCBR, KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSPC,
                                KC_LEFT,  KC_DOWN,   KC_UP,  KC_RIGHT, KC_RCTL,
        KC_RGUI,  KC_MEH,
        KC_HYPR,
        KC_ENT,   KC_ENT,  KC_SPC
),

/******* Symbols Layer *************************************************************************************************
 *
 * ,-----------------------------------------------------.       ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  | Esc  |       |  F6  |  F7  |  F8  |  F9  |  F10 |   -  |          |
 * |-----------+------+------+------+------+-------------|       |------+------+------+------+------+------+-----------|
 * |           |   !  |   @  |   {  |   }  |   &  |  <   |       |  >   |   |  |   7  |   8  |   9  |   /  |           |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * |           |   #  |   $  |   (  |   )  |   `  |------|       |------|   /  |   4  |   5  |   6  |   *  |           |
 * |-----------+------+------+------+------+------| Tab  |       | Shift|------+------+------+------+------+-----------|
 * |           |   %  |   ^  |   [  |   ]  |   ~  |      |       |  -Tab|   \  |   1  |   2  |   3  |   -  |           |
 * `-----------+------+------+------+------+-------------'       `-------------+------+------+------+------+-----------'
 *     | LCtrl | Meh  |Hyper | LAlt | LGui |                                   |   0  |   .  |   =  |   +  |  Ent  |
 *     `-----------------------------------'                                   `-----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         | Left | Right|       | Home | End  |
 *                                  ,------|------|------|       |------+------+------.
 *                                  |      |      |  Up  |       | PgUp |      |      |
 *                                  |Space |Enter |------|       |------|BackSp| Del  |
 *                                  |      |      | Down |       | PgDn |      |      |
 *                                  `--------------------'       `--------------------'
 */
[SYMB] = KEYMAP(

// left hand
TO(BASE) ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,_____
,_____   ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_AMPR ,LSFT(KC_COMM)
,_____   ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,KC_GRV
,_____   ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,KC_TILD ,KC_TAB
,_____   ,KC_MEH  ,KC_HYPR ,KC_LALT ,KC_LGUI
                                             ,KC_LEFT ,KC_RGHT
                                                      ,KC_UP
                                    ,KC_SPC  ,KC_ENT  ,KC_DOWN
                                                                 // right hand
                                                                 ,KC_F6   ,KC_F7 ,KC_F8  ,KC_F9 ,KC_F10  ,KC_MINS     ,_____
                                                                 ,LSFT(KC_DOT),KC_PIPE ,KC_7  ,KC_8   ,KC_9  ,KC_SLSH ,_____
                                                                              ,KC_SLSH ,KC_4  ,KC_5   ,KC_6  ,KC_ASTR ,_____
                                                                 ,LSFT(KC_TAB),KC_BSLS ,KC_1  ,KC_2   ,KC_3  ,KC_MINS ,_____
                                                                                       ,KC_0  ,KC_DOT ,KC_EQL,KC_PLUS ,KC_ENT
                                                                 ,KC_HOME     ,KC_END
                                                                 ,KC_PGUP
                                                                 ,KC_PGDN     ,KC_BSPC ,KC_DEL

),

/******* Media Layer *******************************************************************************************************
 *
 * ,---------------------------------------------------------------.    ,---------------------------------------------------------------.
 * |      |   F11   |   F12   |   F13   |   F14   |   F15   | Esc  |    | F16  |   F17   |   F18   |   F19   |   F20   |         |      |
 * |------+---------+---------+---------+---------+----------------|    |------+---------+---------+---------+---------+---------+------|
 * |      |Shut Down|         |Mouse Up |         |Volume Up|Scroll|    |Scroll|PrintScrn|   Home  |    Up   |   PgUp  |   Mail  |      |
 * |------+---------+---------+---------+---------+---------|  Up  |    |  Up  |---------+---------+---------+---------+---------+------|
 * |      |  Sleep  |MouseLeft|MouseDown|MouseRght|Volume Dn|------|    |------| Num Lock|   Left  |   Down  |   Right | MyComp  |      |
 * |------+---------+---------+---------+---------+---------|Scroll|    |Scroll|---------+---------+---------+---------+---------+------|
 * |      |         |         |MouseDown|         |  Mute   | Down |    | Down |         |   End   |   Down  |   PgDn  |         |      |
 * `------+---------+---------+---------+---------+----------------'    `----------------+---------+---------+---------+---------+------'
 *  |LCtrl|   Meh   |  MClick | LClick  |  R Click|                                      |Cmd/Insrt|Optn/Del | Hyper   |  Meh    |RCtrl|
 *  `---------------------------------------------'                                      `---------------------------------------------'
 *                                                   ,-------------.    ,-------------.
 *                                                   | Stop |Refrsh|    | Prev | Next |
 *                                            ,------|------|------|    |------+------+------.
 *                                            |Brwser|Brwser|Search|    |VolUp |      |      |
 *                                            |Back  | Fwd  |------|    |------| Stop | Play-|
 *                                            |      |      | Home |    |VolDn |      | Pause|
 *                                            `--------------------'    `--------------------'
 */
[MDIA] = KEYMAP(

// left hand
TO(BASE),KC_F11   ,KC_F12  ,KC_F13   ,KC_F14  ,KC_F15  ,_____
,_____ ,KC_POWER ,_______ ,KC_MS_U  ,_______ ,KC_VOLU ,KC_WH_U
,_____ ,KC_SLEP  ,KC_MS_L ,KC_MS_D  ,KC_MS_R ,KC_VOLD
,_____ ,KC_NO    ,_______ ,KC_MS_D  ,_______ ,KC_MUTE ,KC_WH_D
,KC_LCTL ,KC_MEH   ,KC_BTN3 ,KC_BTN1  ,KC_BTN2
                                               ,KC_WSTP ,KC_WREF
                                                        ,KC_WSCH
                                      ,KC_WBAK ,KC_NO   ,KC_WHOM
                                                                     // right hand
                                                                     ,KC_F16  ,KC_F17       ,KC_F18       ,KC_F19  ,KC_F20  ,KC_NO    ,_____
                                                                     ,KC_WH_U  ,KC_PSCR ,KC_HOME      ,KC_UP        ,KC_PGUP ,KC_MAIL ,_____
                                                                               ,KC_NLCK ,KC_LEFT      ,KC_DOWN      ,KC_RIGHT,KC_MYCM ,_____
                                                                     ,KC_WH_D  ,KC_NO   ,KC_END       ,KC_DOWN      ,KC_PGDN ,KC_NO   ,_____
                                                                                        ,GUI_T(KC_INS),ALT_T(KC_DEL),KC_HYPR ,KC_MEH  ,KC_RCTL
                                                                     ,KC_MPRV  ,KC_MNXT
                                                                     ,KC_VOLU
                                                                     ,KC_VOLD  ,KC_MSTP ,KC_MPLY

),

/******* Special Layer *****************************************************************************************************
 *
 * ,-------------------------------------------------------.    ,-------------------------------------------------------.
 * |             |  Esc |      |      |      |      |      |    |      |      |      |      |      | RESET|             |
 * |-------------+------+------+------+------+-------------|    |------+------+------+------+------+------+-------------|
 * |             |      |      |      |      |      |      |    |      |      |      |      |      | PRINT|             |
 * |-------------+------+------+------+------+------|      |    |      |------+------+------+------+------+-------------|
 * |             |      |      |      |      |      |------|    |------|      |      |      |      |      |             |
 * |-------------+------+------+------+------+------|      |    |      |------+------+------+------+------+-------------|
 * | Caps Lock   |      |      |      |      |      |      |    |      |      |      |      |      |      |             |
 * `-------------+------+------+------+------+-------------'    `-------------+------+------+------+------+-------------'
 *      |        |      |      |      |      |                                |      |      |      |      |        |
 *      `------------------------------------'                                `------------------------------------'
 *                                         ,-------------.     ,-------------.
 *                                         |      |      |     |      |      |
 *                                  ,------|------|------|     |------+------+------.
 *                                  |      |      |      |     |      |      |      |
 *                                  |      |      |------|     |------|      |      |
 *                                  |      |      |      |     |      |      |      |
 *                                  `--------------------'     `--------------------'
 */
[SPEC] = KEYMAP(
// left hand
TO(BASE) ,KC_ESC ,_____ ,_____ ,_____ ,_____ ,_____
,_____   ,______ ,_____ ,_____ ,_____ ,_____ ,_____
,_____   ,______ ,_____ ,_____ ,_____ ,_____
,KC_CAPS ,______ ,_____ ,_____ ,_____ ,_____ ,_____
,_____   ,______ ,_____ ,_____ ,_____
                                           ,_____ ,_____
                                                  ,_____
                                     ,_____,_____ ,_____
                                                             // right hand
                                                             ,_____ ,_____ ,_____ ,_____ ,_____ ,RESET   ,_____
                                                             ,_____ ,_____ ,_____ ,_____ ,_____ ,KC_PSCR ,_____
                                                                    ,_____ ,_____ ,_____ ,_____ ,_______ ,_____
                                                             ,_____ ,_____ ,_____ ,_____ ,_____ ,_______ ,_____
                                                                           ,_____ ,_____ ,_____ ,_______ ,_____
                                                             ,_____ ,_____
                                                             ,_____
                                                             ,_____ ,_____ ,_____
    )
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{
    // turn em all on if we're in a special shift
    if(layer_state & (1UL<<SPEC))
    {
        ergodox_led_all_on();
    }
    else
    {
        ergodox_led_all_off();
    }

    // shift or caps lock turns on red light
    if((keyboard_report->mods & MOD_BIT(KC_LSFT))
    || (keyboard_report->mods & MOD_BIT(KC_RSFT))
    || (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)))
    {
        ergodox_right_led_1_on();
    }
    else
    {
        ergodox_right_led_1_off();
    }

    // Symbol layer turns on green light
    if(layer_state & (1UL<<SYMB))
    {
        ergodox_right_led_2_on();
    }
    else
    {
        ergodox_right_led_2_off();
    }

    // Media layer turns on blue light
    if(layer_state & (1UL<<MDIA))
    {
        ergodox_right_led_3_on();
    }
    else
    {
        ergodox_right_led_3_off();
    }
};
