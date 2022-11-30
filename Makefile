ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all: TEST_EXECUTE QMK-COMPILE
build: $(TEST_BINS) QMK-COMPILE
test: TEST_EXECUTE
flash: QMK-FLASH
console: QMK-CONSOLE
setup: QMK-SETUP
clean: TEST_CLEAN QMK-CLEAN

# ########
# QMK
# ########

QMK-SETUP:
	qmk config user.hide_welcome=True
	qmk setup --home $(ROOT_DIR)..\..\..\.. --yes
	qmk config user.keyboard=moonlander
	qmk config user.keymap=fl3pp

QMK-COMPILE:
	qmk compile

QMK-FLASH:
	qmk flash

QMK-CONSOLE:
	qmk console

QMK-CLEAN:
	qmk clean

# ########
# Testing
# ########

CC := gcc
CFLAGS := -ggdb -I. -Wall -I/ -Itest/lib/ -I../../../../quantum

TEST_SRCS := $(wildcard ./test/*.c)
TEST_BINS := $(patsubst %.c, %, $(TEST_SRCS))

$(TEST_BINS): $(TEST_SRCS)
	$(CC) $(CFLAGS) -o $@ $<

TEST_EXECUTE: $(TEST_BINS)
	$(TEST_BINS)

TEST_CLEAN:
	rm -f $(TEST_BINS)

