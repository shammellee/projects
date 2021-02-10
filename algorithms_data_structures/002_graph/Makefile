PROJECT_NAME := myproject
TEST_DIR     := test
SRC_DIR      := src
LIB          := graph
LIB_SOURCE   := $(SRC_DIR)/$(LIB).c
LIB_HEADER   := $(LIB_SOURCE:.c=.h)
BUILD_DIR    := build

CC     := gcc
CFLAGS :=
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -std=c99
CFLAGS += -O0
CFLAGS += -I$(SRC_DIR)

all: test
.PHONY: all

.SECONDEXPANSION:
test: $(TEST_DIR)/$$@_$(LIB).c $(LIB_SOURCE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^
.PHONY: test

$(LIB_SOURCE): $(LIB_HEADER)

$(BUILD_DIR):
	mkdir $@

run:
	$(BUILD_DIR)/test
.PHONY: run

clean:
	$(RM) -rf $(BUILD_DIR)
.PHONY: clean

