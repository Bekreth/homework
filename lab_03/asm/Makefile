SOURCES:=$(shell find -type f -iname "*.asm" | sed 's|\.\/\(.*\).asm|build\/\1.o|')
build/:
	@mkdir $@

build/%.o: %.asm Makefile | build/
	as -g -o $@ $<

build/caller: ${SOURCES} | build/
	ld -o $@ $^
	@chmod 755 $@

run: build/caller
	@$<; echo "\nOutput: " $$?
