# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -Iinclude
DEBUG_CFLAGS = -g -O0 -DDEBUG
RELEASE_CFLAGS = -O2 -DNDEBUG

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TEST_DIR = tests

# Source files
CORE_SRCS = $(wildcard $(SRC_DIR)/core/*.c)
LINEAR_ALGEBRA_SRCS = $(wildcard $(SRC_DIR)/linear_algebra/*.c)
MODEL_SRCS = $(wildcard $(SRC_DIR)/models/*.c)
UTILS_SRCS = $(wildcard $(SRC_DIR)/utils/*.c)

# Object files
CORE_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(CORE_SRCS))
LINEAR_ALGEBRA_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(LINEAR_ALGEBRA_SRCS))
MODEL_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(MODEL_SRCS))
UTILS_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(UTILS_SRCS))

ALL_OBJS = $(CORE_OBJS) $(LINEAR_ALGEBRA_OBJS) $(MODEL_OBJS) $(UTILS_OBJS)

# Targets
.PHONY: all debug release clean main

all: release

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: emel_lib

release: CFLAGS += $(RELEASE_CFLAGS)
release: emel_lib

# Build the static library
emel_lib: $(ALL_OBJS)
	ar rcs $(BUILD_DIR)/libemel.a $(ALL_OBJS)

# Pattern rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

main: emel_lib
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c -L$(BUILD_DIR) -lemel -lm -o $(BUILD_DIR)/main
	$(BUILD_DIR)/main

clean:
	rm -rf $(BUILD_DIR)