.global factorial

.section .data

.section .text
factorial:
	push %rbp
	mov %rsp, %rbp

	mov $1, %rax
	mov %rdi, %r10
	mov $1, %r11
_factorial:
	imul %r10, %rax
	dec %r10
	cmp %r11, %r10
	jne _factorial

end_factorial:
	mov %rbp, %rsp
	pop %rbp
	ret
