BITS 64

global ft_read

extern __errno_location

ft_read:
    mov rax, 0      ; add read syscall number
    syscall
    cmp rax, 0
    jl L1
    ret

L1:
    mov rdi, -1                     ; add -1 to rdi for multiplication on next line
    mul rdi                         ; multiply rdi with rax to set errno to positive
    mov rdi, rax                    ; use rdi as buffer of rax
    call __errno_location WRT ..plt ; add errno location to rax
    mov [rax], rdi                  ; add result of write syscall to rax addr (errno)
    mov rax, -1                     ; set -1 as return value
    ret