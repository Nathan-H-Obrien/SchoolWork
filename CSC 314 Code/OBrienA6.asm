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
Output	db 13, 10, "Thanks for using the program!", 13, 10, '$'

																		
		.code
	extrn MFPGCD : near
	
Main   	proc
		_Begin				; Intialize the program
		
		call MFPGCD			; Calls MFPGCD program
		
		_PutStr Output		; Print output message
		_Exit 0				; Exits the program
Main 	ENDP

		END Main