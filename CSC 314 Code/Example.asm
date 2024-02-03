;	Name: Nathan O'Brien
;	Class: CSC 314 
;	Assignment: EXAMPLE
; 	Due:
; 	Description: 

include PCMAC.inc
.MODEL SMALL
.586
.STACK 100h
.DATA
msg db "Please enter the number of chirps heard in 25 second -> ", '$' ; message to prompt the user to enter chirps
msg2 db "You heard ","$"
msg3 db " chirps in 25 second, so ", "$"
Answer db "The temperature in degrees celcius is -> ", '$' ; message to display the temperature
chirps dw ?
celcius dw ?
.CODE
extrn GetDec:near
extrn PutDec:near
Main PROC
	_Begin ; Initialize the program
	_PutStr msg ; Display the message
	call GetDec
	mov chirps,ax
	;; the formula to convert chirps to celcius is
	;;(chirps/3) + 4 = temperature in celcius
	mov bl,3	;; AX holds chirps
	idiv bl		;; AX now holds chirps/3
	add ax,4	;; AX now holds chirps/3 + 4
	mov celcius,ax
	_PutSTR msg2
	mov ax, chirps
	call PutDec
	_PutSTR msg3
	_PutSTR Answer
	mov ax,celcius
	call PutDec
	_Exit 0 ; Exit the program
Main ENDP
END Main ; Tells where to start execution