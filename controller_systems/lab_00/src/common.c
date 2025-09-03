#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "common.h"

uint8_t P3OUT = 0;

//Prints formatted HEX and BIN values of the P3OUT
void hexPortDisplay() {
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
	P3OUT = 0xF0;
	binaryPortDisplay();

	// Clear bits 7, 5
	uint8_t clear_bits = 0b01011111;
	P3OUT &= clear_bits;
	binaryPortDisplay();

	// Set bits 3, 2
	uint8_t set_bits = 0b00001100;
	P3OUT |= set_bits;
	binaryPortDisplay();
}

void bitWiseEx2() {
	P3OUT = 0xA5;// 10100101
	binaryPortDisplay();
	for (int i = 0; i < 8; i++) {
		printf("%d - ", i);
		uint8_t toggle_bit = (1 << i);
		P3OUT ^= toggle_bit;
		binaryPortDisplay();
	}
}

void bitWiseEx3(uint8_t* array, uint8_t length) {
	for (int i = 0; i < length; i++) {
		uint8_t message = array[i];
		printf("\n");
		printf("Byte to serialize: \n");
		P3OUT = message;
		binaryPortDisplay();
		P3OUT = 0x00;
		for (int j = 0; j < 8; j++) {
			uint8_t select_bit = (1 << j);
			P3OUT = (message & select_bit) > 0;
			printf("%d - ", j);
			binaryPortDisplay();
		}
	}
}

