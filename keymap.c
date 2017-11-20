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

// Layers
enum {
    BASE = 0,
    SYMB,
    MDIA,
    SPEC
};

enum {
    LSymb, // left symbol-shift key
    LMdia, // left media-shift key
    LSpec, // left special-shift key
    RSymb, // right symbol-shift key
    RMdia, // right media-shift key
    RSpec, // right special-shift key

    MUL,   // mouse up left
    MUR,   // mouse up right
    MDL,   // mouse down left
    MDR   // mouse down right
};

enum {
    TD_SPECIAL,
    TD_MEDIA,
    TD_SYMBOL
};

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
KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5, F(LSpec),
M(LMdia),   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,
KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
KC_LSPO,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, LSFT(KC_LBRC),
M(LSymb), KC_MEH, KC_HYPR, KC_LALT, KC_LGUI,
                                                     KC_HOME, KC_END,
                                                              KC_PGUP,
                                             KC_BSPC, KC_DEL, KC_PGDN,

                                                                  // right hand
        KC_6,          KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS,  F(RSpec),
        KC_RBRC,       KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     F(RMdia),
                       KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  F(RSymb),
        LSFT(KC_RBRC), KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSPC,
                                KC_LEFT,  KC_DOWN,   KC_UP,  KC_RIGHT, KC_RCTL,
        KC_RGUI,  KC_MEH,
        KC_HYPR,
        KC_ENT,   KC_ENT,  KC_SPC

//,KC_RGUI,KC_RALT,KC_HYPR ,KC_MEH   ,KC_RCTL,
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
 _____ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,_____
,_____ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_AMPR ,LSFT(KC_COMM)
,_____ ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,KC_GRV
,_____ ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,KC_TILD ,KC_TAB
,_____ ,KC_MEH  ,KC_HYPR ,KC_LALT ,KC_LGUI
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
 * |      |   F11   |   F12   |   F13   |   F14   |   F15   | Esc  |    | F16  |   F17   |   F18   |   F19   |   F20   |      |      |
 * |------+---------+---------+---------+---------+----------------|    |------+---------+---------+---------+---------+---------+------|
 * |      |Shut Down|MouseUpLf|Mouse Up |MouseUpRg|Volume Up|Scroll|    |Scroll|PrintScrn|   Home  |    Up   |   PgUp  |   Mail  |      |
 * |------+---------+---------+---------+---------+---------|  Up  |    |  Up  |---------+---------+---------+---------+---------+------|
 * |      |  Sleep  |MouseLeft|MouseDown|MouseRght|Volume Dn|------|    |------| Num Lock|   Left  |   Down  |   Right | MyComp  |      |
 * |------+---------+---------+---------+---------+---------|Scroll|    |Scroll|---------+---------+---------+---------+---------+------|
 * |      |         |MouseDnLf|MouseDown|MouseDnRg|  Mute   | Down |    | Down |         |   End   |   Down  |   PgDn  |         |      |
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
 _____ ,KC_F11   ,KC_F12  ,KC_F13   ,KC_F14  ,KC_F15  ,_____
,_____ ,KC_POWER ,M(MUL)  ,KC_MS_U  ,M(MUR)  ,KC_VOLU ,KC_WH_U
,_____ ,KC_SLEP  ,KC_MS_L ,KC_MS_D  ,KC_MS_R ,KC_VOLD
,_____ ,KC_NO    ,M(MDL)  ,KC_MS_D  ,M(MDR)  ,KC_MUTE ,KC_WH_D
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
 * |             |  Esc |      |      |      |      |      |    |      |      |      |      |   -  | RESET|             |
 * |-------------+------+------+------+------+-------------|    |------+------+------+------+------+------+-------------|
 * |             |      |      |      |      |      |      |    |      |      |      |      |  [   |   ]  |             |
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
 _____ ,KC_ESC  ,_____ ,_____ ,_____ ,_____ ,_____
