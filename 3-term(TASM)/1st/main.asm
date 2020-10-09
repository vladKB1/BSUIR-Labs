.model small
.stack 100h
.data 
	a dw 3
	b dw 18
	c dw 3
	d dw 36
.code
main:
	mov ax,@data
	mov ds,ax

	mov ax, a
	add ax, c
	jc overflow1
	
	mov bx, b
	xor bx, d
	
	cmp ax, bx
	je else1
		overflow1:
		mov bx, b
		and bx, d
		jc overflow2
		cmp ax, bx
		je else2
			overflow2:
			mov ax, a
			add ax, d
			mov bx, b
			or bx, c
			and ax, bx
			jmp finish		
		else2:
			mov ax, a
			xor ax, b
			mov bx, c
			xor bx, d
			add ax, bx
			jmp finish
			
	else1:
		mov ax, a
		or ax, b
		or ax, c
		add ax, d
		
	finish:

	mov ax,4c00h
	int 21h
end main
