.global fib

.section .data
hello_fib: .ascii "Hello Baeldung\n"

.section .text
fib:
	push %rbp
	mov %rsp, %rbp

	mov $1, %rax
	mov $0, %r10
	push %r10
	mov $0, %r11
_fib:
	pop %r10
	push %rax
	add %r10, %rax
	dec %rdi
	cmp %r11, %rdi
	jne _fib

end_factorial:
	mov %rbp, %rsp
	pop %rbp
	ret
