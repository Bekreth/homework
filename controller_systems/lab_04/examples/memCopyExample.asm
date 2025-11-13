;-------------------------------------------------------------------------------
; memCopyExample.asm
;
; Example assembler source file for ROBT 3356
; Demonstates word copy from two locations in memory
; 
; Author:  Greg Scutt, Oct 2018
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
; Main loop here
;-------------------------------------------------------------------------------
ramS0Base	.equ 0x2400				; base addresses
ramS1Base 	.equ 0x2C00
OneKB		.equ 1024				; 1KB definition
			.define R4, ramS0ptr	; pointer defn
			.define R5, ramS1ptr
			.define R7, index	

MAIN_LOOP:
			mov.w #ramS0Base, ramS0ptr	; set up the pointers to RAM
			mov.w #ramS1Base, ramS1ptr	; true this one may not be used ...
			clr.w index					; clear index counter.  emulated with mov.w #0, dst
		

Copy1:	
	mov.w @ramS0ptr+, ramS1Base(index) ; 5 cycles
	incd index								         ; 3 cycles
	cmp.w #OneKB, index                ; 3 cycle
End_Copy1: 	jne CPY1
 	
	mov.w #OneKB, index
	
Copy2:		; do it again but try to make CPY1 more efficient by avoiding a cmp statement
	mov.w @ramS0ptr+, ramS1Base(index) ; 5 cycles
	decd index								         ; 3 cycles ; possible OBO error, keep an eye out
End_Copy2:
	jne CPY2

Copy3:		; do it again but try to do it with a while-do loop using indexed mode in both src and dst of the mov statement	
	clr.w index
While:
	cmp #OneKB, index                  ; 3 cycles
	jeq Continue
	mov.w @ramS0ptr+, ramS1Base(index) ; 5 cycles
	incd index								         ; 3 cycles
	jmp While
Continue:
End_Copy3:

DONE:		
	jmp MAIN_LOOP							; if so then jump back to main loop
	NOP					
			
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
            
