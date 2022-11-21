SECTION .data
	msg times 1024 db 0x41
	EXIT_STATUS equ 0

SECTION .text
	global _start
	_start:
		mov rax, msg
		push rax

		mov rax, 60
		mov rdi, EXIT_STATUS
		syscall
