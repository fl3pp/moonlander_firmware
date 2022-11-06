# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no 
COMMAND_ENABLE = no
AUDIO_ENABLE = no
ORYX_ENABLE = yes
SPACE_CADET_ENABLE = no
UNICODEMAP_ENABLE = yes

SRC = matrix.c features/umlaut.c features/unicode.c shim/qmk.c