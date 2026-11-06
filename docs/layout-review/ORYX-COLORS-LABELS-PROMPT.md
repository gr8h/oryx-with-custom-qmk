# Task: set the LED colours and key labels of my ZSA Voyager layout in Oryx

You are setting per-key LED colours and custom key labels in ZSA's Oryx configurator for me. This is a precise data-entry job: use exactly the colours and labels given, and change nothing else.

## Before you start
- Layout: https://configure.zsa.io/voyager/layouts/nd96R/latest/0
  - The last number in the URL is the layer (0 = Base, 1, 2, 3, 4 = Mouse, 5 = F-keys).
- Another session may have just finished changing the keys on this layout. Make sure layer 5 exists. If it doesn't, or if anything else on the layout is still being edited, **stop and tell me**.
- I must be logged in and own the layout. If Oryx shows it as read-only or asks to log in, **stop and tell me**.

## Rules
1. **Change only LED colours and custom labels.** Don't change any key, Hold action, layer or setting.
2. **Don't touch the Mouse layer (layer 4).** It keeps its current colours and labels.
3. **Positions are named after the Base layer key in the same physical spot.** For example, "J" on layer 3 means the key that types J on Base. Each half has 2 thumb keys: the outer one is further from the centre of the keyboard, the inner one is closer.
4. **Set each listed key's colour to the exact hex value given.** Use the colour picker's hex/custom input if there is one.
   - Every key **not** listed for a layer must have **no colour**: off, black, or "none".
   - On Base this includes all the letter keys, which currently glow blue.
5. **Bright and dim are different colours.** Dim versions are the same colour at 40% brightness, so use the exact hex.
6. **Some keys are Transparent** (for example the thumb you hold to open a layer). They still get the colour listed.
7. **If Oryx can only fill a whole layer at once,** that can be a quick way to clear a layer to "no colour" first, then set the listed keys.
8. **Labels:** type each label exactly as given, without the backticks, into the key's custom label field (Oryx calls it "Label this key"). The limit is 11 characters, and every label here fits.
   - Keys with "—" in the Label column get **no** custom label. Clear any existing custom label on them, and on every key not in the table, because old labels from the previous layout would now be wrong.
9. **If something can't be set exactly,** don't improvise. Note it, carry on, and report it at the end.

## Palette

| Colour | Bright | Dim (40%) |
|---|---|---|
| Green | #00FF00 | #006600 |
| White | #FFFFFF | #666666 |
| Cyan | #00FCFF | #006566 |
| Amber | #FF7E00 | #663200 |
| Magenta | #FF00FC | #660065 |
| Blue | #0000FF | #000066 |

Boot, Lock screen and Layer Lock all use the white values.

## Colours and labels per layer

Each layer also has a colour grid to check against.
- **Grid codes:** G = green, W = white, C = cyan, A = amber, M = magenta, B = blue.
- **Brightness:** UPPER case = bright, lower case = dim, `.` = no colour.
- **Grid layout:** left half, then right half.

### Layer 0: Base

18 keys get a colour and 4 keys get a label. **Every key not in this table: no colour and no custom label.**

| Position | Colour | Label |
|---|---|---|
| number row far left | White dim `#666666` | — |
| number row above T | White dim `#666666` | `Leader` |
| number row above Y | White dim `#666666` | `Caps Word` |
| number row far right | Blue dim `#000066` | `Shot clip` |
| Tab (left of Q) | White dim `#666666` | — |
| Backspace (right of P) | White dim `#666666` | — |
| One-shot Shift (left of A) | Green dim `#006600` | — |
| A | Green dim `#006600` | — |
| S | Green dim `#006600` | — |
| D | Green dim `#006600` | — |
| K | Green dim `#006600` | — |
| L | Green dim `#006600` | — |
| : (right of L) | Green dim `#006600` | — |
| Backspace (left of Z) | White dim `#666666` | — |
| left thumb outer | Cyan bright `#00FCFF` | — |
| left thumb inner | Amber bright `#FF7E00` | `Newline` |
| right thumb inner | Magenta bright `#FF00FC` | — |
| right thumb outer | Green bright `#00FF00` | — |

