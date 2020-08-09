#include QMK_KEYBOARD_H

enum layer { LAYER_MAC, LAYER_WIN, LAYER_SYM, LAYER_FNC, LAYER_ADJ };
enum macros { MC_DARR = SAFE_RANGE, MC_EARR };

#define LY_SYM MO(LAYER_SYM)
#define LY_FNC MO(LAYER_FNC)
#define LY_ADJ MO(LAYER_ADJ)

#define KY_CESC LCTL_T(KC_ESC)
#define KY_HYPR RCAG_T(KC_NO)
#define BR_BACK LGUI(KC_LBRC)
#define BR_FWRD LGUI(KC_RBRC)
#define SPTLITE LCAG(KC_SPACE)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MC_DARR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case MC_EARR:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* MAC - typing layer
     * Tap CTRL for ESC
     * Menu opens macOS Spotlight (not the default shortcut)
     * Hyper is RCAG
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------| Back  |    |Forward|------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGui | SYM  | / Space /       \Enter \  | FNC  |Hyper |Menu  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [LAYER_MAC] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        KY_CESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     BR_BACK,  BR_FWRD,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                      KC_LALT,  KC_LGUI,  LY_SYM,   KC_SPC,   KC_ENT,   LY_FNC,   KY_HYPR,  SPTLITE
    ),

    /* WIN - gaming layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LALT  |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | FNC  |Insert|LCTRL | /       /       \      \  | ADJ  |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
	[LAYER_WIN] = LAYOUT(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_LALT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                      LY_FNC,   KC_INS,   KC_LCTL,  KC_TRNS,  KC_TRNS,  LY_ADJ,   KC_TRNS,  KC_TRNS
    ),

    /* SYM - symbols/macros
     * F13-20 are mapped to different Hammerspoon/Keyboard Maestro macros per application 
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | !    | @    | #    | $    | %    |                    | ^    | &    | *    | (    | )    |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | F13  | F14  | F15  | F16  |      |-------.    ,-------| |    | _    | +    | {    | }    | ~    |
     * |------+------+------+------+------+------| =>    |    | ->    |------+------+------+------+------+------|
     * |      | F17  | F18  | F19  | F20  |      |-------|    |-------| \    | -    | =    | [    | ]    | `    |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  | ADJ  |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
	[LAYER_SYM] = LAYOUT(
        KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
        KC_TRNS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_TRNS,
        KC_TRNS,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_NO,                        KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_TILD,
        KC_TRNS,  KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_NO,    MC_EARR,  MC_DARR,  KC_BSLS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_GRV,
                                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  LY_ADJ,   KC_TRNS,  KC_TRNS
    ),

    /* FNC - function keys, arrows, numbers
     * F11 and F12 in two places to allow for all function keys to be used on left side
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      | F11  | F12  |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | 1    | 2    | 3    | 4    | 5    |                    | 6    | 7    | 8    | 9    | 0    |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | F1   | F2   | F3   | F4   | F5   |-------.    ,-------| Left | Down | Up   |Right | F11  | F12  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      | F6   | F7   | F8   | F9   | F10  |-------|    |-------| Home | PgDn | PgUp | End  |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      | ADJ  | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
	[LAYER_FNC] = LAYOUT(
        KC_TRNS,  KC_F11,   KC_F12,   KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
        KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
        KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_F12,
        KC_NO,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_NO,    KC_NO,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,    KC_NO,
                                      KC_TRNS,  KC_TRNS,  LY_ADJ,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /* ADJ - adjustment stuff
     * Select the default layer here
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      | Play |VolUp | Stop | BrUp |                    |EEPROM|Reset |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      | Prev |VolDn | Next | BrDn |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------| WIN   |    | MAC   |------+------+------+------+------+------|
     * |      |      |      | Mute |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
	[LAYER_ADJ] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_MPLY,  KC_VOLU,  KC_MSTP,  KC_BRIU,                      EEP_RST,  RESET,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_MPRV,  KC_VOLD,  KC_MNXT,  KC_BRID,                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_MUTE,  KC_NO,    KC_NO,    DF(1),    DF(0),    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
    )
};
// clang-format on
