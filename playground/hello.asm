section .data
	hello: DB "hello world", 10
	helloLen: equ $-hello


section .text

	global _start

	_start:
		mov rsi, hello
		mov rdx, helloLen
		mov rax, 1; sys_write
		mov rdi, 1; stdout
		syscall

		mov rax, 60; sys_exit
		mov rdi, 0; exit_status
		syscall	