Colour grid to check against:
```
w . . . . w   w . . . . b
w . . . . .   . . . . . w
g g g g . .   . . g g g .
w . . . . .   . . . . . .
thumbs: C A M G
```
### Layer 1: Numbers + IDE

32 keys get a colour and 12 keys get a label. **Every key not in this table: no colour and no custom label.**

| Position | Colour | Label |
|---|---|---|
| Q | White dim `#666666` | `Lock layer` |
| W | Blue dim `#000066` | `Split` |
| E | Blue dim `#000066` | `Explorer` |
| R | Blue dim `#000066` | `Replace all` |
| T | Blue dim `#000066` | `Terminal` |
| Y | Amber dim `#663200` | — |
| U | Amber bright `#FF7E00` | — |
| I | Amber bright `#FF7E00` | — |
| O | Amber bright `#FF7E00` | — |
| P | Amber dim `#663200` | — |
| A | Green dim `#006600` | — |
| S | Green dim `#006600` | — |
| D | Green dim `#006600` | — |
| F | Blue dim `#000066` | `Find all` |
| G | Blue dim `#000066` | `Git` |
| H | Amber dim `#663200` | — |
| J | Amber bright `#FF7E00` | — |
| K | Amber bright `#FF7E00` | — |
| L | Amber bright `#FF7E00` | — |
| : (right of L) | Amber dim `#663200` | — |
| ' (far right) | Amber dim `#663200` | — |
| Z | Blue dim `#000066` | `Full path` |
| X | Blue dim `#000066` | `Rel path` |
| C | Blue dim `#000066` | `Palette` |
| V | Blue dim `#000066` | `Launcher` |
| B | Blue dim `#000066` | `Quick fix` |
| N | Amber bright `#FF7E00` | — |
| M | Amber bright `#FF7E00` | — |
| , | Amber bright `#FF7E00` | — |
| . | Amber bright `#FF7E00` | — |
| ; | Amber dim `#663200` | — |
| left thumb inner | Amber bright `#FF7E00` | — |

Colour grid to check against:
```
. . . . . .   . . . . . .
. w b b b b   a A A A a .
. g g g b b   a A A A a a
. b b b b b   A A A A a .
thumbs: . A . .
```
### Layer 2: Symbols

25 keys get a colour and 2 keys get a label. **Every key not in this table: no colour and no custom label.**

| Position | Colour | Label |
|---|---|---|
| Q | Magenta dim `#660065` | — |
| W | Magenta dim `#660065` | — |
| E | Magenta bright `#FF00FC` | — |
| R | Magenta bright `#FF00FC` | — |
| T | Magenta dim `#660065` | — |
| Y | Magenta dim `#660065` | — |
| U | Magenta bright `#FF00FC` | `->` |
| I | Magenta bright `#FF00FC` | `=>` |
| A | Magenta dim `#660065` | — |
| S | Magenta dim `#660065` | — |
| D | Magenta bright `#FF00FC` | — |
| F | Magenta bright `#FF00FC` | — |
| G | Magenta dim `#660065` | — |
| H | Magenta dim `#660065` | — |
| J | Magenta bright `#FF00FC` | — |
| K | Magenta bright `#FF00FC` | — |
| L | Magenta dim `#660065` | — |
| : (right of L) | Magenta dim `#660065` | — |
| ' (far right) | Magenta dim `#660065` | — |
| Z | Magenta dim `#660065` | — |
| X | Magenta dim `#660065` | — |
| C | Magenta bright `#FF00FC` | — |
| V | Magenta bright `#FF00FC` | — |
| B | Magenta dim `#660065` | — |
| right thumb inner | Magenta bright `#FF00FC` | — |

Colour grid to check against:
```
. . . . . .   . . . . . .
. m m M M m   m M M . . .
. m m M M m   m M M m m m
. m m M M m   . . . . . .
thumbs: . . M .
```
### Layer 3: Nav

29 keys get a colour and 15 keys get a label. **Every key not in this table: no colour and no custom label.**

