CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = src
BIN_DIR = bin

$(BIN_DIR)/phonebook: $(SRC_DIR)/phonebook.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f phonebook
