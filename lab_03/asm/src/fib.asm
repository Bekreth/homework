.global fib

.section .data

.section .text
# N input @ rdi
fib:
	push %rbp
	mov %rsp, %rbp
	push %rdi

string_array:
	mov %rdi, %rsi # Length
	mov $0, %rdi # Address
	mov $3, %rdx # Prot
	mov $0x22, %r10 # Flags
	mov $-1, %r8 # FD
	mov $0, %r9 # Offset
	mov $9, %rax # mmap
	syscall
	pop %rdi
	push %rax

	mov $1, %rsi
	mov $0, %r10
	mov $0, %r11

fib_loop:
	add %r10, %rsi
	call store_stars
	mov %rsp, %r8
	add $8, %r8
	mov %rax, %r8
	inc %r11
	cmp %r11, %rdi
	jne fib_loop

end_fib:
	pop %rax
	mov %rbp, %rsp
	pop %rbp
	ret

# rdi 
# rsi length
# rdx 
# r10
# r8
# r9
#
# rax Address returned
store_stars:
	push %rbp
	mov %rsp, %rbp
	push %rsi

	#mov (%rdi)+(%rsi), %rdi # Address
	mov $0, %rdi # Address
	#mov %rsi, %rsi # Length
	mov $3, %rdx # Prot
	mov $0x22, %r10 # Flags
	mov $-1, %r8 # FD
	mov $0, %r9 # Offset
	mov $9, %rax # mmap
	syscall

	pop %rsi
	push %rax
	mov $0, %rdi

_store_stars_loop:
	mov %rdi, %r8
	imul $8, %r8
	add %rax, %r8
	mov $42, (%r8)
	inc %rdi
	cmp %rdi, %rsi
	jne _store_stars_loop

_end_store_stars:
	mov %rbp, %rsp
	pop %rbp
	pop %rax
	ret
