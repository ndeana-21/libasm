section .text
		global	ft_strdup
		extern	malloc
		extern	ft_strlen
		extern	ft_strcpy

; strdup(rdi)
ft_strdup:
		push	rdi
		call	ft_strlen
		inc		rax
		mov		rdi, rax

		call	malloc
		mov		rdi, rax
		pop		rsi

		call	ft_strcpy
		ret
