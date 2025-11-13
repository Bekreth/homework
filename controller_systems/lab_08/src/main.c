#include "msp430f5529.h"
#include "encoder.h"

int main() {
	WDTCTL = WDTPW | WDTHOLD;

	init_encoder();

	P1DIR |= BIT0;
	P1OUT &= BIT0;
	unsigned int i = 1;
	while(i) {
		P1OUT ^= BIT0;
		__delay_cycles(50L);
		//for (int j = 0; j < 10; j++) {
		//}
	}
	return 0;
}
