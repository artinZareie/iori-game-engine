# Makefile for running clang-format

# Directories to search for source files
SRC_DIRS := src include

# File extensions to format
FILE_EXTS := *.cpp *.cxx *.c *.h *.hpp *.tpp

# Find all source files recursively
SOURCE_FILES := $(shell find $(SRC_DIRS) -type f \( $(foreach ext,$(FILE_EXTS),-name '$(ext)' -o) -false \))
BUILD_DIR	 := build

# Default target (does nothing by default)
all:
	@echo "Available targets:"
	@echo "  make format    - Format source code"
	@echo "  make profile   - Run gprof performance profiling"
	@echo "  make clean     - Remove build artifacts"

# Format all source files
format:
	@echo "Formatting files with clang-format..."
	@clang-format -i --style=Microsoft $(SOURCE_FILES)
	@echo "Formatting complete!"
	@echo "Formatted files: " $(SOURCE_FILES)

profile:
	@echo "Generating profiling results..."
	@gprof $(BUILD_DIR)/iori_game_engine $(BUILD_DIR)/gmon.out > $(BUILD_DIR)/profile_results.txt
	@echo "Profile results saved to $(BUILD_DIR)/profile_results.txt"

# Clean build artifacts (example)
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf build/*

.PHONY: all format clean