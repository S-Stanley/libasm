BITS 64

global ft_strcpy

ft_strcpy:
	mov rax, 0			; init iterator at 0
	jmp L1				;  start the loop

L1:
	cmp BYTE [rsi + rax], 0		; check if string source is null
	je L2				; if null, then the loop end
	mov rdx, [rsi + rax]		; use buffer to add char into rdx
	mov [rdi + rax], rdx		; copy char from source string to dest string
	inc rax				; increment iterator
	jmp L1				; continue the loop

L2:
	mov rdx, 0			; add null-terminating char to rdx
	mov [rdi + rax], rdx		; add null-terminating char to dest string
	mov rax, rdi			; copy rsi (dest string) into rax for return
	ret
