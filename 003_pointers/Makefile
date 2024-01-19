CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = src
BIN_DIR = bin

SOURCES := $(wildcard $(SRC_DIR)/ex*.c)

EXECUTABLES := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SOURCES))

all: $(EXECUTABLES)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLES)
