# Task: update my ZSA Voyager layout in Oryx

You are editing my keyboard layout in ZSA's Oryx configurator for me. Work carefully and exactly. This is a precise data-entry job, so don't redesign anything.

## Where
- Layout: https://configure.zsa.io/voyager/layouts/nd96R/latest/0
  - The last number in the URL is the layer (0 = Base, 1, 2, 3, 4 = Mouse, and the new 5).
- I must be logged in and own this layout. If Oryx shows it as read-only or asks to log in, or the page shows someone else's layout, **stop and tell me**. Don't make a copy.

## Rules
1. **Change only the keys listed below.** Every other key stays exactly as it is.
2. **Don't touch the Mouse layer (layer 4),** and don't change any LED colours. The colours are set in code.
3. **Don't change any settings** under Oryx's config or settings: tapping term, Permissive Hold, Chordal Hold, Flow Tap, combos, and so on. All of these are set in code.
4. **Positions are named after the Base layer key in the same physical spot.** "E position" on layer 2 means the key that types E on Base.
   - **Thumbs:** each half has 2 thumb keys. The outer one is further from the centre of the keyboard, the inner one is closer.
5. **How to set a key:**
   - Click the key, then set its Tap (and Hold, where given) in the key editor.
   - "X with Cmd + Shift" means the key X with those modifier boxes ticked. Cmd is called GUI or ⌘ in some places.
   - "Transparent" and "None/blocked" are different settings, so use exactly the one listed.
   - Clear any existing Hold, double-tap or tap-and-hold action unless a Hold is listed.
6. **If something can't be set exactly as written,** don't improvise. Leave it, note it, and carry on. Report it at the end.
7. **Work through the layers in order: 0, 1, 2, 3, then create layer 5.** After finishing each layer, compare it with the target grid at the bottom of this prompt and fix any mismatch.

There are 119 key changes in total.

## Layer 0 (Base)
Only these 6 keys change. The letters, home-row modifiers and both Backspaces stay as they are.

| Position | Currently | Change to |
|---|---|---|
| Number row, above T | None (blocked, no key) | Leader key (if Oryx has no Leader key, use F24 instead) |
| Number row, above Y | None (blocked, no key) | Caps Word |
| Number row, far right | Transparent | 4 with Ctrl + Cmd + Shift |
| Left thumb outer | Tap: Space. Hold: Layer 2 (momentary) | Tap: Space. Hold: Layer 3 (momentary) |
| Left thumb inner | Tap: Enter. Hold: Layer 3 (momentary) | Tap: Enter with Shift (Shift+Enter). Hold: Layer 1 (momentary). If Oryx can't combine a Shift+Enter tap with a layer hold, use Tap: Enter and report it |
| Right thumb inner | Tap: Tab. Hold: Layer 1 (momentary) | Tap: Tab. Hold: Layer 2 (momentary) |

## Layer 1 (becomes "Numbers + IDE")
31 keys change.

| Position | Currently | Change to |
|---|---|---|
| Number row, far right | My Computer | Transparent |
| Q position | None (blocked, no key) | Layer Lock |
| W position | None (blocked, no key) | \ with Cmd |
| E position | None (blocked, no key) | E with Cmd + Shift |
| R position | None (blocked, no key) | H with Cmd + Shift |
| T position | % | ` (grave) with Ctrl |
| Y position | ^ (caret) | + (plus) |
| U position | Keypad minus | 7 |
| I position | Keypad plus | 8 |
| O position | Keypad asterisk | 9 |
| P position | Keypad slash | * (asterisk) |
| A position | 1 | Left Ctrl (plain modifier key) |
| S position | 2 | Left Alt (plain modifier key) |
| D position | 3 | Left Cmd/GUI (plain modifier key) |
| F position | 4 | F with Cmd + Shift |
| G position | 5 | G with Ctrl + Shift |
| H position | 6 | - (minus) |
| J position | 7 | 4 |
| K position | 8 | 5 |
| L position | 9 | 6 |
| : (right of L) | 0 | . (period) |
| ' (far right) | Transparent | : (colon) |
| Z position | None (blocked, no key) | C with Alt + Cmd |
| X position | None (blocked, no key) | C with Alt + Cmd + Shift |
| C position | None (blocked, no key) | P with Cmd + Shift |
| V position | None (blocked, no key) | Space with Alt |
| B position | None (blocked, no key) | . (period) with Cmd |
| M position | None (blocked, no key) | 1 |
| , position | Transparent | 2 |
| . position | Transparent | 3 |
| ; position | Transparent | / (slash) |

## Layer 2 (Symbols)
8 keys change. Note: the `_` and `?` keys swap places. The brackets `[ ] ( ) < >`, plus `~` and `` ` ``, keep their positions.

