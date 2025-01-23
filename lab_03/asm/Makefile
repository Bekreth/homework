SOURCE_FILE:=$(shell find src -type f | \
	grep -E '*.asm$$' | \
	sed -r 's|src|build|' | \
	sed -r 's|\.asm|\.o|')

clean:
	rm build/*

build/:
	@mkdir $@

build/%.o: src/%.asm Makefile | build/
	as -g -o $@ $<

build/main: ${SOURCE_FILE} | build/
	ld -o $@ $^
	@chmod 755 $@

run: build/main
	@$<
