section .data
    hello:  db "Hello world", 10

section .text
    global  _start

    _start:
        mov rax,1
        mov rdi,1
        mov rsi,hello
        mov rdx,10
        syscall

        mov rax,60
        mov rdi,0
        syscall
