SECTION .data
	msg db "Nofil", 0xa
	EXIT_STATUS equ 54
SECTION .bss
SECTION .text
	global _start
	_start:
	mov rax,1
	mov rdi,1
	mov rsi,msg
	mov rdx,26
	syscall ;write()
	mov rax,60
	mov rdi, EXIT_STATUS
	syscall ;exit()
