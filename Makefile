SRC_DIRS := ./src
TEST_DIRS := ./test
CLANGTIYD_FILE := ./.clang-tidy

SRC_FILES := $(shell find $(SRC_DIRS) -name '*.cc' -or -name '*.h')
TEST_FILES := $(shell find $(TEST_DIRS) -name '*.cc' -or -name '*.h')
ALL_FILES := $(SRC_FILES) $(TEST_FILES)

format:
	-@clang-format -i $(ALL_FILES)
	@echo "$(words $(ALL_FILES)) files are formatted, done!"

tidy:
	-@clang-tidy --quiet $(ALL_FILES) -- -x c++ -fno-caret-diagnostics -I .
	@echo "$(words $(ALL_FILES)) files are checked, done!"

clean:
	-@bazel clean

.PHONY: format tidy clean
