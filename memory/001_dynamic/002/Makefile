.PHONY: leak test run clean

CFLAGS =
EXE_STEM := main
DIR_BUILD := build
EXE := $(DIR_BUILD)/$(EXE_STEM)

$(EXE): $(EXE_STEM).c | $(DIR_BUILD)
	gcc $(CFLAGS) $< -o $@

$(DIR_BUILD):
	mkdir $@

leak: CFLAGS = -DLEAK
leak: $(EXE)

test: $(EXE)
	@[[ -n $$(which valgrind) ]] || \
	(echo "\033[031mError:\033[0m valgrind must be installed" \ && exit 1)
	valgrind --leak-check=full $^

run: $(EXE)
	./$<

clean:
	rm -rf $(DIR_BUILD)

