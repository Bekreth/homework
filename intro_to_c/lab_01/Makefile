

build/:
	@mkdir $@

build/main.o: src/main.c Makefile | build/
	@gcc -g $< -o $@

run: build/main.o
	@./build/main.o
