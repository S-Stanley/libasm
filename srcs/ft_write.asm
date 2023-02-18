BITS 64

global ft_write

ft_write:
    mov rax, 1      ; add write syscall
    syscall
    ret