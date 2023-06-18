BITS 64

extern malloc
extern ft_strlen

global ft_strdup

; malloc first and only parameter is rdi (or edi) return is in rax register

ft_strdup:
    call ft_strlen		; call strlen to get len of string, result are store in rax
    mov rcx, rax		; move len of string in rcx as buffer
    mov rbx, rdi		; move parameter (string to dup) into rsi
    mov rdi, rcx     		; number of bits to allocate
    call malloc WRT ..plt	; call malloc
    mov rdx, rax		; move result of malloc into rdx
    mov rax, 0			; set iterator to 0
    jmp L1			; start the loop

L1:
    cmp byte [rbx + rax], 0	; check if string is finished
    je L2			; string is finished
    mov rcx, [rbx + rax]	; use rcx for buffer cher
    mov [rdx + rax], rcx	; add char to rcx
    inc rax			; increment iterator
    jmp L1			; continue loop

L2:
    mov byte [rdx + rax], 0	; add null terminating-char
    mov rax, rdx		; move rdx to rax for return
    ret
