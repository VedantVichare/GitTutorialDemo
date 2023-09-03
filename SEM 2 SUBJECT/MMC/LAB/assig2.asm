section .data
	num_array times 64 db 0
	msg1 db "Element of array addition is ",10
	msglen1 equ $-msg1
	msg db "result of array addition is ",10
	msglen equ $-msg
	cnt db 5
	temp1 db 0
section .bss
	result resw 1
	temp resw 2
	num resb 3
	%macro rw 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
	%endmacro
section .text
	global  _start
	_start:

	mov rbp,num_array
	
	nextnum:rw 1,1,msg1,msglen1
	rw 0,0,num,3
	mov rcx,0
	mov rax,0
	mov rsi,num
	
	up1:mov cl,byte[rsi]
	cmp cl,0AH
	Je packed
	cmp cl,39h
	Jbe down1
	Sub cl,07h
	down1:sub cl,30H
	Rol al,4
	Add al,cl
	inc rsi
	Jmp up1

packed: mov byte[rbp],al
	inc rbp
	dec byte[cnt]
	jnz nextnum
	mov rsi,num_array
	mov ax,00h
	mov bx,00h
	mov cx,05h
	
up2:
	mov bl,byte[rsi]
	add ax,bx
	jnc skip
	inc ah
	
skip:
	inc rsi
	dec cx
	jnz up2
	mov word[result],ax
	mov ax,word[result]
	mov bp,4
	
up: rol ax,4
	mov bx,ax
	and ax,0Fh
	cmp al,09
	jbe down
	add al,07h
	down:Add al,30h
	
mov byte[temp],al
rw 1,1,temp,1
mov ax,bx
dec bp
jnz up
rw 60,0,0,0


OUTPUT:
student@admin:~$ nasm -f elf64 assig2.asm
student@admin:~$ ld -o assig2  assig2.o
student@admin:~$ ./assig2
Element of array addition is 
01
Element of array addition is 
02
Element of array addition is 
03
Element of array addition is 
04
Element of array addition is 
05
000Fstudent@admin:~$ 



