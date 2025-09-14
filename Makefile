# =============================================================================
# Project Configuration
# =============================================================================

# Compiler and Linker
CXX = clang++

# Directories
COMMON_DIR = common
PROBLEMS_DIR = problems

# Python settings
PYTHON = python3
PYTEST = pytest

# =============================================================================
# Compiler and Linker Flags
# =============================================================================

# Detect operating system and set Google Test paths accordingly
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	# macOS with Homebrew
	GTEST_LIB_PATH = -I$(shell brew --prefix googletest)/include
	GTEST_LINK_PATH = -L$(shell brew --prefix googletest)/lib
else ifeq ($(UNAME_S),Linux)
	# Linux - check for common installation paths
	ifneq ($(wildcard /usr/local/include/gtest),)
		# Modern installation (from source)
		GTEST_LIB_PATH = -I/usr/local/include
		GTEST_LINK_PATH = -L/usr/local/lib
	else ifneq ($(wildcard /usr/include/gtest),)
		# System-wide installation (apt install libgtest-dev)
		GTEST_LIB_PATH = -I/usr/include
		GTEST_LINK_PATH = -L/usr/lib/x86_64-linux-gnu
	else
		# Fallback - assume pkg-config can find it
		GTEST_LIB_PATH = $(shell pkg-config --cflags gtest 2>/dev/null || echo "")
		GTEST_LINK_PATH = $(shell pkg-config --libs-only-L gtest 2>/dev/null || echo "")
	endif
else
	# Other systems - try pkg-config
	GTEST_LIB_PATH = $(shell pkg-config --cflags gtest 2>/dev/null || echo "")
	GTEST_LINK_PATH = $(shell pkg-config --libs-only-L gtest 2>/dev/null || echo "")
endif

# CXXFLAGS: C++20 standard, all warnings, warning pedantic mode, include common and problems directories
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -I$(COMMON_DIR) -I$(PROBLEMS_DIR) $(GTEST_LIB_PATH)

# LDFLAGS
TEST_LDFLAGS = $(GTEST_LINK_PATH) -lgtest -lgtest_main -pthread
DEBUG_LDFLAGS = -g -DDEBUG

# =============================================================================
# File Discovery
# =============================================================================

