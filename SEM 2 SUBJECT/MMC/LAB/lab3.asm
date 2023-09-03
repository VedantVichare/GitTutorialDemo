%macro op 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
	%endmacro

section .data
	arr db 0FH,06H,05H,04H,0AH
	
	msg1 db "Result is: ",10 ;10 is \n
	msg1len equ $-msg1
	newline db 10

section .bss
	sum resw 1;assuming that sum value is maximum 0xFF (1byte)
	result resb 1
	count resb 1
cou resb 1
section .text 
	global _start
	_start:
	op 1,1,msg1,msg1len
		mov byte[count],5
		mov rsi,arr
		mov ax,00H
		mov bx,00H
		
		
		
		
		up2:
		mov bl,[rsi]
		add ax,bx
		inc rsi
		dec byte[count]
			jnz up2
		
		mov [sum],ax
		mov byte[count],4
		up:	mov ax,[sum]
			rol ax,04;rotate left causes swap of digits i.e
			mov [sum],ax
			and ax,0FH;AND so that LSbyte has only ones digits
				cmp al,09H
					jbe add30H;if true go to 

						add al,07H
					add30H:add al,30H
			mov [result],al
			op 1,1,result,1
			
			dec byte[count]
			jnz up;jif count is not zero go to 'up' label
			
		
		op 1,1,newline,1
		op 1,1,sum,1
		op 1,1,newline,1
		op 60,0,0,0

