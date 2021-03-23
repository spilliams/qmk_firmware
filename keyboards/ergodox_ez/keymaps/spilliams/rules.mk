# from ergodox/steno
STENO_ENABLE = yes          # Additional protocols for Stenography(+1700), requires VIRTSER

# from https://github.com/paulfioravanti/qmk_example_keymaps
VIRTSER_ENABLE = yes
FORCE_NKRO = yes

# from georgi/spilliams
#Firmware reduction options
MOUSEKEY_ENABLE			 = no   # 1500 bytes
# NO_TAPPING				 = no   # this also enables OSL, for some reason
# NO_PRINT				 = yes

# #Debug options
# CONSOLE_ENABLE			 = no   # Plover needs this to be no? to use the serial?
# DEBUG_MATRIX_SCAN_RATE   = no
# DEBUG_MATRIX			 = no
# ONLY_QWERTY				 = no

# from ergodox_ez/default_glow
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes # enable later
