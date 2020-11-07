section .text
		global	ft_strlen

; ft_strlen(rdi)
ft_strlen:
		mov		rax, -1
loop:
		inc		rax
		cmp		byte [rdi + rax], 0
		jne		loop
		ret
