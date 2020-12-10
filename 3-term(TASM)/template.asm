model small
.stack 100h
.data
	
.code
.386

main:
	mov ax, @data
 	mov ds, ax

 	
	 
	mov ah, 4ch
	int 21h
end main