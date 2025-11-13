
.global __start
.global .resetvec

.data
ramS0Base: .word 0x2400
ramS1Base: .word 0x2C00
ONE_KB: .word 1024

.text

__start:
	;mov.w #WDTPW|WDTHOLD, &WDTCTL ; WDTCTL PW|HOLD
	;mov.w #0x01, &P2DIR ; P1DIR
	;mov.w #0x01, &P2OUT ; P1DIR
	mov.w #0x5A80, 0x015C;

CPY1:


.resetvec:
	jmp __start
	;mov.w #__STACK_END,SP
