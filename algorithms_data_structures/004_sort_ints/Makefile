PROJECT_NAME := sort
SRC_DIR      := src
SOURCES      := $(wildcard $(SRC_DIR)/*.c)
BUILD_DIR    := build
PROGRAM      := $(BUILD_DIR)/$(PROJECT_NAME)

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
	./$<
.PHONY: run

test: $(PROGRAM)
	valgrind --leak-check=full $<
.PHONY: test

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

