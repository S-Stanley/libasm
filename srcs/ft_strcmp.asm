BITS 64

global ft_strcmp

ft_strcmp:
    mov rax, 0                  ; init iterator to 0
    jmp L0                      ; start loop

L0:
    mov bh, byte [rdi + rax]    ; use bh as buffer for s1
    mov bl, byte [rsi + rax]    ; use bl as buffer for s2
    cmp byte bh, 0              ; check if s1 is finish (null terminating char)
    je L1                       ; if finished, jump to L1
    cmp byte bl, 0              ; check if s2 is finish (null terminating char)
    je L2                       ; if finished, jump to L2
    cmp byte bl, bh 		    ; check if s1[x] and s2[x] are differents
    jg L5                       ; if diff greater return 1
    jl L4                       ; if diff lower return -1
    inc rax                     ; increment iterator
    jmp L0                      ; continue loop

L1:
    cmp byte bl, 0              ; check if s2 is also finish
    je L3                       ; if yes return 0
    jmp L5                      ; if not return -1

L2:
   cmp byte bh, 0               ; check if s1 is also finish
   je L3                        ; if yes return 0
   jmp L4                       ; if no return 1

L3:
    mov rax, 0                  ; return 0
    ret                         ; exit function

L4:
    mov rax, 1                  ; return 1
    ret                         ; exit function

L5:
    mov rax, -1                 ; return -1
    ret                         ; exit function
