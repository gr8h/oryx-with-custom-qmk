# Layout changes

The new layout is written directly in `nd96R/keymap.c`, and the custom behaviour lives in `nd96R/custom_qmk.c`.
This file lists every key that changed from the original Oryx layout, for reference.
You don't need to make these changes in Oryx. Design and reasoning are in [the layout review](index.html).

The Mouse layer (layer 4) is unchanged. Keys not listed stay as they were.

### Layer 0 · Base

Only the thumbs and three top-row keys change. Letters, home-row mods, `:`, both Backspaces and Esc/Shift stay exactly as they are.

| Key | Before | Now |
|---|---|---|
| Number row, left inner (T/G/B) | No key | Leader (`QK_LEAD`) |
| Number row, right inner (Y/H/N) | No key | Caps Word (`CW_TOGG`) |
| Number row, right outer | Transparent | `LCTL(LGUI(LSFT(KC_4)))` · Shot clip |
| Left outer thumb | **Space**, hold → layer 2 (Symbols) | `KC_SPACE`, hold → layer 3 (Nav) |
| Left inner thumb | **Enter**, hold → layer 3 (Nav) | `LSFT(KC_ENTER)`, hold → layer 1 (Numbers) |
| Right inner thumb | **Tab**, hold → layer 1 (Numbers) | `KC_TAB`, hold → layer 2 (Symbols) |

### Layer 1 · Numbers + IDE

Right hand becomes a numpad, left hand gets the VS Code keys that used to be on Nav. Plain ⌃⌥⌘ on A S D let ⌘+digit replace the ⌘1/⌘2 tap dance.

| Key | Before | Now |
|---|---|---|
| Number row, right outer | **MyPC** | Transparent |
| Top row, left pinky (Q/A/Z) | No key | Layer Lock (`QK_LLCK`) |
| Top row, left ring (W/S/X) | No key | `LGUI(KC_BSLS)` · Split |
| Top row, left middle (E/D/C) | No key | `LGUI(LSFT(KC_E))` · Explorer |
| Top row, left index (R/F/V) | No key | `LGUI(LSFT(KC_H))` · Replace all |
| Top row, left inner (T/G/B) | **%** | `LCTL(KC_GRAVE)` · Terminal |
| Top row, right inner (Y/H/N) | **^** | `KC_PLUS` |
| Top row, right index (U/J/M) | **KP-** | `KC_7` |
| Top row, right middle (I/K/,) | **KP+** | `KC_8` |
| Top row, right ring (O/L/.) | **KP*** | `KC_9` |
| Top row, right pinky (P/:/;) | **KP/** | `KC_ASTR` |
| Home row, left pinky (Q/A/Z) | **1** | `KC_LCTL` (plain Control) |
| Home row, left ring (W/S/X) | **2** | `KC_LALT` (plain Option) |
| Home row, left middle (E/D/C) | **3** | `KC_LGUI` (plain Command) |
| Home row, left index (R/F/V) | **4** | `LGUI(LSFT(KC_F))` · Find all |
| Home row, left inner (T/G/B) | **5** | `LCTL(LSFT(KC_G))` · Git |
| Home row, right inner (Y/H/N) | **6** | `KC_MINUS` |
| Home row, right index (U/J/M) | **7** | `KC_4` |
| Home row, right middle (I/K/,) | **8** | `KC_5` |
| Home row, right ring (O/L/.) | **9** | `KC_6` |
| Home row, right pinky (P/:/;) | **0** | `KC_DOT` |
| Home row, right outer | Transparent | `KC_COLN` |
| Bottom row, left pinky (Q/A/Z) | No key | `LALT(LGUI(KC_C))` · Full path |
| Bottom row, left ring (W/S/X) | No key | `LALT(LGUI(LSFT(KC_C)))` · Rel path |
| Bottom row, left middle (E/D/C) | No key | `LGUI(LSFT(KC_P))` · Palette |
| Bottom row, left index (R/F/V) | No key | `LALT(KC_SPACE)` |
| Bottom row, left inner (T/G/B) | No key | `LGUI(KC_DOT)` · Quick fix |
| Bottom row, right index (U/J/M) | No key | `KC_1` |
| Bottom row, right middle (I/K/,) | Transparent | `KC_2` |
| Bottom row, right ring (O/L/.) | Transparent | `KC_3` |
| Bottom row, right pinky (P/:/;) | Transparent | `KC_SLASH` |
| Left inner thumb | Transparent | Transparent, hold → layer 1 (Numbers) |
| Right inner thumb | Transparent | Transparent, hold → layer 2 (Symbols) |

### Layer 2 · Symbols

Your left-hand bracket block stays. `_` and `?` swap, `->`/`=>` are macros, and the symbols that now live on Numbers (`+ - * /`, `0`) are removed.

| Key | Before | Now |
|---|---|---|
| Top row, right index (U/J/M) | **-** | Macro: types `->` |
| Top row, right middle (I/K/,) | **+** | Macro: types `=>` |
| Top row, right ring (O/L/.) | ***** | Transparent |
| Top row, right pinky (P/:/;) | **/** | Transparent |
| Home row, left pinky (Q/A/Z) | **?** | `KC_UNDS` |
| Home row, right inner (Y/H/N) | **_** | `KC_QUES` |
| Bottom row, right inner (Y/H/N) | **0** | Transparent |
| Bottom row, right index (U/J/M) | No key | Transparent |
| Left inner thumb | Transparent | Transparent, hold → layer 1 (Numbers) |
| Right inner thumb | Transparent | Transparent, hold → layer 2 (Symbols) |

