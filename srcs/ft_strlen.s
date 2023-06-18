BITS 64

global ft_strlen

ft_strlen:
	mov rax, 0			; init iterator to 0
	jmp L1				; start loop

L1:
	cmp BYTE [rdi + rax], 0		; check if string is finish
	je L2				; end the loop
	inc rax				; increment iterator
	jmp L1				; continue the loop

L2:
	ret				; return iterator (rax)
