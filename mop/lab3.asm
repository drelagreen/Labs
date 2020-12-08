;VAR 2
model SMALL
stack 256

dataseg
COUNT dw 0
ARR db 255, 12, 54, 78, 92, 1, 67, 155; 8+2+4+4+4+1+3+5=31 - OK

codeseg
startupcode
	mov CX, 8
	lea BX, ARR
loop1:	
	push CX
	mov CX, 8
loop2:
	mov AX, 1
	and AX, [BX]
	add COUNT, AX
	mov AL, [BX]
	shr AL, 1
	mov [BX], AL
	loop loop2
	add BX, 1
	pop CX
	loop loop1

QUIT: exitcode 0
end


