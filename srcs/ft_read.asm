BITS 64

global ft_read

ft_read:
    mov rax, 0      ; add read syscall number
    syscall
    ret