,_____ ,_____ ,_____ ,_____ ,_____ ,_____ ,_____
,_____ ,_____ ,_____ ,_____ ,_____ ,_____
,KC_CAPS ,_____ ,_____ ,_____ ,_____ ,_____ ,_____
,_____ ,_____ ,_____ ,_____ ,_____
                                             ,_____ ,_____
                                                      ,_____
                                     ,_____,_____ ,_____
                                                             // right hand
                                                             ,_____ ,_____ ,_____ ,_____ ,KC_MINS ,RESET,_____
                                                             ,_____ ,_____ ,_____ ,_____ ,KC_LBRC ,KC_RBRC ,_____
                                                                      ,_____ ,_____ ,_____ ,_____ ,_____ ,_____
                                                             ,_____ ,_____ ,_____ ,_____ ,_____ ,_____ ,KC_CAPS
                                                                               ,_____ ,_____ ,_____ ,_____ ,_____
                                                             ,_____ ,_____
                                                             ,_____
                                                             ,_____ ,_____ ,_____
    )
};

const uint16_t PROGMEM fn_actions[] = {
     // the faux shift keys are implemented as macro taps
     [LSymb] = ACTION_MACRO_TAP(LSymb)
    ,[LMdia] = ACTION_MACRO_TAP(LMdia)
    ,[LSpec] = ACTION_MACRO_TAP(LSpec)
    ,[RSymb] = ACTION_MACRO_TAP(RSymb)
    ,[RMdia] = ACTION_MACRO_TAP(RMdia)
    ,[RSpec] = ACTION_MACRO_TAP(RSpec)
};

/*
void dance_special(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    register_code(KC_LCTL);
    register_code(KC_X);
    unregister_code(KC_X);
    unregister_code(KC_LCTL);
  }
  else
  {
    register_code(KC_LCTL);
    register_code(KC_C);
    unregister_code(KC_C);
    unregister_code(KC_LCTL);
  }

  reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPECIAL] = ACTION_TAP_DANCE_FN(),
    [TD_MEDIA] = ACTION_TAP_DANCE_FN(unredo),
    [TD_SYMBOL] = ACTION_TAP_DANCE_FN(findreplace)
};
*/

uint16_t symb_shift = 0;
uint16_t mdia_shift = 0;
uint16_t spec_shift = 0;

