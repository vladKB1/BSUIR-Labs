model small
.stack 200h
.data
	ten dw 10
	entr db 13
	bcksp db 8
	esc db 27
	new_line db 10

	len db, 0
	isMinus db, 0

	text1 db "First number: $"
	text2 db "Second number: $"
	msg_integer db "Integer part of number = $"
	msg_remainder db "Remainder of the number = $"
	msg_divide_by_zero db "You can't divide by zero!$"


	uncontrollableAns db "32768$"
.code

printAX proc
	push cx
	push dx


	xor cx, cx

	test ax, 8000h
	jz putToStack

	push ax
	mov dl, '-'
	mov ah, 02h
	int 21h
	pop ax

	neg ax


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
	mov isMinus, 0
	xor bx, bx
		

	whileNotEnter:		
		mov ah, 08h
		int 21h

		cmp al, entr
		je findEnter
				
		cmp al, bcksp
		je backSpace				

		cmp len, 0
		je firstSymb
	
	
		noLeadZero:
		
		sub al, '0'
		cmp al, 9
		ja whileNotEnter	

		xor dx, dx
		mov cl, al
		mov ax, ten
		mul bx
		xor ch, ch
		add ax, cx	

		cmp dx, 0
		ja whileNotEnter

		mov dl, isMinus
		add dx, 7fffh
		cmp ax, dx
		ja whileNotEnter

		mov bx, ax
		inc len


		add cl, '0'
		mov dl, cl
		mov ah, 02h
		int 21h

		jmp whileNotEnter


		firstSymb:
			cmp al, '-'
			je minus

			cmp al, '0'
			je whileNotEnter			

			jmp noLeadZero


		minus:			
			cmp isMinus, 1
			je whileNotEnter

			mov isMinus, 1						

			mov dl, '-'
			mov ah, 02h
			int 21h

			jmp whileNotEnter					


		delMinus:
			cmp isMinus, 0
			je whileNotEnter

			mov isMinus, 0					
			call delFromScreen
			jmp whileNotEnter	


		backSpace:
			cmp len, 0
			je delMinus
			
			call delFromScreen			
			jmp whileNotEnter									
	

		findEnter:		
			mov dl, new_line
			mov ah, 02h
			int 21h

			mov ax, bx
			
			cmp isMinus, 0
			je readEnd
			
			neg ax


	readEnd:	
		pop dx
		pop cx
		pop bx

		ret
readToAX endp

delFromScreen proc
	push ax
	push dx
	

	mov ah, 02h	
	mov dl, bcksp
	int 21h

	mov dl, ' '
	int 21h

	mov dl, bcksp
	int 21h

	xor dx, dx
	mov ax, bx
	div ten
	mov bx, ax

	cmp len, 0
	je delEnd

	dec len

	delEnd:
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

	
	cmp ax, -32768
	je uncontrollable


	controllable:

	xor dx, dx
	cwd	
	idiv bx
	
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


	uncontrollable:
		cmp bx, -1
		jne controllable

		lea dx, msg_integer
		mov ah, 09h
		int 21h

		lea dx, uncontrollableAns
		int 21h

		mov dl, new_line
		mov ah, 02h
		int 21h

		lea dx, msg_remainder
		mov ah, 09h
		int 21h

		mov dl, '0'
		mov ah, 02h
		int 21h

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
