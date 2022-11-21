SECTION .data
	num1 db 0x4
	num2 db 0x32
	EXIT_STATUS equ 0

SECTION .text
	global _start
	_start:
		mov rax, num1
		mov rdx, num2
		add rax, rax
		sub rax, rdx
		push rax
		
		mov rax, 60
		mov rdi, EXIT_STATUS
		syscall
		
	
