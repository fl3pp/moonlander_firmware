ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
MSYS := $(ROOT_DIR)msys.cmd

all: build

build:
	$(MSYS) qmk compile -j 0

flash:
	$(MSYS) qmk flash -j 0

console:
	$(MSYS) qmk console

setup:
	$(MSYS) qmk config user.hide_welcome=True
	$(MSYS) qmk setup --home $(ROOT_DIR)..\..\..\.. --yes
	$(MSYS) qmk config user.keyboard=moonlander
	$(MSYS) qmk config user.keymap=fl3pp

clean:
	$(MSYS) qmk clean
