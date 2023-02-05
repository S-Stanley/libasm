global putstr

; first parameter is store in rdi
; second parameter is store in rsi

putstr:
	mov rdx, rsi	; len of parameter
	mov rsi, rdi	; move parameter in rsi
	mov rax, 1	; sys_write
	mov rdi, 1	; stdout
	syscall
