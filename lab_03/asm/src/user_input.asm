.global get_user_input

.section .data
prompt: .ascii "What number should we fact/fib?: \t"

.section .text
get_user_input:
	push %rbp
	mov %rsp, %rbp

	mov $1, %rax
	mov $1, %rdi
	mov $prompt, %rsi
	mov $15, %rdx
	syscall

#TODO: Sort out input

	mov $10, %rax
end_get_user_input:
	mov %rbp, %rsp
	pop %rbp
	ret