### Layer 3 · Nav

VS Code panels, media and app shortcuts move off. What remains is moving and editing text, plus real Enter on the right inner thumb.

| Key | Before | Now |
|---|---|---|
| Top row, left ring (W/S/X) | **⌘\** | `LGUI(LSFT(KC_LBRC))` · Prev tab |
| Top row, left middle (E/D/C) | **⌘⇧[** | `LGUI(LSFT(KC_RBRC))` · Next tab |
| Top row, left index (R/F/V) | **⌘⇧]** | `LCTL(KC_MINUS)` · Back |
| Top row, left inner (T/G/B) | **⌘↓** | `LCTL(LSFT(KC_MINUS))` · Forward |
| Top row, right pinky (P/:/;) | **Play** | No key |
| Top row, right outer | **Stop** | Delete (`KC_DELETE`) |
| Home row, left pinky (Q/A/Z) | No key | `KC_LCTL` (plain Control) |
| Home row, left ring (W/S/X) | **⌃⇧G** | `KC_LALT` (plain Option) |
| Home row, left middle (E/D/C) | **⌘⇧F** | `KC_LGUI` (plain Command) |
| Home row, left index (R/F/V) | **⌘⇧H** | `KC_LSFT` (plain Shift) |
| Home row, left inner (T/G/B) | **⌘⇧E** | Layer Lock (`QK_LLCK`) |
| Home row, right pinky (P/:/;) | **Vol-** | No key |
| Home row, right outer | **Vol+** | No key |
| Bottom row, left outer | **⌥Spc** | Transparent |
| Bottom row, left pinky (Q/A/Z) | **⌥⌘⇧C** | `LGUI(KC_Z)` · Undo |
| Bottom row, left ring (W/S/X) | **⌥⌘C** | `LGUI(KC_X)` · Cut |
| Bottom row, left middle (E/D/C) | **⌘1/2** | `LGUI(KC_C)` · Copy |
| Bottom row, left index (R/F/V) | **⌃`** | `LGUI(KC_V)` · Paste |
| Bottom row, left inner (T/G/B) | No key | `LGUI(LSFT(KC_Z))` · Redo |
| Bottom row, right pinky (P/:/;) | **Mute** | No key |
| Bottom row, right outer | **⌘⇧4** | No key |
| Left outer thumb | Transparent | Transparent, hold → layer 3 (Nav) |
| Right inner thumb | Transparent | Enter (`KC_ENTER`) |

### Layer 5 · F-keys + media (new layer)

A new layer 5, after the Mouse layer (custom_qmk.c expects `FN_LAYER 5`). Both inner thumbs are transparent on it. No key opens it: pressing both inner thumbs together within 35 ms does (custom_qmk.c).

| Key | Before | Now |
|---|---|---|
| Number row, left outer | — | Bootloader (`QK_BOOT`) |
| Number row, right outer | — | `LCTL(LGUI(KC_Q))` (lock screen) |
| Top row, left pinky (Q/A/Z) | — | `KC_F12` |
| Top row, left ring (W/S/X) | — | `KC_F7` |
| Top row, left middle (E/D/C) | — | `KC_F8` |
| Top row, left index (R/F/V) | — | `KC_F9` |
| Top row, right inner (Y/H/N) | — | `KC_MEDIA_PLAY_PAUSE` |
| Top row, right index (U/J/M) | — | `KC_AUDIO_MUTE` |
| Top row, right middle (I/K/,) | — | `KC_AUDIO_VOL_DOWN` |
| Top row, right ring (O/L/.) | — | `KC_AUDIO_VOL_UP` |
| Home row, left pinky (Q/A/Z) | — | `KC_F11` |
| Home row, left ring (W/S/X) | — | `KC_F4` |
| Home row, left middle (E/D/C) | — | `KC_F5` |
| Home row, left index (R/F/V) | — | `KC_F6` |
| Home row, right index (U/J/M) | — | `KC_LSFT` (plain Shift) |
| Home row, right middle (I/K/,) | — | `KC_LGUI` (plain Command) |
| Home row, right ring (O/L/.) | — | `KC_LALT` (plain Option) |
| Home row, right pinky (P/:/;) | — | `KC_LCTL` (plain Control) |
| Bottom row, left pinky (Q/A/Z) | — | `KC_F10` |
| Bottom row, left ring (W/S/X) | — | `KC_F1` |
| Bottom row, left middle (E/D/C) | — | `KC_F2` |
| Bottom row, left index (R/F/V) | — | `KC_F3` |
| Bottom row, left inner (T/G/B) | — | Layer Lock (`QK_LLCK`) |
| Bottom row, right inner (Y/H/N) | — | `LGUI(LSFT(KC_4))` · Shot file |
| Bottom row, right index (U/J/M) | — | `RGB_TOG` |
| Bottom row, right middle (I/K/,) | — | `RGB_VAD` |
| Bottom row, right ring (O/L/.) | — | `RGB_VAI` |

## Lights

The colours come from `light_map` in `nd96R/custom_qmk.c`, on every layer except Mouse, which keeps its `ledmap` colours from `keymap.c`.
To change a colour, edit `light_colors` in `custom_qmk.c`, or pick colours on the Lights tab of the review page and send the "Copy settings" line.

## Editing the layout from now on

`nd96R/keymap.c` is now the source of truth. **Don't change the layout in Oryx.** The "Fetch and build layout" action still
pulls from Oryx: if Oryx's export changes, the merge step either conflicts or brings old keys back. As long as the layout in
Oryx stays untouched, the action finds no Oryx change and builds this repo's layout.

## Check after flashing

1. **Newline:** left inner thumb in Slack or a chat app adds a line without sending.
2. **Send:** hold Space and tap the right inner thumb. This should send straight away, even right after typing.
3. **Symbols:** with the right inner thumb held, `( ) [ ] < > _ ?` all type. Typing a space and then a quick `{` works.
4. **Numbers:** with the left inner thumb held, `- r` typed fast gives `-r`, not Replace all.
5. **F-keys:** pressing both inner thumbs together and tapping S gives F2. Rolling `[0]` does not open F-keys.
6. **Leader:** the Leader key then `m` types `&mut `.
7. **Caps Word:** double-tapping the left one-shot Shift starts Caps Word.
8. **Esc:** the right outer thumb still gives Esc on a tap and Shift on a hold.
9. **Lights:** Base is mostly dark with coloured thumbs, and each layer lights in its own colour. Caps Word makes the one-shot Shift and Caps Word keys glow white.
