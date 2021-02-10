PROJECT_NAME := matching_pairs
SRC_DIR      := src
SOURCES      := $(wildcard $(SRC_DIR)/*.c)
BUILD_DIR    := build
PROGRAM      := $(BUILD_DIR)/$(PROJECT_NAME)
PROGRAM_ARG ?= 15

CFLAGS :=
CFLAGS += -std=c99
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -O0

all: $(PROGRAM)
.PHONY: all

$(PROGRAM): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $@

run: $(PROGRAM)
	./$< $(PROGRAM_ARG)
.PHONY: run

test: $(PROGRAM)
	valgrind --leak-check=full $< $(PROGRAM_ARG)
.PHONY: test

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

