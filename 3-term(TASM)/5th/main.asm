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
	ki dw 0
	kj dw 0
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

			cmp al, new_line
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

		cmp cx, 0
		je nextStepFori2

		forj2:
			xor ax, ax
			mov al, [bx][si]
			call printAX

			push dx
			mov ah, 02h
			mov dl, space
			int 21h
			pop dx
			
			add si, elementSize
		loop forj2

		nextStepFori2:
		xor ax, ax
		mov al, [bx][si]
		call printAX
		
		push dx
		mov ah, 02h
		mov dl, new_line
		int 21h
		pop dx

		add si, elementSize


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

		cmp al, new_line
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


	mov ki, 0
	mov kj, 0
	fork3:
		push cx
		
		xor cx, cx
		mov cl, n
		mov bx, 0
		fori3:
			push cx

			xor cx, cx
			mov cl, n
			mov si, 0
			forj3:
				push si
				mov si, kj
				mov al, ms[bx][si]
				pop si
				push bx
				mov bx, ki
				add al, ms[bx][si]
				pop bx

				cmp ms[bx][si], al
				ja newAns
				
				jmp nextStepForj3


				newAns:
				mov ms[bx][si], al
				

				nextStepForj3:
				add si, elementSize
			loop forj3

			pop cx
			add bx, si						
		loop fori3

		pop cx
		add ki, si
		mov ax, kj
		add ax, elementSize
		mov kj, ax
	loop fork3
	

	lea bx, ms
	xor cx, cx
	xor dx, dx
	mov cl, n
	mov dl, n
	call printMatrix
	 
	mov ah, 4ch
	int 21h
end main