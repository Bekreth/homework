SOURCE_FILE:=$(shell find -type f | \
	grep -E '*.c$$' | \
	sed -r 's/\./build/' | \
	sed -r 's/\.c/\.o/')

E:
	echo $(SOURCE_FILE)

build/:
	@mkdir $@

build/%.o: %.c Makefile| build/
	gcc -g -c -o $@ $<

build/main: ${SOURCE_FILE} | build/
	gcc -o $@ $(SOURCE_FILE)