| Position | Colour | Label |
|---|---|---|
| W | Blue dim `#000066` | `Prev tab` |
| E | Blue dim `#000066` | `Next tab` |
| R | Blue dim `#000066` | `Back` |
| T | Blue dim `#000066` | `Forward` |
| Y | Blue dim `#000066` | `Prev win` |
| U | Blue dim `#000066` | `Pane left` |
| I | Blue dim `#000066` | `Pane right` |
| O | Blue dim `#000066` | `Next win` |
| Backspace (right of P) | White bright `#FFFFFF` | `Fwd delete` |
| A | Green dim `#006600` | — |
| S | Green dim `#006600` | — |
| D | Green dim `#006600` | — |
| F | Green dim `#006600` | — |
| G | White dim `#666666` | `Lock layer` |
| H | Cyan bright `#00FCFF` | — |
| J | Cyan bright `#00FCFF` | — |
| K | Cyan bright `#00FCFF` | — |
| L | Cyan bright `#00FCFF` | — |
| Z | White dim `#666666` | `Undo` |
| X | White dim `#666666` | `Cut` |
| C | White dim `#666666` | `Copy` |
| V | White dim `#666666` | `Paste` |
| B | White dim `#666666` | `Redo` |
| N | Cyan dim `#006566` | — |
| M | Cyan dim `#006566` | — |
| , | Cyan dim `#006566` | — |
| . | Cyan dim `#006566` | — |
| left thumb outer | Cyan bright `#00FCFF` | — |
| right thumb inner | White bright `#FFFFFF` | — |

Colour grid to check against:
```
. . . . . .   . . . . . .
. . b b b b   b b b b . W
. g g g g w   C C C C . .
. w w w w w   c c c c . .
thumbs: C . W .
```
### Layer 5: F-keys + media

29 keys get a colour and 19 keys get a label. **Every key not in this table: no colour and no custom label.**

| Position | Colour | Label |
|---|---|---|
| number row far left | White dim `#666666` | `Flash` |
| number row far right | White dim `#666666` | `Lock Mac` |
| Q | Amber bright `#FF7E00` | `F12 GoDef` |
| W | Amber bright `#FF7E00` | `F7 Diff` |
| E | Amber bright `#FF7E00` | `F8 Problem` |
| R | Amber bright `#FF7E00` | `F9 Brkpt` |
| Y | Blue dim `#000066` | — |
| U | Blue dim `#000066` | — |
| I | Blue dim `#000066` | — |
| O | Blue dim `#000066` | — |
| A | Amber bright `#FF7E00` | `F11 StepIn` |
| S | Amber bright `#FF7E00` | `F4 Result` |
| D | Amber bright `#FF7E00` | `F5 Debug` |
| F | Amber bright `#FF7E00` | `F6 Pause` |
| J | Green dim `#006600` | — |
| K | Green dim `#006600` | — |
| L | Green dim `#006600` | — |
| : (right of L) | Green dim `#006600` | — |
| Z | Amber bright `#FF7E00` | `F10 StepOv` |
| X | Amber bright `#FF7E00` | `F1 Palette` |
| C | Amber bright `#FF7E00` | `F2 Rename` |
| V | Amber bright `#FF7E00` | `F3 Next` |
| B | White dim `#666666` | `Lock layer` |
| N | Blue dim `#000066` | `Shot file` |
| M | White dim `#666666` | `LEDs on/off` |
| , | White dim `#666666` | `LED dim` |
| . | White dim `#666666` | `LED bright` |
| left thumb inner | Amber bright `#FF7E00` | — |
| right thumb inner | Amber bright `#FF7E00` | — |

Colour grid to check against:
```
w . . . . .   . . . . . w
. A A A A .   b b b b . .
. A A A A .   . g g g g .
. A A A A w   b w w w . .
thumbs: . A A .
```

## Check, then compile
1. Go through layers 0, 1, 2, 3 and 5. Compare each with its colour grid, then check the labels against the table. Don't change layer 4.
2. Click **Compile this layout**. If there is a notes field, enter: `LED colours and key labels for the new layout`.
3. Wait for the compile to finish. Don't download or flash anything.

## Report back to me
- Confirm that each layer matches its colour grid and label table.
- List any key you couldn't colour or label exactly, and what you did instead.
