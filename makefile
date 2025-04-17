# Directories and Build Config
BUILD_DIR    := build
SRC_DIRS     := src include
FILE_EXTS    := *.cpp *.cxx *.c *.h *.hpp *.tpp
BUILD_TYPE   ?= DEBUG  # Default to Debug (override with BUILD_TYPE=Release)

# Source files for formatting
SOURCE_FILES := $(shell find $(SRC_DIRS) -type f \( $(foreach ext,$(FILE_EXTS),-name '$(ext)' -o) -false \))

# Default target (help)
all:
	@echo "Available targets:"
	@echo "  make generate  - Generate CMake build system (Debug/Release)"
	@echo "  make compile   - Build project using CMake"
	@echo "  make run       - Run executable"
	@echo "  make format    - Format source code"
	@echo "  make profile   - Run gprof performance profiling"
	@echo "  make clean     - Clean build artifacts"

# CMake Generation (Debug/Release)
generate:
	@mkdir -p $(BUILD_DIR)
	@cmake -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -S . -B $(BUILD_DIR)
	@echo "CMake generated for $(BUILD_TYPE) build"

# CMake Compile
compile:
	@cmake --build $(BUILD_DIR)

# Run executable
run: compile
	@cd $(BUILD_DIR) && ./iori_game_engine

# Format source files
format:
	@echo "Formatting files with clang-format..."
	@clang-format -i --style=Microsoft $(SOURCE_FILES)
	@echo "Formatting complete!"

# Generate profiling results
profile:
	@gprof $(BUILD_DIR)/iori_game_engine $(BUILD_DIR)/gmon.out > $(BUILD_DIR)/profile_results.txt
	@echo "Profile results saved to $(BUILD_DIR)/profile_results.txt"

# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR)/*

.PHONY: all generate compile run format profile clean