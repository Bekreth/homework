#include "msp430f5529.h"
#include "encoder.h"

int main() {
	WDTCTL = WDTPW | WDTHOLD;

	init_encoder();

	while(i) {
		update_encoder_state();
	}
	return 0;
}
