model small
.stack 100h
.data
	len db 0
	mx db 0
	mxlen db 0
	l db 0
	r db 0

	string db 100 dup('$')
	zFunc db 100 dup(0)
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
	push dx
	push si
	push di


	lea si, zFunc	
	lea di, string
	mov cx, 1

	for1:
		cmp cl, len
		jae calcEnd

		cmp cl, r
		ja while1

		mov al, zFunc[si+cl-l]
		mov zFunc[si+cl], al
		mov al, r
		sub al, cl
		inc al
		cmp al, zFunc[si+cl]
		ja while1

		mov zFunc[si+cl], al


		while1:
			mov al, cl
			add al, zFunc[si+cl]
			cmp len, al
			jae afterWhile1

			cmp string[di+zFunc[si+cl]], string[di+cl+zFunc[si+cl]]
			jne afterWhile1

			inc zFunc[si+cl]		
			jmp whille1


		afterWhile1:
		mov al, cl
		add al, zFunc[si+cl]
		dec al
		cmp r, al
		jae findAns

		mov l, cl
		mov r, al


		findAns:
		mov al, zFunc[si+cl]
		cmp mx, al
		jae nextStep

		mov mx, al
		mov mxlen, cl
		inc mxlen
		

		nextStep:
		inc cx
		inc si
		jmp for1
	

	calcEnd:

	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax

	ret
calcZetFunction endp

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
	
	mov al, mxlen
	add al, mx
	dec al
	cmp al, len
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