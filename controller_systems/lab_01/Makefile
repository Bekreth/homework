BINS:=/home/bekreth/local_git/msp430/msp430_gcc/msp430-gcc-9.3.1.11_linux64/bin
CC:=${BINS}/msp430-elf-gcc
AS:=${BINS}/msp430-elf-as
LD:=${BINS}/msp430-elf-ld

HARDWARE:=msp430f5529

INCLUDE_DIR:=/home/bekreth/local_git/msp430/msp430-gcc-support-files/include

CFLAGS = -I src -I ${INCLUDE_DIR} -mmcu=${HARDWARE} -g
LFLAGS = -L ${INCLUDE_DIR} -T ${HARDWARE}.ld -e 0x4400

SOURCE_FILE:=$(shell find src -type f | \
	grep -E '*.asm$$' | \
	sed -r 's|src|build|' | \
	sed -r 's|\.asm|\.o|')

clean:
	rm -rf build/*

build/:
	mkdir $@

build/%.o: src/%.asm Makefile | build/
	${AS} -g -o $@ $<

build/main: ${SOURCE_FILE} | build/
	${LD} ${LFLAGS} -o $@ $^

