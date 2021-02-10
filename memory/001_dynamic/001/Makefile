.PHONY: clean

EXE := main
DIR_BUILD := build

$(DIR_BUILD)/$(EXE): $(EXE).c | $(DIR_BUILD)
	gcc $< -o $@

$(DIR_BUILD):
	mkdir $@

clean:
	rm -rf $(DIR_BUILD)

