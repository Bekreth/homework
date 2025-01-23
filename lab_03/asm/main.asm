.global _start
.section .text
_start:

	call get_user_input

	mov %rax, %rdi
	push %rax
	call factorial

	pop %rdi
	push %rax
	call fib

	mov $60, %rax
	syscall
