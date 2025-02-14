SOURCE_FILE:=$(shell find src -type f | \
	grep -E '*.c$$' | \
	sed -r 's|src|build|' | \
	sed -r 's|\.c|\.o|')

clean:
	rm build/*

build/:
	@mkdir $@

build/%.o: src/%.c Makefile| build/
	gcc -g -c -o $@ $<

build/main: ${SOURCE_FILE} | build/
	gcc -o $@ $(SOURCE_FILE) -lm 

run: build/main
	$<

debug: build/main
	gdb $<

build/flow_%.png: docs/flow_%.dot | build/
	@dot $< -Tpng -o $@

charts: build/flow_1.png build/flow_2.png build/flow_3.png 
