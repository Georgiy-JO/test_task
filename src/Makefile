# Paths
PROJECT_ROOT := $(abspath $(CURDIR)/..)
SRC_DIR      := $(PROJECT_ROOT)/src
BUILD_DIR    := $(PROJECT_ROOT)/build

# Tools
CMAKE := cmake
MAKE  := make

MAKEFLAGS += --no-print-directory

# Default target
.PHONY: all
all: test_task

.PHONY: configure
configure: $(BUILD_DIR)
	@cd $(BUILD_DIR) && \
	$(CMAKE) $(SRC_DIR)

# Build targets
.PHONY: test_task run_test_task
test_task: configure
	@cd $(BUILD_DIR) && $(MAKE) test_task

run_test_task: configure
	@cd $(BUILD_DIR) && $(MAKE) run_test_task


# Tests
.PHONY: tests run_tests
tests: configure
	@cd $(BUILD_DIR) && $(MAKE) tests

run_tests: configure
	@cd $(BUILD_DIR) && $(MAKE) run_tests


# Coverage
.PHONY: coverage open_coverage
coverage: configure
	@cd $(BUILD_DIR) && $(MAKE) coverage

open_coverage: coverage
	@xdg-open $(BUILD_DIR)/tests/coverage/index.html


# Service
.PHONY: clean clean_all

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		cd $(BUILD_DIR) && $(MAKE) clean; \
	fi

clean_all:
	@rm -rf $(BUILD_DIR)
