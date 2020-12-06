model small
.stack 100h
.data
	ten dw 10
	len dw 0
	mx dw 0
	mxlen dw 0
	l dw 0
	r dw 0

	string dw 100 dup('$')
	zFunc dw 100 dup(0)
.code
.386

readString proc
	push ax
	push di


	mov len, 0
	lea di, string	
	cld

	whileNotEnter:
		mov ah, 01h
		int 21h

		cmp al, 13
		je readStringEnd
		
		inc len
		stosb
		jmp whileNotEnter


	readStringEnd:

	pop di
	pop ax

	ret
readString endp

calcZetFunction proc
	push ax
	push bx
	push cx
	push si
	push di


	lea si, zFunc	
	lea di, string
	mov bx, 1

	for1:
		cmp bx, len
		jae calcEnd

		cmp bx, r
		ja while1
		
		mov ax, zFunc[bx]
		mov zFunc[bx], ax
		mov ax, r
		sub ax, bx
		inc ax
		cmp ax, zFunc[bx]
		ja while1

		mov zFunc[bx], ax

		
		while1:
			mov ax, bx
			add ax, zFunc[bx]
			cmp ax, len
			jae afterWhile1

			push bx
			add bx, zFunc[bx]			
			mov cx, string[bx]
			pop bx

			push bx
			mov bx, zFunc[bx]
			cmp string[bx], cx
			jne afterWhile1

			inc zFunc[bx]		
			jmp while1


		afterWhile1:
		mov ax, bx
		add ax, zFunc[bx]
		dec ax
		cmp r, ax
		jae findAns

		mov l, bx
		mov r, ax


		findAns:
		mov ax, zFunc[bx]
		cmp mx, ax
		jae nextStep

		mov mx, ax
		mov mxlen, bx
		inc mxlen
		

		nextStep:	
		push ax	
		mov ax, zFunc[bx]
		call printAX
		mov dl, ' '
		mov ah, 02h
		int 21h
		pop ax	

		inc bx
		jmp for1
	

	calcEnd:
	pop di
	pop si	
	pop cx
	pop bx
	pop ax

	ret
calcZetFunction endp

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

main:
	mov ax, @data
 	mov ds, ax
	mov es, ax

 	call readString
	call calcZetFunction
	
	mov ax, len
	mov bx, mxlen
	dec bx
	div bx

	cmp ah, 0
	jne noPeriod
	
	mov ax, mxlen
	add ax, mx
	dec ax
	cmp ax, len
	jne noPeriod

	mov ax, mxlen
	dec ax
	call printAX
	jmp exit

	noPeriod:
	mov ax, len
	call printAX

	exit:
	mov ah, 4ch
	int 21h
end main