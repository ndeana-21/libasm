section .text
		global ft_strcmp

; strcmp(rdi, rsi)
ft_strcmp:
		mov		rax, 0

loop:
		mov		al, byte [rdi]
		mov		bl, byte [rsi]
		inc		rdi
		inc		rsi

		cmp		al, bl
		jne		exit
		cmp		al, 0
		je		exit
		cmp		bl, 0
		je		exit
		jmp		loop

exit:
		movzx	rax, al
		movzx	rbx, bl
		sub		rax, rbx
		ret