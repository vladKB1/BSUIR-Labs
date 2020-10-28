model small
.stack 100h
.data
	ten dw 10
	entr db 13
	bcksp db 8
	esc db 27
	new_line db 10

	len db, 0

	text1 db "First number: $"
	text2 db "Second number: $"
	msg_integer db "Integer part of number = $"
	msg_remainder db "Remainder of the number = $"
	msg_divide_by_zero db "You can't divide by zero!$"
.code

printAX proc
	push cx
	push dx
	
	xor cx, cx	

	putToStack:
		xor dx, dx
		div ten
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
	push cx
	push dx

	mov len, 0
	xor bx, bx

	whileNotEnter:		
		mov ah, 08h
		int 21h

		cmp al, entr
		je findEnter

		cmp al, bcksp
		je backSpace

		cmp al, esc
		je escape

		cmp len, 0
		je leadZero
	

	
		noLeadZero:
				
		sub al, '0'
		cmp al, 9
		ja whileNotEnter	

		xor dx, dx
		mov cl, al
		mov ax, ten
		mul bx	

		cmp dx, 0
		ja whileNotEnter

		xor ch, ch
		add ax, cx
		jc whileNotEnter

		mov bx, ax
		inc len

		add cl, '0'
		mov dl, cl
		mov ah, 02h
		int 21h

		jmp whileNotEnter

		backSpace:
			call delFromScreen
			
			xor dx, dx
			mov ax, bx
			div ten
			mov bx, ax

			jmp whileNotEnter

		escape:	
			call delFromScreen

			xor dx, dx
			mov ax, bx
			div ten
			mov bx, ax

			cmp len, 0
			ja escape

			jmp whileNotEnter	

		leadZero:
			cmp al, '0'
			je whileNotEnter

			jmp noleadzero

	findEnter:		
		mov dl, new_line
		mov ah, 02h
		int 21h

		mov ax, bx 
		
	pop dx
	pop cx
	pop bx

	ret
readToAX endp

delFromScreen proc
	push ax
	push dx

	cmp len, 0
	je lenNull
		
	mov ah, 02h	
	mov dl, bcksp
	int 21h

	mov dl, ' '
	int 21h

	mov dl, bcksp
	int 21h

	dec len
	
	lenNull:		

	pop dx
	pop ax

	ret
delFromScreen endp

main:
	mov ax, @data
 	mov ds, ax

	lea dx, text1
	mov ah, 09h
	int 21h

	call readToAX
	mov bx, ax

	lea dx, text2
	mov ah, 09h
	int 21h

	call readToAX
	cmp ax, 0
	je nullNumber


	
	xor ax, bx
	xor bx, ax
	xor ax, bx

	xor dx, dx
	div bx
	
	push dx
	push ax

	lea dx, msg_integer
	mov ah, 09h
	int 21h

	pop ax
	call printAX

	mov dl, new_line
	mov ah, 02h
	int 21h

	lea dx, msg_remainder
	mov ah, 09h
	int 21h

	pop dx
	mov ax, dx
	call printAX 

	mov dl, new_line
	mov ah, 02h
	int 21h

	jmp endd

	nullNumber:
		lea dx, msg_divide_by_zero
		mov ah, 09h
		int 21h
		jmp endd
	
	endd:
		mov ah, 4ch
		int 21h
end main
