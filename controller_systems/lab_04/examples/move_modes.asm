;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
; ROBT3356 Lab3. Use this file for 4.2.1, 4.2.2
; Greg Scutt
; Oct 1, 2016
;
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

;			.define R5, COUNTER
;COUNT1 		.equ 5000

;-------------------------------------------------------------------------------
; Main loop here



MAIN_LOOP:
			;  single step through these basic moves with the addresssing modes
			; observe the PC, memory and registers R4,R5.

			mov.w #0xaa55, &0x2400		;  	src immediate,  dst absolute
			mov.w #0x2400, R4			;	src immediate, dst reg direct
			mov.w R4, R5				;	src reg direct, dst reg direct
			mov.w @R5, 2(R4)			;	src reg indirect, dst indexed.
										; 	do you see how 0x2402 received the same data ?
			; ****************************************************************************
			; now observe how 20 bit registers are overwritten with .b moves
			mov.b #0x35, &0x2405		; write 0x35 to 0x2405. note odd address is ok for .b right ? Yes.
			mov.b #0x78, R5				; observe bits 19:16 are cleared in R5 !! defn of .b move to register
			mov.w R5,4(R4)				; now only 0x78 should appear in the 0x2004
										; verify 0x2405 is now cleared. Do you understand why this happened?

			; ***************************************************************************
			; bit wise operations. Please read about these instructions in 6.6.2 of user guide.
			; set all odd bits in address 0x2400. Observe PC, mem and relavent registers.
			mov.w #0, &0x2400			; first clear mem location 0x2400. could also use clr.w
			bis.w #0x5555, &0x2400		; set bits with bis. source operand is acting as a mask
			bic.w #0x5555, &0x2400		; clear bits with bic. source operand is acting as a mask


			clr.b &P1DIR				; use emulated instruction clr to clear the P1DIR register.   see section 6.5.1.4 of user manual for clr
			mov.b #0xC8, &P1DIR			; let's assume that P1DIR alraeady has some bits set in it defined by 0xC8
			mov.b #0x43, R4				; use R4 as a mask. Load it with  0x43
			bis.b R4, &P1DIR			; now set direction bits dictated by the mask in the P1DIR register. verify P1DIR bits that got set
										; verify all other bits were left alone.
										; understand these bitwise  instructions !!!! ask questions if something is not clear.

			; we can toggle bis too with an xor
			xor.b #0xAA, &P1OUT			; toggle even bits of P1OUT
										; try doing this with an addressing mode where the mask is
										; pointed to by an address in memory, and also a register.
										; experiment with xor.b  and registers as the destination. Again, what do you notice with the upper bits 19:8?



			jmp MAIN_LOOP					; if so then jump back to main loop
			NOP
;-------------------------------------------------------------------------------

                                            

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
            
