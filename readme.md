# Custom Moonlander Firmware

This repository contains the custom firmware for the
[ZSA Moonlander](https://www.zsa.io/moonlander/) keyboard.

## Prerequisites

- The [Wally](https://ergodox-ez.com/pages/wally) flashing tool

- The [QMK MSYS](https://msys.qmk.fm/) development environment

- [ZSA's fork](https://github.com/zsa/qmk_firmware) of the QMK firmware (check current branch)

``` bash
git clone --recurse-submodules --branch firmware21 https://github.com/zsa/qmk_firmware zsa_qmk_firmware
```

## Environment Setup

1. Start the QMK shell and navigate to the firmware directory

``` bash
# e.g. .\qmk.cmd
cd /c/dev/qmk/zsa_qmk_firmware
```

2. Setup the ZSA fork as your QMK home directory and the default keyboard:

``` bash
qmk setup -H /c/dev/qmk/zsa_qmk_firmware
# list available keyboards: qmk config user.keyboard=moonlander
qmk config user.keyboard=moonlander
```

3. Verify the build environment by building the default keymap:

``` bash
qmk compile [kb](-kb) moonlander -km default
# second time should be much faster
```

4. Clone your keymap code into `keyboards/moonlander/keymaps/<layout>` and
   set the default keymap

``` bash
# You'll maybe have to do this outside of the QMK shell
git clone git@github.com:fl3pp/moonlander_firmware.git /c/dev/qmk/zsa_qmk_firmware/keyboards/moonlander/keymaps/fl3pp
qmk config user.keymap=fl3pp
```

5. Compile your keymap

``` bash
qmk compile
```

6. Flash your firmware (in `.build/moonlander_fl3pp.bin`) using Wally (UI
   interface)

7. You're done!

## Tricks

- List supported keyboards
  `qmk list-keyboards`

- Print a layout of a keyboard using:
  `qmk info --keyboard <keyboard> --layouts`

