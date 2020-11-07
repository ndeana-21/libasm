section .text
		global ft_strcpy

; strcpy(rdi, rsi)
ft_strcpy:
		mov		rax, 0
loop:
		mov		cl, [rsi + rax]
		mov		[rdi + rax], cl
		inc		rax
		cmp		byte [rsi + rax], 0
		jne		loop

		mov		byte [rdi + rax], 0
		mov		rax, rdi
		ret
