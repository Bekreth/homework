#include <msp430f5529.h>
__start:
	mov.w #0x52A8, &0x015C ; WDTCTL PW|HOLD
	mov.w #0x0001, &0x0204 ; P1DIR
	mov.w #0x0001, &0x0202 ; P1DIR

.reset:
	jmp __start

.global __STACK_END