bool mdia_lock = false;
bool symb_lock = false;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id)
    {
        // There are two shift keys for each layer so we increment a layer_shift var when one
        // is pressed and decrement when one is released. If both are pressed at the same time
        // then the layer is locked (or unlocked). The shift counts are bound between 0 and 2
        // only because sometimes rapid pressing led to irregular events; this way the states
        // are self healing during use.

        case LSymb:
            if (record->event.pressed)
            {                                           // when the LSymb button is pressed
                if(++symb_shift > 2) mdia_shift = 2;    // increment the symb shift count, max two
                if(spec_shift) symb_lock = !symb_lock;  // if the Special layer is on, toggle the shift lock
                layer_on(SYMB);                         // in any case, turn on the Symbols layer
            }
            else
            {                                                         // when the LSymb button is released
                if(--symb_shift < 0) symb_shift = 0;                  // decrement the shift count, minimum zero
                if((!symb_shift) && (!symb_lock)) layer_off(SYMB);    // if both shifts are released and the lock is off, turn off the Symbols layer
            }
            break;

        case LMdia:
            if (record->event.pressed)
            {
                if (record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift))
                {
                    register_code(KC_TAB);
                }
                else
                {
                    if(spec_shift) mdia_lock = !mdia_lock;
                    if(++mdia_shift > 2) mdia_shift = 2;
                    layer_on(MDIA);
                }
            }
            else
            {
                if(record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift))
                {
                    unregister_code(KC_TAB);
                }
                else
                {
                    if(--mdia_shift < 0) mdia_shift = 0;
                    if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
                }
            }
            break;

        case LSpec:
            if (record->event.pressed)  // when the LSpec button is pressed
            {
                if(symb_shift) symb_lock = !symb_lock;       // if another layer button is engaged, then
                else if(mdia_shift) mdia_lock = !mdia_lock;  // lock that layer, be it caps or symb or mdia
                else if (record->tap.count && !record->tap.interrupted && (!spec_shift))
                {
                    register_code(KC_GRV);                   // otherwise, if it's an uninterrupted tap, emit a char
                }
                else
                {
                    if(++spec_shift > 2) spec_shift = 2;
                    layer_on(SPEC);                          // otherwise, turn on the Special layer
                }
            }
            else
            {
                if(record->tap.count && !record->tap.interrupted && (!spec_shift))
                {
                    unregister_code(KC_GRV);
                }
                else
                {
                    if(--spec_shift < 0) spec_shift = 0;
                    if(!spec_shift) layer_off(SPEC);
                }
            }
            break;

        case RSymb:
            if (record->event.pressed)
            {
                if (record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift))
                {
                    register_code(KC_QUOT);
                }
                else
                {
                    if(++symb_shift > 2) symb_shift = 2;
                    if(spec_shift) symb_lock = !symb_lock;
                    layer_on(SYMB);
                }
            }
            else
            {
                if(record->tap.count && (!symb_shift) && (!symb_lock) && (!spec_shift))
                {
                    unregister_code(KC_QUOT);
                }
                else
                {
                    if(--symb_shift < 0) symb_shift = 0;
                    if((!symb_shift) && (!symb_lock)) layer_off(SYMB);
                }
            }
            break;

        case RMdia:
            if (record->event.pressed)
            {
                if (record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift))
                {
                    register_code(KC_BSLS);
                }
                else
                {
                    if(++mdia_shift > 2) mdia_shift = 2;
                    if(spec_shift) mdia_lock = !mdia_lock;
                    layer_on(MDIA);
                }
            }
            else
            {
                if(record->tap.count && (!mdia_shift) && (!mdia_lock) && (!spec_shift))
                {
                    unregister_code(KC_BSLS);
                }
                else
                {
                    if(--mdia_shift < 0) mdia_shift = 0;
                    if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
                }
            }
            break;

        case RSpec:
            if (record->event.pressed)
            {
                if(symb_shift) symb_lock = !symb_lock;
                else if(mdia_shift) mdia_lock = !mdia_lock;
                else if (record->tap.count && !record->tap.interrupted && (!spec_shift))
                {
                    register_code(KC_EQL);
                }
                else
                {
                    if(++spec_shift > 2) spec_shift = 2;
                    layer_on(SPEC);
                }
            }
            else
            {
                if(record->tap.count && !record->tap.interrupted && (!spec_shift))
                {
                    unregister_code(KC_EQL);
                }
                else
                {
                    if(--spec_shift < 0) spec_shift = 0;
                    if(!spec_shift) layer_off(SPEC);
                }
            }
            break;

            // mouse diagonals

        case MUL: // mouse up left
            if (record->event.pressed)
            {
                mousekey_on(KC_MS_UP);
                mousekey_on(KC_MS_LEFT);
                mousekey_send();
            }
            else
            {
                mousekey_off(KC_MS_UP);
                mousekey_off(KC_MS_LEFT);
                mousekey_send();
            }
            break;

        case MUR: // mouse up right
            if (record->event.pressed)
            {
                mousekey_on(KC_MS_UP);
                mousekey_on(KC_MS_RIGHT);
                mousekey_send();
            }
            else
            {
                mousekey_off(KC_MS_UP);
                mousekey_off(KC_MS_RIGHT);
                mousekey_send();
            }
            break;

        case MDL: // mouse down left
            if (record->event.pressed)
            {
                mousekey_on(KC_MS_DOWN);
                mousekey_on(KC_MS_LEFT);
                mousekey_send();
            }
            else
            {
                mousekey_off(KC_MS_DOWN);
                mousekey_off(KC_MS_LEFT);
                mousekey_send();
            }
            break;

        case MDR: // mouse down right
            if (record->event.pressed)
            {
                mousekey_on(KC_MS_DOWN);
                mousekey_on(KC_MS_RIGHT);
                mousekey_send();
            }
            else
            {
                mousekey_off(KC_MS_DOWN);
                mousekey_off(KC_MS_RIGHT);
                mousekey_send();
            }
            break;

        default:
            // none
            break;
    }

    return MACRO_NONE;
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