# Find all problem directories and extract their names (snake_case)
PROBLEM_DIRS = $(wildcard $(PROBLEMS_DIR)/*)
SNAKE_CASE_PROBLEM_NAMES = $(notdir $(PROBLEM_DIRS))

# Find all cpp source files
COMMON_SRCS = $(wildcard $(COMMON_DIR)/*.cc)
PROBLEM_TEST_SRCS = $(foreach dir,$(PROBLEM_DIRS),$(wildcard $(dir)/*_test.cc))
PROBLEM_SRCS = $(foreach dir,$(PROBLEM_DIRS),$(filter-out $(PROBLEM_TEST_SRCS),$(wildcard $(dir)/*.cc)))

# Find all python test files
PYTHON_TEST_SRCS = $(foreach dir,$(PROBLEM_DIRS),$(wildcard $(dir)/*_test.py))
PYTHON_SRCS = $(foreach dir,$(PROBLEM_DIRS),$(filter-out $(PYTHON_TEST_SRCS),$(wildcard $(dir)/*.py)))

# =============================================================================
# Test Rules
# =============================================================================

# Converter from snake_case to kebab-case
define kebab_to_snake
$(subst -,_,$(1))
endef

.PHONY: test\:%
test\:%:
	@make test-cpp:$* 
	@echo ""
	@make test-py:$*

.PHONY: test-cpp\:%
test-cpp\:%:
	@if [ "$*" = "all" ]; then \
		echo "Running all C++ tests..."; \
		overall_result=0; \
		for dir in $(PROBLEM_DIRS); do \
			if [ -f $$dir/*_test.cc ]; then \
				echo "$(call color_blue,Testing C++ in $$dir...)"; \
				$(CXX) $(CXXFLAGS) $(DEBUG_LDFLAGS) $(TEST_LDFLAGS) -I$(COMMON_DIR) -I$$dir -o $$dir/test_runner $$dir/*.cc; \
				if [ $$? -eq 0 ]; then \
					cd $$dir && ./test_runner --gtest_brief=1 --gtest_color=yes; \
					test_result=$$?; \
					if [ $$test_result -ne 0 ]; then \
						overall_result=$$test_result; \
					fi; \
					rm -f $$dir/test_runner; \
					cd - > /dev/null; \
				else \
					echo "$(call color_red,Failed to compile tests in $$dir)"; \
					overall_result=1; \
				fi; \
				if [ "$$dir" != "$(lastword $(PROBLEM_DIRS))" ]; then \
					echo ""; \
				fi; \
			fi; \
		done; \
		make clean SILENT=true; \
		exit $$overall_result; \
	else \
		snake_case_name=$(call kebab_to_snake,$*); \
		if [ -f $(PROBLEMS_DIR)/$$snake_case_name/$${snake_case_name}_test.cc ]; then \
			echo "$(call color_blue,Running C++ tests for $*...)"; \
			$(CXX) $(CXXFLAGS) $(DEBUG_LDFLAGS) $(TEST_LDFLAGS) -I$(COMMON_DIR) -I$(PROBLEMS_DIR)/$$snake_case_name -o $(PROBLEMS_DIR)/$$snake_case_name/test_runner $(PROBLEMS_DIR)/$$snake_case_name/*.cc; \
			if [ $$? -eq 0 ]; then \
				cd $(PROBLEMS_DIR)/$$snake_case_name && ./test_runner --gtest_color=yes; \
				test_result=$$?; \
				rm -f $(PROBLEMS_DIR)/$$snake_case_name/test_runner; \
				cd - > /dev/null; \
				make clean SILENT=true; \
				exit $$test_result; \
			else \
				echo "$(call color_red,Failed to compile tests for $*)"; \
				exit 1; \
			fi; \
		else \
			echo "$(call color_red,No C++ test file found for $*.)"; \
			exit 1; \
		fi; \
	fi
	@make clean SILENT=true

.PHONY: test-py\:%
test-py\:%:
	@if [ "$*" = "all" ]; then \
		echo "Running all Python tests..."; \
		overall_result=0; \
		for dir in $(PROBLEM_DIRS); do \
			if [ -f $$dir/*_test.py ]; then \
				echo "$(call color_blue,Testing Python in $$dir...)"; \
				cd $$dir && $(PYTEST) *_test.py --color=yes; \
				test_result=$$?; \
				if [ $$test_result -ne 0 ]; then \
					overall_result=$$test_result; \
				fi; \
				cd - > /dev/null; \
				echo ""; \
			fi; \
		done; \
		make clean SILENT=true; \
		exit $$overall_result; \
	else \
		snake_case_name=$(call kebab_to_snake,$*); \
		if [ -f $(PROBLEMS_DIR)/$$snake_case_name/$${snake_case_name}_test.py ]; then \
			echo "$(call color_blue,Running Python tests for $*...)"; \
			cd $(PROBLEMS_DIR)/$$snake_case_name && $(PYTEST) $${snake_case_name}_test.py -v --color=yes; \
		else \
			echo "$(call color_red,No Python test file found for $*.)"; \
			exit 1; \
		fi; \
	fi
	@make clean SILENT=true

# =============================================================================
# Code Quality Rules
# =============================================================================

.PHONY: format
format:
	@make format-cpp
	@echo ""
	@make format-py

.PHONY: format-cpp
format-cpp:
	@echo "Formatting C++ files..."
	@if command -v clang-format >/dev/null; then \
		find $(COMMON_DIR) $(PROBLEMS_DIR) -name '*.cc' -o -name '*.h' | xargs clang-format -i; \
		echo "$(call color_green,C++ files formatted.)"; \
	else \
		echo "$(call color_red,clang-format not found. Please install it to format C++ files.)"; \
	fi

.PHONY: format-py
format-py:
	@echo "Formatting Python files..."
	@if command -v ruff >/dev/null; then \
		ruff format $(PROBLEMS_DIR); \
		echo "$(call color_green,Python files formatted with ruff.)"; \
	elif command -v black >/dev/null; then \
		find $(PROBLEMS_DIR) -name '*.py' | xargs black; \
		echo "$(call color_green,Python files formatted with black.)"; \
	else \
		echo "$(call color_red,Neither ruff nor black found. Please install one of them to format Python files.)"; \
	fi

.PHONY: lint
lint:
	@make lint-cpp
	@echo ""
	@make lint-py

.PHONY: lint-cpp
lint-cpp:
	@echo "Linting C++ files..."
	@if command -v clang-tidy >/dev/null; then \
		find $(PROBLEMS_DIR) $(COMMON_DIR) -type f \( -name '*.cc' -o -name '*.h' \) -print0 | \
		xargs -0 -P 4 -I {} clang-tidy {} --config-file=.clang-tidy --quiet --header-filter="^(problems|common)/.*\\.(h|cc)$$" -- $(CXXFLAGS) -x c++ 2>/dev/null | \
		grep -E "^[^:]+:[0-9]+:[0-9]+:" || true; \
		echo "$(call color_green,C++ linting complete.)"; \
	else \
		echo "$(call color_red,clang-tidy not found. Please install it to lint C++ files.)"; \
	fi

.PHONY: lint-py
lint-py:
	@echo "Linting Python files..."
	@if command -v ruff >/dev/null; then \
		ruff check $(PROBLEMS_DIR); \
		echo "$(call color_green,Python linting complete with ruff.)"; \
	elif command -v flake8 >/dev/null; then \
		find $(PROBLEMS_DIR) -name '*.py' | xargs flake8; \
		echo "$(call color_green,Python linting complete with flake8.)"; \
	else \
		echo "$(call color_red,Neither ruff nor flake8 found. Please install one of them to lint Python files.)"; \
	fi

# =============================================================================
# Utility Rules
# =============================================================================

.PHONY: clean
clean:
	@if [ "$(SILENT)" != "true" ]; then \
		echo "Cleaning build artifacts..."; \
	fi
	@find $(PROBLEMS_DIR) -type f -executable -not -name "*.py" -not -name "*.cc" -not -name "*.h" -delete 2>/dev/null || true
	@find $(PROBLEMS_DIR) -name "test_runner" -delete 2>/dev/null || true
	@find $(PROBLEMS_DIR) -name "test_runner.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	@find $(PROBLEMS_DIR) -name "*_debug" -delete 2>/dev/null || true
	@find $(PROBLEMS_DIR) -name "__pycache__" -type d -exec rm -rf {} + 2>/dev/null || true
	@find $(PROBLEMS_DIR) -name "*.pyc" -delete 2>/dev/null || true
	@find $(PROBLEMS_DIR) -name ".pytest_cache" -type d -exec rm -rf {} + 2>/dev/null || true
	@if [ "$(SILENT)" != "true" ]; then \
		echo "$(call color_green,Clean complete.)"; \
	fi

# Show project statistics
.PHONY: stats
stats:
	@echo "=== Project Statistics ==="
	@echo "$(call color_green,Problems found:) $(words $(SNAKE_CASE_PROBLEM_NAMES))"
	@echo "$(call color_green,C++ sources:) $(words $(COMMON_SRCS) $(PROBLEM_SRCS))"
	@echo "$(call color_green,C++ tests:) $(words $(PROBLEM_TEST_SRCS))"
	@echo "$(call color_green,Python sources:) $(words $(PYTHON_SRCS))"
	@echo "$(call color_green,Python tests:) $(words $(PYTHON_TEST_SRCS))"
	@echo ""
	@echo "Available problems:"
	@for prob in $(SNAKE_CASE_PROBLEM_NAMES); do echo "  $(call color_cyan,- $$prob)"; done

# Update README badges with current problem counts
.PHONY: update-badges
update-badges:
	@echo "Updating README badges..."
	@./scripts/update_badges.sh
	@echo "$(call color_green,README badges updated.)"

# README Generation
.PHONY: readme
readme: ## Generate README from problem configurations
	@$(PYTHON) scripts/generate_readme.py

.PHONY: readme-check
readme-check: ## Check if README is up to date
	@echo "Checking if README is up to date..."
	@cp README.md README.md.backup
	@$(PYTHON) scripts/generate_readme.py > /dev/null
	@if ! diff -q README.md README.md.backup > /dev/null; then \
		echo "$(call color_yellow,README is out of date. Run 'make readme' to update.)"; \
		mv README.md.backup README.md; \
		exit 1; \
	else \
		echo "$(call color_green,README is up to date.)"; \
		rm README.md.backup; \
	fi

# Debug Google Test configuration
.PHONY: debug-gtest
debug-gtest:
	@echo "=== Google Test Configuration Debug ==="
	@echo "$(call color_green,Operating System:) $(UNAME_S)"
	@echo "$(call color_green,Google Test Include Path:) $(GTEST_LIB_PATH)"
	@echo "$(call color_green,Google Test Link Path:) $(GTEST_LINK_PATH)"
	@echo "$(call color_green,Test Linker Flags:) $(TEST_LDFLAGS)"
	@echo ""
	@echo "$(call color_yellow,Checking Google Test installation:)"
	@if [ "$(UNAME_S)" = "Darwin" ]; then \
		if command -v brew >/dev/null 2>&1; then \
			if brew list googletest >/dev/null 2>&1; then \
				echo "$(call color_green,✓ Google Test installed via Homebrew)"; \
			else \
				echo "$(call color_red,✗ Google Test not found via Homebrew. Install with: brew install googletest)"; \
			fi; \
		else \
			echo "$(call color_red,✗ Homebrew not found)"; \
		fi; \
	elif [ "$(UNAME_S)" = "Linux" ]; then \
		if [ -f /usr/local/include/gtest/gtest.h ]; then \
			echo "$(call color_green,✓ Google Test headers found in /usr/local/include (modern installation))"; \
		elif [ -f /usr/include/gtest/gtest.h ]; then \
			echo "$(call color_green,✓ Google Test headers found in /usr/include (system installation))"; \
		else \
			echo "$(call color_red,✗ Google Test headers not found)"; \
			echo "$(call color_yellow,Install with: sudo apt-get install libgtest-dev)"; \
			echo "$(call color_yellow,Or build from source: git clone https://github.com/google/googletest.git && cd googletest && mkdir build && cd build && cmake .. && make && sudo make install)"; \
		fi; \
		if [ -f /usr/local/lib/libgtest.a ] || [ -f /usr/local/lib/libgtest.so ]; then \
			echo "$(call color_green,✓ Google Test libraries found in /usr/local/lib (modern installation))"; \
		elif [ -f /usr/lib/x86_64-linux-gnu/libgtest.a ] || [ -f /usr/lib/x86_64-linux-gnu/libgtest.so ]; then \
			echo "$(call color_green,✓ Google Test libraries found in /usr/lib/x86_64-linux-gnu (system installation))"; \
		else \
			echo "$(call color_red,✗ Google Test libraries not found)"; \
			echo "$(call color_yellow,For system installation: sudo apt-get install libgtest-dev && cd /usr/src/gtest && sudo cmake . && sudo make && sudo cp lib/*.a /usr/lib/x86_64-linux-gnu/)"; \
			echo "$(call color_yellow,Or build from source: git clone https://github.com/google/googletest.git && cd googletest && mkdir build && cd build && cmake .. && make && sudo make install)"; \
		fi; \
	fi

# =============================================================================
# Git Hooks
# =============================================================================

# Install Git hooks
.PHONY: install-hooks
install-hooks: ## Install Git hooks for code quality
	@echo "Installing Git hooks..."
	@cp hooks/pre-commit .git/hooks/pre-commit
	@chmod +x .git/hooks/pre-commit
	@echo "$(call color_green,Git hooks installed successfully.)"

# Uninstall Git hooks
.PHONY: uninstall-hooks
uninstall-hooks: ## Uninstall Git hooks
	@echo "Uninstalling Git hooks..."
	@rm -f .git/hooks/pre-commit
	@echo "$(call color_green,Git hooks uninstalled.)"

# =============================================================================
# Help and Documentation
# =============================================================================

.PHONY: help
help:
	@echo "$(call color_blue,=== LeetCode Project Help ===)"
	@echo ""
	@echo "$(call color_yellow,Test Targets:)"
	@echo "  test-cpp:all       		- Run all C++ tests"
	@echo "  test-cpp:PROBLEM   		- Run C++ tests for specific problem (kebab-case)"
	@echo "  test-py:all        		- Run all Python tests"
	@echo "  test-py:PROBLEM    		- Run Python tests for specific problem (kebab-case)"
	@echo ""
	@echo "$(call color_yellow,Code Quality Targets:)"
	@echo "  format             		- Format all code (C++ and Python)"
	@echo "  format-cpp         		- Format C++ code only"
	@echo "  format-py          		- Format Python code only"
	@echo "  lint               		- Lint all code (C++ and Python)"
	@echo "  lint-cpp           		- Lint C++ code only"
	@echo "  lint-py            		- Lint Python code only"
	@echo ""
	@echo "$(call color_yellow,Utility Targets:)"
	@echo "  clean              		- Clean build artifacts"
	@echo "  stats              		- Show project statistics"
	@echo "  readme             		- Generate README from problem configurations"
	@echo "  readme-check       		- Check if README is up to date"
	@echo "  update-badges      		- Update README badges with current problem counts"
	@echo "  install-hooks      		- Install Git hooks for code quality"
	@echo "  uninstall-hooks    		- Uninstall Git hooks"
	@echo "  debug-gtest        		- Debug Google Test configuration"
	@echo "  help               		- Show this help message"
	@echo ""
	@echo "$(call color_green,Examples:)"
	@echo "  make test-cpp:two-sum  	- Test C++ solution for two-sum"
	@echo "  make test-py:all       	- Run all Python tests"
	@echo "  make format			- Format all source files"
	@echo ""
	@echo "$(call color_cyan,Available problems:) $(SNAKE_CASE_PROBLEM_NAMES)"

# =============================================================================
# Color Functions
# =============================================================================

# Color definitions
define color_blue
\033[1;34m$(1)\033[0m
endef

define color_green
\033[1;32m$(1)\033[0m
endef

define color_yellow
\033[1;33m$(1)\033[0m
endef

define color_cyan
\033[1;36m$(1)\033[0m
endef

define color_reset
\033[0m
endef