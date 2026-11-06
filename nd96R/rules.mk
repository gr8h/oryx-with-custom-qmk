CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
LAYER_LOCK_ENABLE = yes

# Custom QMK features (logic in custom_qmk.c, design in docs/layout-review/)
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
LEADER_ENABLE = yes
# Compiled together with keymap.c, so keymap.c itself stays as Oryx exports it
INTROSPECTION_KEYMAP_C = custom_qmk.c
