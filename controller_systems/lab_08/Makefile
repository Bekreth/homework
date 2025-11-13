CC:=msp430-elf-gcc
LD:=msp430-elf-ld
AS:=msp430-elf-as

CHIP:=msp430f5529

INCLUDE_DIR:=/nix/store/00a090i5paslvp9z7vsd3p4mmkyf43av-msp430-support/include

CFLAGS = -I src -I ${INCLUDE_DIR} -mmcu=${CHIP} -g
LFLAGS = -L ${INCLUDE_DIR} -T ${INCLUDE_DIR}/${CHIP}.ld

build/:
	mkdir $@

build/%.s: src/%.c Makefile | build/
	${CC} ${CFLAGS} -S $< -o $@
	@echo Compiled

build/%.a: build/%.s Makefile | build/
	${AS} $< -o $@
	@echo Assembled

build/blink: build/encoder.a build/main.a 
	${LD} ${LFLAGS} $< -o $@
	@echo Linked
