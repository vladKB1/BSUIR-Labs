model small
.stack 100h
.data
	ten db 10
	Wten dw 10

	entr db 13
	new_line db 10
	space db 32

	elementSize dw 1

	n db 0
	ms db 10 dup(10 dup(0))
.code
.386

readMatrix proc
	push bx
	push si
	push ax
	push cx
	push dx

	
	fori1:
		push cx

		mov cx, dx				
		mov si, 0

		forj1:
			mov ah, 01h
			int 21h

			cmp al, entr
			je nextStepForj1

			cmp al, space
			je nextStepForj1


			sub al, '0'

			xor al, [bx][si]
			xor [bx][si], al
			xor al, [bx][si]			
			mul ten
			add [bx][si], al
			
			jmp forj1

			
			nextStepForj1:
			add si, elementSize					
		loop forj1

		nextStepFori1:
		pop cx
		add bx, si
	loop fori1


	pop dx
	pop cx
	pop ax
	pop si
	pop bx

	ret
readMatrix endp

printMatrix proc
	push bx
	push si
	push ax
	push cx
	push dx


	fori2:
		push cx

		mov cx, dx
		dec cx
		mov si, 0
		
		push dx

		forj2:
			xor ax, ax
			mov al, [bx][si]
			call printAX

			mov ah, 02h
			mov dl, space
			int 21h
			
			add si, elementSize
		loop forj2

		
		xor ax, ax
		mov al, [bx][si]
		call printAX
		
		mov ah, 02h
		mov dl, new_line
		int 21h

		add si, elementSize


		pop dx
		pop cx
		add bx, si
	loop fori2
	

	pop dx
	pop cx
	pop ax
	pop si
	pop bx

	ret
printMatrix endp

printAX proc
	push cx
	push dx
	

	xor cx, cx	


	putToStack:
		xor dx, dx
		div Wten
		add dx, '0'
		push dx
		inc cx
		cmp ax, 0
		ja putToStack
	

	xor dx, dx
	printChar:	
		pop ax		
		mov dl, al
		mov ah, 02h
		int 21h
	loop printChar	
		

	pop dx
	pop cx	

	ret
printAX endp

readToAX proc
	push bx

	
	xor bx, bx

	whileNotEnter:		
		mov ah, 01h
		int 21h

		cmp al, entr
		je findEnter

		xor ah, ah		
		sub al, '0'
		xor ax, bx
		xor bx, ax
		xor ax, bx
		mul ten
		add bl, al
	
		jmp whileNotEnter


	findEnter:		
	mov ax, bx 	

	pop bx

	ret
readToAX endp

main:
	mov ax, @data
 	mov ds, ax
	
 	call readToAX
	mov n, al

	lea bx, ms
	xor cx, cx
	xor dx, dx
	mov cl, n
	mov dl, n
	call readMatrix


	

	lea bx, ms
	xor cx, cx
	xor dx, dx
	mov cl, n
	mov dl, n
	call printMatrix
	 
	mov ah, 4ch
	int 21h
end main