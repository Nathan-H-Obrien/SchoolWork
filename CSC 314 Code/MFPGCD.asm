;	Name: Nathan O'Brien
;	Class: CSC 314 
;	Assignment: 6
; 	Due: 11/29/23
; 	Description: This program calls an outside procedure to calculate the greatest
; 				 common divisor of two numbers and also allow the user to recalculate a
; 				 new set of numbers

INCLUDE PCMAC.INC	
.model SMALL
.586
.stack 100h
.data
GetM	db 13, 10, "What is the first value you would like to use? ", '$' 					; Prompts the user for first number				
GetN	db 13, 10, "What is the second value you would like to use? ", '$'					; Prompts the user for second number

DivisorOut	db 13, 10, "The greatest common Divisor is: ", '$'								; Displays the GCD to the user

RepeatPrompt	db 13, 10, "Would you like to find another GCD (Input Y/y to continue)? ", '$'	; Prompt user if they would like to repeat
M		dw ?																		; Variable to hold the first number
N		dw ?																		; Variable to hold the second number
GCD		dw ?																		; Variable to hold the answer
		
PUBLIC MFPGCD																		; Allows program to be used externally
																
.code
extrn GetDec : near
extrn PutDec : near		

GetNums proc		; Proc that prompts the user for the two numbers they desire to use	
	_PutStr GetM
	call GetDec		; Gets first number
	mov M, ax		; Stores whatever is stored in the ax register into M
	
	_PutStr GetN
	call GetDec				; Gets second number
	mov N, ax				; Stores whatever is stored in the ax register into N
	ret						
GetNums ENDP

CalcGCD proc				; Proc to calculate the GCD from the given numbers
	mov ax, M				; Stores whatever is in M into the ax register
	mov bx, N				; Stores whatever is in N into the bx register

While_1:
Then_Equal:					; Checks to see if the values of bx and ax are equal
	cmp ax, bx
	jne Then_0M
	mov GCD, bx
	ret
Then_0M:						; Checks to see if the value in ax is 0
	cmp ax, 0
	jne Then_0N
	mov GCD, bx
	ret
Then_0N:						; Checks to see if the value in bx is 0
	cmp bx, 0
	jne Then_Negative
	mov GCD, ax
	ret
Then_Negative:				; Checks to see if the value in ax is -32768
	cmp ax, -32768
	jne Calculate
	mov ax, 16384
		
Calculate:
	if_1:						; Checks to see if the value in bx is less than the value in ax
	cmp bx, ax
	jl else_1
	then_1:						; Checks to see if the value in bx is less than the value in ax
	sub bx, ax				; Subtracts ax from bx
	jmp end_1
	else_1:
	sub ax, bx				; Subtracts bx from ax
	end_1:
	mov GCD, bx				; Moves bx into GCD
	cmp ax, bx				; Compares to see if ax and bx are equal to each other
	jne While_1
	ret
CalcGCD ENDP

Closing proc					; Proc to display the answer
	_PutStr DivisorOut			; Displays the contents of DivisorOut	
	
	mov ax, GCD					; Stores whatever is in GCD into the ax register
	call PutDec					; Displays the contents of the ax register
	
	ret
Closing ENDP
		
MFPGCD   	proc
main:
	call GetNums	    ; Calls the GetNums proc
	mov ax, M		
	mov bx, N
	call CalcGCD		; Calculate GCD
	call Closing		; Print closing
		
	_PutStr RepeatPrompt	; Prompt to repeat program
	_GetCh					; Gets character from user
	mov cl, 59h				; Stores the hex value of Y into cl register
	cmp al, cl
	je main
	mov cl, 79h				; Stores the hex value of y into cl register
	cmp al, cl
	je main
		
	ret
MFPGCD 	ENDP
End
