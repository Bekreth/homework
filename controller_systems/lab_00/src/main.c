#include <stdio.h>

#include "common.h"

int main()
{
    printf("The value of the 8-bit port P3OUT is currently 0\n\n");

    //Set some bits
    printf("Set bits 2 and 5 of P3OUT\n");
    P3OUT |= BIT2 + BIT5;
    hexPortDisplay();

    //Clear the bits
    printf("Clear bit 5 of P3OUT\n");
    P3OUT &= ~BIT5;
    hexPortDisplay();

    //Toggle bits on/off
    printf("Toggle BIT4 on P3OUT\n");
    P3OUT ^= BIT4;
    hexPortDisplay();
    printf("Toggle\n");
    P3OUT ^= BIT4;
    hexPortDisplay();

    //Shift left
    printf("Shift P3OUT 3 bits left.\n");
    P3OUT = P3OUT << 3;
    hexPortDisplay();
    
    //Shift right
    printf("Shift P3OUT 3 bits right.\n");
    P3OUT = P3OUT >> 3;
    hexPortDisplay();

    //Walking ones
    walkingOnesDemo();

    printf("bitWiseEx1.\n");
		bitWiseEx1();

    printf("bitWiseEx2.\n");
		bitWiseEx2();

    printf("bitWiseEx3.\n");
		uint8_t test_array[5] = {
			0xAA,
			0xBB,
			0xCC,
			0xDD,
			0xFF
		};
		bitWiseEx3(&test_array, 5);
}
