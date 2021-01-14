model small
.stack 100h
.data	
	keyboardCode db 30, 48, 46, 32, 18, 33, 34, 35, 23, 36, 37, 38, 50, 49, 24, 25, 16, 19, 31, 20, 22, 47, 17, 45, 21, 44
	;keyWord db 26 dup('$')
	;lenKeyW db 0
	letterCode db "nebulascdfghijkmopqrtvwxyz"
	lastButton db 0

	old_int09h dd 0


	intStatus db 0
	capsLockFlag db 0
	shiftFlag db 0

	;msg_lenKeyW_is_null db "The length of key word is 0.$"
	;msg_lenKeyW_is_big db "The length of key word is more than 26.$"
.code
.386

setNewHandler proc
	push ax bx ds es

	mov ax, 3509h
	int 21h

	mov word ptr old_int09h, bx
	mov word ptr old_int09h+2, es


	mov ax, 2509h
	mov dx, seg newHandler
	mov ds, dx
	mov dx, offset newHandler
	int 21h
	

	pop es ds bx ax
	ret
setNewHandler endp


newHandler proc
	pusha
	push ds es si
	cli 

	xor ax, ax
	in al, 60h	

	cmp al, 58
	je capsLock
	cmp al, 186
	je unCapsLock

	cmp al, 42
	je shift
	cmp al, 170 ;+80h=128
	je unShift

	cmp al, 54
	je shift
	cmp al, 180
	je unShift


	xor si, si
	for1:
		cmp keyboardCode[si], al
		je letter	

		inc si
		cmp si, 26
		je endd
	jmp for1


	capsLock:
	mov capsLockFlag, 1
	jmp endd

	unCapsLock:
	mov capsLockFlag, 0
	jmp endd

	shift:
	mov shiftFlag, 1
	jmp endd

	unShift:
	mov shiftFlag, 0
	jmp endd


	letter:
	mov dl, letterCode[si]

	mov cl, shiftFlag
	add cl, capsLockFlag
	and cl, 1

	cmp cl, 0
	je printLetter

	upperCase:
	sub dl, 32

	printLetter:
	mov ah, 02h
	int 21h
	mov lastButton, dl

	endd:
	xor ax, ax
	mov al, 20h
	out 20h, al

	pop si es ds
	popa

	sti
	iret
newHandler endp


setOldHandler proc
	push ax dx ds

	mov ax, 2509h
	lds dx, old_int09h
	int 21h

	pop ds dx ax
	ret
setOldHandler endp


main:
	mov ax, @data
 	mov ds, ax

 	;call getArgument	

	while1:	
		cmp intStatus, 1
		je checkButton

		mov ah, 01h
		int 21h
		mov lastButton, al


		checkButton:
		cmp lastButton, 's'
		je setNewHandle
		cmp lastButton, 'e'
		je setOldHandle
		cmp lastButton, 'x'
		je exit

		jmp while1


		setNewHandle:
			cmp intStatus, 1
			je while1

			call setNewHandler
			mov intStatus, 1
			jmp while1


		setOldHandle:
			cmp intStatus, 0
			je while1

			call setOldHandler
			mov intStatus, 0
			jmp while1
		

		endWhile1:
	jmp while1

	exit:
	mov ah, 4ch
	int 21h
end main


;getArgument proc
	;uses ax, bx, cx, dx, si

	;xor cx, cx	
	;mov cl, es:[80h]
	;cmp cl, 0
	;je nullLen
	;cmp cl, 26
	;jae bigLen

	;xor bx, bx
	;mov si, es:[82h]

	;while2:
	
	;loop while2


	;nullLen:
	;	lea dx, msg_lenKeyW_is_null
	;	mov ah, 09h
	;	int 21h
	;	call endd

	;bigLen:
	;	lea dx, msg_lenKeyW_is_big
	;	mov ah, 09h
	;	int 21h
	;	call endd
		

	
	;endd:
	;	mov ah, 4ch
	;	int 21h


	;ret
;getArgument endp