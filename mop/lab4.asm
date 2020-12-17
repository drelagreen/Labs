;VAR 3
model SMALL
stack 256

dataseg
Counter db 0
Number  db 0
Inbuff db 80, ?, 82 dup(?)

OutBuff db 0Ah, 0Dh, ?, ?, 0Dh, 0Ah, '$'
codeseg
startupcode

Begin:
	lea DX, Inbuff
	mov AH, 0Ah
	int 21h
	
	mov CL, Inbuff+1; count of symbols
	lea BX, Inbuff+2; adress of beggining
	jmp Loop1
Mult:	
	mov AL, 10
	mul Number
	mov Number, AL 
	jmp Loop10
Loop1:
	mov AL, [BX] 
	add BL, 1
	cmp AL, ' '
	je NotDigit
	sub AL, '0' 
	push AX
	jmp Mult
Loop10:	
	pop AX
	add Number, AL 
	;cmp CL, 0
	;je Print
	loop Loop1
NotDigit:
	cmp Number, 0 
	je NotDigit1

	test Number, 1
	jnz Odd
	mov AL, 1
	add Counter, AL
Odd:
	mov Number, 0
NotDigit1:
	cmp CL, 0
	je Print
	loop Loop1 
Print: 
	xor AX, AX
	mov AL, Counter
	mov BL, 10
	div BL
	add AH, '0' 
	add AL, '0' 
	cmp AL, 0
	mov OutBuff+2, AL
	mov OutBuff+3, AH	
	
	lea DX, OutBuff
	mov AH, 09h
	int 21h
QUIT:
	exitcode 0
end


 