| Position | Currently | Change to |
|---|---|---|
| U position | - (minus) | Macro that types -> (minus, then Shift+period) |
| I position | + (plus) | Macro that types => (equals, then Shift+period) |
| O position | * (asterisk) | Transparent |
| P position | / (slash) | Transparent |
| A position | ? (question mark) | _ (underscore) |
| H position | _ (underscore) | ? (question mark) |
| N position | 0 | Transparent |
| M position | None (blocked, no key) | Transparent |

## Layer 3 (becomes "Nav")
22 keys change. Keep Right Alt on the four P/H/L/N shortcuts, as they are today.

| Position | Currently | Change to |
|---|---|---|
| W position | \ with Cmd | [ with Cmd + Shift |
| E position | [ with Cmd + Shift | ] with Cmd + Shift |
| R position | ] with Cmd + Shift | - (minus) with Ctrl |
| T position | Down arrow with Cmd | - (minus) with Ctrl + Shift |
| P position | Media play/pause | None (blocked, no key) |
| Backspace (right of P) | Stop | Delete (forward delete) |
| A position | None (blocked, no key) | Left Ctrl (plain modifier key) |
| S position | G with Ctrl + Shift | Left Alt (plain modifier key) |
| D position | F with Cmd + Shift | Left Cmd/GUI (plain modifier key) |
| F position | H with Cmd + Shift | Left Shift (plain modifier key) |
| G position | E with Cmd + Shift | Layer Lock |
| : (right of L) | Volume down | None (blocked, no key) |
| ' (far right) | Volume up | None (blocked, no key) |
| Backspace (left of Z) | Space with Alt | Transparent |
| Z position | C with Alt + Cmd + Shift | Z with Cmd |
| X position | C with Alt + Cmd | X with Cmd |
| C position | Tap dance (Cmd+1 / Cmd+2) | C with Cmd |
| V position | ` (grave) with Ctrl | V with Cmd |
| B position | None (blocked, no key) | Z with Cmd + Shift |
| ; position | Audio mute | None (blocked, no key) |
| = (far right) | 4 with Cmd + Shift | None (blocked, no key) |
| Right thumb inner | Transparent | Enter |

## New layer 5 (F-keys + media)
Add a new layer **at the end**, after the Mouse layer, so it is layer **5** (URL ends in `/5`). **Don't** add any key that switches to it: code opens it when both inner thumbs are pressed together.
Set all 52 keys exactly as listed, including the ones marked "None (blocked, no key)". The two **inner** thumbs must be **Transparent**.

| Position | Set to |
|---|---|
| Number row, far left (Esc) | Bootloader / Reset to flash (QK_BOOT) |
| Number row, above Q | None (blocked, no key) |
| Number row, above W | None (blocked, no key) |
| Number row, above E | None (blocked, no key) |
| Number row, above R | None (blocked, no key) |
| Number row, above T | None (blocked, no key) |
| Number row, above Y | None (blocked, no key) |
| Number row, above U | None (blocked, no key) |
| Number row, above I | None (blocked, no key) |
| Number row, above O | None (blocked, no key) |
| Number row, above P | None (blocked, no key) |
| Number row, far right | Q with Ctrl + Cmd (locks the Mac screen) |
| Tab (left of Q) | None (blocked, no key) |
| Q position | F12 |
| W position | F7 |
| E position | F8 |
| R position | F9 |
| T position | None (blocked, no key) |
| Y position | Media play/pause |
| U position | Audio mute |
| I position | Volume down |
| O position | Volume up |
| P position | None (blocked, no key) |
| Backspace (right of P) | None (blocked, no key) |
| One-shot Shift (left of A) | None (blocked, no key) |
| A position | F11 |
| S position | F4 |
| D position | F5 |
| F position | F6 |
| G position | None (blocked, no key) |
| H position | None (blocked, no key) |
| J position | Left Shift (plain modifier key) |
| K position | Left Cmd/GUI (plain modifier key) |
| L position | Left Alt (plain modifier key) |
| : (right of L) | Left Ctrl (plain modifier key) |
| ' (far right) | None (blocked, no key) |
| Backspace (left of Z) | None (blocked, no key) |
| Z position | F10 |
| X position | F1 |
| C position | F2 |
| V position | F3 |
| B position | Layer Lock |
| N position | 4 with Cmd + Shift |
| M position | RGB toggle (LEDs on/off) |
| , position | RGB brightness down |
| . position | RGB brightness up |
| ; position | None (blocked, no key) |
| = (far right) | None (blocked, no key) |
| Left thumb outer | None (blocked, no key) |
| Left thumb inner | Transparent |
| Right thumb inner | Transparent |
| Right thumb outer | None (blocked, no key) |

## Optional: layer names
If Oryx lets you name layers, use: 0 "Base", 1 "Numbers + IDE", 2 "Symbols", 3 "Nav", 4 leave as is, 5 "F-keys".

## Check, then compile
1. Go back through layers 0, 1, 2, 3 and 5, and compare each with its target grid below.
   - **Grid symbols:** `·` = Transparent, `✕` = None/blocked, `⌘⌥⌃⇧` = Cmd/Alt/Ctrl/Shift. `X/Y` on a thumb means tap X, hold Y.
   - **Hold names:** NAV = layer 3, NUM = layer 1, SYM = layer 2. The thumb labels on layers 1, 2, 3 and 5 only show which thumb is being held; those thumbs are Transparent.
2. Click **Compile this layout**. If there is a field for notes about the change, enter: `New layout: thumbs, Numbers + IDE, Symbols, Nav, F-keys (layer 5)`.
3. Wait for the compile to finish. Don't download or flash anything.

## Report back to me
- Confirm that each layer matches its grid. List anything you couldn't set exactly, and what you set instead.
- Give me the URL of the page after compiling.

## Target grids (the tap action of every key, left half | right half)

**Layer 0, Base**
```
  Esc     ✕     ✕     ✕     ✕  Lead  |     CW     ✕     ✕     ✕     ✕  ⌃⌘⇧4
  Tab     Q     W     E     R     T  |      Y     U     I     O     P  Bspc
  OS⇧     A     S     D     F     G  |      H     J     K     L     :     '
 Bspc     Z     X     C     V     B  |      N     M     ,     .     ;     =
