#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "common.h"

uint8_t P3OUT = 0;

//Prints formatted HEX and BIN values of the P3OUT
void hexPortDisplay(){
	printf("The HEX value of P3OUT is: %#4.2hhX\n", P3OUT);
	printf("The BINARY value is: ");
	binaryPortDisplay();
	printf("\n");
}

//Prints only the binary value of the P3OUT
void binaryPortDisplay() {
	for (int i = 0; i < 8; i++) {
		if ((P3OUT & (0x01 << (7 - i))) == (0x01 << (7 - i))){
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

//The walking ones demo
void walkingOnesDemo() {
	//Direction flag
	bool direction = true;
	//Initialize
	P3OUT = 0x01;

	printf("Walking ones demo shifting left and right.\n");
	for (int i = 0; i < 2; i++) {
		binaryPortDisplay();
		if (direction) {
			P3OUT = P3OUT << 1;
			if (P3OUT == 0x80) {
				direction = false;
			}
		} else {
			P3OUT = P3OUT >> 1;
			if (P3OUT == 0x01) {
				direction = true;
			}
		}
		sleep(0.5);
	}
	P3OUT = 0x01;
	binaryPortDisplay();
}

void bitWiseEx1() {
}

void bitWiseEx2() {
}

void bitWiseEx3() {
}

