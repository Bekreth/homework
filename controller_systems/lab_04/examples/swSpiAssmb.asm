;-------------------------------------------------------------------------------
; swSpiAsmb.asm
;
; Template file for Lab 4 to implement SPI in assembler
;
; Author:  Greg Scutt, Oct 2021
;-------------------------------------------------------------------------------


            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main code here
;-------------------------------------------------------------------------------
ramS0Base	.equ 0x2400				; base addresses of data to serialize
OneKB		.equ 0x1024				; 1KB definition

			;.define BIT0, SOUT		; P3OUT<0>
			;.define BIT1, SCLK		; P3OUT<1>
			.define R12, buffer	; R12 points to the array of data
			.define R13, buffer_size	; numBytes of data stoared in R13

			.define R5, bit_counter
			.define R6, byte_counter

			.define R7, byte
			.define R8, bit_counter

PORT_INIT:										; initialize the required PORTS
	mov.w #BIT0|BIT1, &P3DIR	
	clr.w &P3OUT	
	


MAIN:  											; MAIN is the firmware super-loop
	mov.w #ramS0Base, buffer			; 3  provide address of bytes to serialize
	mov.w buffer_size, byte_counter				; 3  load counter with number of bytes to serialize

	;  show the number of cycles for each instruction in the adjacent comment
	;  jumps of any kind are always 2, NOPs are 1

BYTE_LOOP: ;  the outer loop to go through all the bytes
	mov.b &buffer(byte_counter), byte
	mov.b #7, bit_counter
BIT_LOOP: 	; the inner loop to go serialize all the bits within a byte and output them with SCLK on P3OUT
		
	rlc byte                         ; 3
	cmp R2, #C                       ; 1
	je SOUT_HIGH                     ; 2
	jmp SOUT_LOW                     ; 2

	SOUT_HIGH:
		bis.w #BIT0, &P3OUT            ; 2
		jmp SCLK                       ; 2
		
	SOUT_LOW:
		bic.w #BIT0, &P3OUT            ; 2
		jmp SCLK                       ; 2

SCLK:
	xor.w #BIT1, &P3OUT              ; 2
	dec bit_counter                  ; 2
	jne BIT_LOOP	                   ; 2

END_BIT:

	inc byte_counter                 ;
	cmp byte_counter, buffer_size    ;
	jne BYTE_LOOP                    ; 2

END_BYTE:
	jmp MAIN							           ; 2
	NOP									             ; 1


;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