thumbs: Space/NAV, ⇧⏎/NUM, Tab/SYM, Esc/⇧
```

**Layer 1, Numbers + IDE**
```
    ·     ·     ·     ·     ·     ·  |      ·     ·     ·     ·     ·     ·
    · LLock    ⌘\   ⌘⇧E   ⌘⇧H    ⌃`  |      +     7     8     9     *     ·
    ·     ⌃     ⌥     ⌘   ⌘⇧F   ⌃⇧G  |      -     4     5     6     .     :
    ·   ⌥⌘C  ⌥⌘⇧C   ⌘⇧P  ⌥Spc    ⌘.  |      0     1     2     3     /     ·
thumbs: ·, ·/NUM, ·/SYM, ·
```

**Layer 2, Symbols**
```
    ·     ·     ·     ·     ·     ·  |      ·     ·     ·     ·     ·     ·
    ·     !     @     [     ]     %  |      ^    ->    =>     ·     ·     ·
    ·     _     &     <     >     #  |      ?     {     }     |     \     "
    ·     ~     `     (     )     $  |      ·     ·     ·     ·     ·     ·
thumbs: ·, ·/NUM, ·/SYM, ·
```

**Layer 3, Nav**
```
    ·     ·     ·     ·     ·     ·  |      ·     ·     ·     ·     ·     ·
    ·     ✕   ⌘⇧[   ⌘⇧]    ⌃-   ⌃⇧-  |     ⌥P    ⌥H    ⌥L    ⌥N     ✕   Del
    ·     ⌃     ⌥     ⌘     ⇧ LLock  |      ←     ↓     ↑     →     ✕     ✕
    ·    ⌘Z    ⌘X    ⌘C    ⌘V   ⌘⇧Z  |   Home  PgDn  PgUp   End     ✕     ✕
thumbs: ·/NAV, ·, Enter, ·
```

**Layer 5, F-keys + media**
```
 Boot     ✕     ✕     ✕     ✕     ✕  |      ✕     ✕     ✕     ✕     ✕  Lock
    ✕   F12    F7    F8    F9     ✕  |   Play  Mute  Vol-  Vol+     ✕     ✕
    ✕   F11    F4    F5    F6     ✕  |      ✕     ⇧     ⌘     ⌥     ⌃     ✕
    ✕   F10    F1    F2    F3 LLock  |    ⌘⇧4   RGB  Bri-  Bri+     ✕     ✕
thumbs: ✕, ·/FN, ·/FN, ✕
```
