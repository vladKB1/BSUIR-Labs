model small
.stack 100h
.data
	ten dw 10

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

		cmp al, 10
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
	push cx
	push si
	push di

	xor ax, ax
	mov cx, 1	
	lea si, zFunc
	inc si	

	for1:
		cmp cl, len
		jae calcEnd

		cmp cl, r
		ja while1
		
		mov al, [si-1]
		mov [si], al

		mov al, r
		sub al, cl
		inc al
		cmp al, [si]
		ja while1

		mov [si], al

		
		while1:
			mov al, cl
			add al, [si]
			cmp al, len
			jae afterWhile1

			push si						
			mov al, [si]
			
			lea si, string
			add si, ax 

			lea di, string
			add di, ax
			add di, cx			

			cmpsb	
			pop si

			jne afterWhile1

			mov al, [si]	
			inc al
			mov [si], al			
			jmp while1


		afterWhile1:
		mov al, cl
		add al, [si]
		dec al
		cmp r, al
		jae findAns

		mov l, cl
		mov r, al


		findAns:
		mov al, [si]
		cmp mx, al
		jae nextStep

		mov mx, al
		mov mxlen, cl
		inc mxlen
		

		nextStep:	
		inc si
		inc cx
		jmp for1
	

	calcEnd:
	pop di
	pop si	
	pop cx	
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
	
	xor ax, ax
	mov al, len
	mov bl, mxlen
	dec bl	
	div bl

	cmp ah, 0
	jne noPeriod
	
	mov al, mxlen
	add al, mx
	dec al
	cmp al, len
	jne noPeriod

	xor ax, ax
	mov al, mxlen
	dec al 
	call printAX
	jmp exit

	noPeriod:
	xor ax, ax
	mov al, len
	call printAX

	exit:
	mov ah, 4ch
	int 21h
end main