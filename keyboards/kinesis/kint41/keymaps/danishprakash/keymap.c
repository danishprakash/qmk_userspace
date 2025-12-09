#include QMK_KEYBOARD_H

/*
 * Kinesis Advantage 2 (kint41) Keymap
 *
 * Layer 0: Base QWERTY
 * Layer 1: Navigation layer (activated by holding Tab or Esc)
 * Layer 2: Numpad layer
 *
 * Special features:
 * - LT(1,KC_TAB): Tap for Tab, hold for Layer 1
 * - LT(1,KC_ESC): Tap for Esc, hold for Layer 1
 * - LSFT_T(KC_LCBR): Tap for {, hold for Left Shift
 * - RSFT_T(KC_RCBR): Tap for }, hold for Right Shift
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: Base QWERTY Layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │       │ F9  │ F10 │ F11 │ F12 │PrtSc│ScrLk│Pause│  -  │RESET│
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     *
     * ┌─────┬─────┐                                                                             ┌─────┬─────┐
     * │  =  │  1  │ 2   │ 3   │ 4   │ 5   │                                         │ 6   │ 7   │ 8   │ 9   │  0  │  -  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                                         ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │Tab/L│  Q  │ W   │ E   │ R   │ T   │                                         │ Y   │ U   │ I   │ O   │ P   │  \  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                                         ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │Ctrl │  A  │ S   │ D   │ F   │ G   │                                         │ H   │ J   │ K   │ L   │  ;  │  '  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                                         ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │Shft/│  Z  │ X   │ C   │ V   │ B   │                                         │ N   │ M   │ ,   │ .   │ /   │Shft/│
     * │ {   │     │     │     │     │     │                                         │     │     │     │     │     │ }   │
     * └─────┴─────┼─────┼─────┼─────┼─────┘                                         └─────┼─────┼─────┼─────┼─────┴─────┘
     *             │  `  │ Ins │Left │Right│                                               │ Up  │Down │  [  │  ]  │
     *             └─────┴─────┴─────┴─────┘                                               └─────┴─────┴─────┴─────┘
     *                                     ┌─────┬─────┐                   ┌─────┬─────┐
     *                                     │Esc/L│ Alt │                   │RGui │Caps │
     *                                     ├─────┼─────┤                   ├─────┼─────┤
     *                                     │     │Home │                   │PgUp │     │
     *                                ┌────┼─────┼─────┤                   ├─────┼─────┼────┐
     *                                │    │     │End  │                   │PgDn │     │    │
     *                                │BkSp│Space│ Ent │                   │ Ent │LGui │    │
     *                                │    │     │     │                   │     │     │    │
     *                                └────┴─────┴─────┘                   └─────┴─────┴────┘
     */
    [0] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,           KC_F5,   KC_F6,   KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS, KC_NO,   QK_BOOT,
        KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,            KC_5,                                                                    KC_6,    KC_7,           KC_8,    KC_9,    KC_0,    KC_MINS,
        LT(1,KC_TAB), KC_Q, KC_W,   KC_E,    KC_R,            KC_T,                                                                    KC_Y,    KC_U,           KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                                    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        LSFT_T(KC_LCBR), KC_Z, KC_X, KC_C,   KC_V,            KC_B,                                                                    KC_N,    KC_M,           KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_RCBR),
                  KC_GRV,  KC_INS,  KC_LEFT, LT(1, KC_RGHT),                                                                                    KC_UP,          KC_DOWN, KC_LBRC, KC_RBRC,
                                                                    KC_ESC, KC_LALT,                        KC_RGUI, KC_CAPS,
                                                                    KC_HOME,                               KC_PGUP,
                                             KC_ENT, KC_LGUI,       KC_END,                                KC_PGDN, KC_BSPC,  KC_SPC
    ),

    /* Layer 1: Navigation Layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │     │     │     │     │       │     │     │     │     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     *
     * ┌─────┬─────┐                                                                             ┌─────┬─────┐
     * │     │     │     │     │     │     │                                         │     │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                                         ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │                                         │     │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                                         ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │                                         │Left │Down │ Up  │Right│     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤                                         ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │                                         │     │     │     │     │     │     │
     * │     │     │     │     │     │     │                                         │     │     │     │     │     │     │
     * └─────┴─────┼─────┼─────┼─────┼─────┘                                         └─────┼─────┼─────┼─────┼─────┴─────┘
     * │     │     │     │     │                                               │     │     │     │     │
     *             └─────┴─────┴─────┴─────┘                                               └─────┴─────┴─────┴─────┘
     *                                     ┌─────┬─────┐                   ┌─────┬─────┐
     *                                     │     │     │                   │     │     │
     *                                     ├─────┼─────┤                   ├─────┼─────┤
     *                                     │     │     │                   │     │     │
     *                                ┌────┼─────┼─────┤                   ├─────┼─────┼────┐
     *                                │    │     │     │                   │     │     │    │
     *                                │    │     │     │                   │     │     │    │
     *                                │    │     │     │                   │     │     │    │
     *                                └────┴─────┴─────┘                   └─────┴─────┴────┘
     *
     * Navigation layer activated by holding Tab or Esc
     * - Arrow keys on right hand home row (HJKL positions)
     */
    [1] = LAYOUT(
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                       KC_NO,   KC_NO,                                         KC_NO,   KC_NO,
                                                                KC_NO,                                         KC_NO,
                                             KC_NO,   KC_NO,   KC_NO,                                         KC_NO,   KC_NO,   KC_NO
    ),

    /* Layer 2: Numpad Layer
     * Number row becomes numpad layout
     */
    [2] = LAYOUT(
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_R,   KC_NO,                                                                   KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                   KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
        KC_LSFT,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                   KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                       KC_NO,   KC_NO,                                         KC_NO,   KC_NO,
                                                                KC_NO,                                         KC_NO,
                                             KC_NO,   KC_TRNS, KC_NO,                                         KC_NO,   KC_NO,   KC_NO
    )
};

// Use df/jk as HRMs to trigger the Ctrl+B (TMUX prefix)
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

// Easier access to escape key f+j > Esc
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};

// My two thumbs rest respectively on  KC_ENT (left) and KC_SPC (right)
// Use this combo to trigger rofi which is configured on MOD+KC_SPC.
// I dont' want to change my i3 mod and this is a close second in terms of usability.
const uint16_t PROGMEM ENT_SPC_combo[] = {KC_ENT, KC_SPC, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_combo, LCTL(KC_B)),
    COMBO(df_combo, LCTL(KC_B)),
    COMBO(fj_combo, KC_ESC),
    COMBO(ENT_SPC_combo, LGUI(KC_SPC))
};
uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);
