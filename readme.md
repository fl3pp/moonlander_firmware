# fl3pp moonlander firmware

This repository contains custom firmware for the
[ZSA Moonlander](https://www.zsa.io/moonlander/) keyboard.

There once was a more elaborate setup in place, including a custom QMK
abstraction as well as custom implemented features and a test
infrastructure. This was removed for the sake of simplicity. You can still
find the source code under the git tag
[unicode](https://github.com/fl3pp/moonlander_firmware/tree/unicode).

## Prerequisites

To run:

- [WinCompose](http://wincompose.info/) to enter Unicode code-points. Set
  the compose key to `F13` (in `%appdata%\WinCompose\settings.ini` ->
  `[composing]compose_key=VK.F13`)

To compile & flash:

- The [Make](https://gnuwin32.sourceforge.net/packages/make.htm#:~:text=Make%20is%20a%20tool%20which,compute%20it%20from%20other%20files) build tool

- The [Wally](https://ergodox-ez.com/pages/wally) flashing tool

- The [QMK MSYS](https://msys.qmk.fm/) development environment (set
  environment variable `QMK_HOME` to path of installation)

- [ZSA's fork](https://github.com/zsa/qmk_firmware) of the QMK firmware (check current release branch)

``` bash
git clone --recurse-submodules --branch firmware23 https://github.com/zsa/qmk_firmware zsa_qmk_firmware
```

## Makefile and MSYS

There is a `Makefile` setup which automates many of the building steps. It
automatically redirects all commands to the MSYS environment for Windows.

Following make targets have been setup:

- `make build`: Builds the keymap
- `make flash`: Builds and flashes the firmware on the keyboard. In order
  for this command to work, you must first set your keyboard in reset-mode
  (`RESET` in `keymap.c`)
- `make setup`: Configure QMK to use this repository
- `make clean`: Remove keymap binary
- `make console`: Start the QMK debug console
- `make all`: Compile keymap

There also is a `msys.cmd` file available, which allows you to either
execute commands directly in the MSYS environment or start an interactive
shell if executed without additional process arguments.

## Environment Setup

1. Install and configure the prerequisites

2. Clone your keymap code into `keyboards/moonlander/keymaps/<layout>`

``` bash
git clone git@github.com:fl3pp/moonlander_firmware.git /c/dev/qmk/zsa_qmk_firmware/keyboards/moonlander/keymaps/fl3pp
```

3. Setup the QMK Environment using `make`

``` bash
make setup
```

4. Compile your firmware

``` bash
make build
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
make console
```

Note: The console functionality is about 5KB in size, and depending on your
messages, can take up quite a few CPU cycles. So if you aren't actively
debugging your keymap, exclude the code from linking into your binary using
the `CONSOLE_ENABLE` compilation symbol.

## Other

- List supported keyboards
  `.\msys.cmd qmk list-keyboards`

- Print a layout of a keyboard using:
  `.\msys.cmd qmk info --keyboard <keyboard> --layouts`

