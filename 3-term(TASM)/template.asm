model small
.stack 100h
.data
	
.code
.386

main:
	mov ax, @data
 	mov ds, ax

 	
	 
	mov ah, 4Ch
	int 21h
end main