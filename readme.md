# Custom Moonlander Firmware

This repository contains the custom firmware for the
[ZSA Moonlander](https://www.zsa.io/moonlander/) keyboard.

## Prerequisites

To run:

- [WinCompose](http://wincompose.info/) to enter Unicode code-points. Set
  the compose key to `F13` (in `%appdata%\WinCompose\settings.ini` ->
  `[composing]compose_key=VK.F13`)

To compile & flash:

- The [Wally](https://ergodox-ez.com/pages/wally) flashing tool

- The [QMK MSYS](https://msys.qmk.fm/) development environment (set
  environment variable `QMK_HOME` to path of installation)

- [ZSA's fork](https://github.com/zsa/qmk_firmware) of the QMK firmware (check current release branch)

``` bash
git clone --recurse-submodules --branch firmware21 https://github.com/zsa/qmk_firmware zsa_qmk_firmware
```

## Makefile and MSYS

There is a `Makefile` setup which automates many of the building steps. In
order to execute it, you must use the `make.cmd` in the root, which
automatically redirects all commands to the MSYS environment.

Following make targets have been setup:

- `.\make build`: Builds the test binaries and the keymap
- `.\make test`: Builds and executes the test binaries
- `.\make flash`: Builds and flashed the firmware on the keyboard. In order
  for this command to work, you must first set your keyboard in reset-mode
  (`RESET` in `keymap.c`)
- `.\make setup`: Configure QMK to use this repository
- `.\make clean`: Remove the test binaries and keymap binary
- `.\make console`: Start the QMK Debug console
- `.\make all`: Execute tests and compile keymap

There also is a `qmk.cmd` file available, which allows you to either execute
`qmk` commands directly in the MSYS environment or start an interactive
shell if started without arguments.

## Features

Features implemented in this keymap, either explicitly or by utilizing QMK
features.

### QMK Shim

There is a slim QMK shim set up in order to make testing easier.

### Umlaut

There is an extensive implementation for Umlauts, since they are placed on a
separate layer and differentiation between upper- and lower case is not
trivial without either monkey-combinations or losing intuitive behavior.

The idea is as following:

- A single shift press without other presses toggles a caps-lock mode for
  umlauts. Leaving the umlaut layer resets the caps-lock
- Holding the shift down should also work as expected, no matter in which
  layer the shift was first pressed down

The corresponding implementation can be found in `features/umlaut.c-h`.

### Unicode

There are multiple ways to send code-points from QMK firmware (see
[docs](https://docs.qmk.fm/#/feature_unicode)).

This keymap uses the `UNICODEMAP` method to specify the code-points as well
as the `WINC` input mode (requires WinCompose installation).

The code-points are named using the `unicode_names` enum, specified in the
`unicode_map` and are accessed through either `X(name)` in the keymap or
`unicode_map[name]` in code.

In this keymap, the corresponding functionality can be found in
`features/unicode.c-h`.

## Test

There is a test infrastructure in place using
[acutest](https://github.com/mity/acutest) as test framework.

## Environment Setup

1. Install and configure the prerequisites

2. Clone your keymap code into `keyboards/moonlander/keymaps/<layout>` and
   set the default keymap

``` bash
# You'll maybe have to do this outside of the QMK shell
git clone git@github.com:fl3pp/moonlander_firmware.git /c/dev/qmk/zsa_qmk_firmware/keyboards/moonlander/keymaps/fl3pp
```

3. Setup the QMK Environment using `make`

``` bash
.\make setup
```

4. Compile your firmware

``` bash
.\make build
```

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
.\make console
```

Note: The console functionality is about 5KB in size, and depending on your
messages, can take up quite a few CPU cycles. So if you aren't actively
debugging your keymap, exclude the code from linking into your binary using
the `CONSOLE_ENABLE` compilation symbol.

## Other

- List supported keyboards
  `qmk list-keyboards`

- Print a layout of a keyboard using:
  `qmk info --keyboard <keyboard> --layouts`

