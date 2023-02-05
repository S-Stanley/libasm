global loopstr

; this function print each caractere of a string in the stdout
; first parameter rdi is the string
; second parameter, rsi, is the len of the string

loopstr:
	mov rax, 0	; initilize iterator to 0
	jmp L1		; launch the loop
L1:
	cmp rax, rsi	; compare iterator with len of string
	je L2		; if equal, quit function and return the len of the string
	inc rax		; increment iterator
	jmp L1		; get back to beginning of the loop
L2:
	ret
