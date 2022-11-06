# Custom Moonlander Firmware

This repository contains the custom firmware for the
[ZSA Moonlander](https://www.zsa.io/moonlander/) keyboard.

## Prerequisites

To run:

- [WinCompose](http://wincompose.info/) to enter Unicode code-points

To compile & flash:

- The [Wally](https://ergodox-ez.com/pages/wally) flashing tool

- The [QMK MSYS](https://msys.qmk.fm/) development environment (set
  environment variable `QMK_HOME` to path of installation)

- [ZSA's fork](https://github.com/zsa/qmk_firmware) of the QMK firmware (check current release branch)

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

5. Compile and flash your firmware (`qmk compile` to just build)

``` bash
qmk flash
```

Alternatively, you can also flash using the Wally UI (file in
`.build/moonlander_fl3pp.bin`)

6. You're done!

## Debugging

To enable debugging, activate the console in the compilation rules in
`rules.mk`:

```
CONSOLE_ENABLE = yes
```

Inside your keymap, you can then use the `uprintf` function as replacement
for `printf`.

To view the printed messages, start the QMK debug console:

```
qmk console
```

Note: The console functionality is about 5KB in size, and depending on your
messages, can take up quite a few CPU cycles. So if you aren't actively
debugging your keymap, exclude the code from your compilation using the
`CONSOLE_ENABLE` compilation symbol.

## Test

There is a test infrastructure in place using
[acutest](https://github.com/mity/acutest) as test framework.

To run them, simply go into the `/test` folder and execute `make`.

## Unicode

There are multiple ways to send code-points from QMK firmware (see
[docs](https://docs.qmk.fm/#/feature_unicode)).

This keymap uses the `UNICODEMAP` method to specify the code-points as well
as the `WINC` input mode (requires WinCompose installation).

The code-points are named using the `unicode_names` enum, specified in the
`unicode_map` and are accessed through either `X(name)` in the keymap or
`unicode_map[name]` in code.

In this keymap, the corresponding functionality can be found in
`features/unicode.c-h`.

## Other

- List supported keyboards
  `qmk list-keyboards`

- Print a layout of a keyboard using:
  `qmk info --keyboard <keyboard> --layouts`

