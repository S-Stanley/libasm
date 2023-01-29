section .data
	hello: db "Hello world", 10
	helloLen: equ $-hello

global ft_strlen

ft_strlen:
    mov rax,1
    mov rdi,1
    mov rsi,hello
    mov rdx,helloLen
    syscall

    mov rax,60
    mov rdi,0
    syscall

