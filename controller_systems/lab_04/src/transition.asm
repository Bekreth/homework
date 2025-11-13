.global __start
.global .resetvec

.define R4, previous
.define R5, current
.define R6, not_previous
.define R7, not_current
.define R8, bottom_half
.define R9, totoal


.text
__start:
	mov.w #0x5A80, 0x015C;

	mov.w #0xAB21 previous
	mov.w #0xF22C current
	inv.w R4 not_previous
	inv.w R5 not_current

	mov.w #0xFF00 top_half
	and.w not_previous top_half
	and.w current top_half

	mov.w #0x00FF bottom_half
	and.w not_current bottom_half
	and.w previous bottom_half


	mov.w top_half total
	bis.w bottom_hal total
