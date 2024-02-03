;	Name: Nathan O'Brien
;	Class: CSC 314 
;	Assignment: 4
; 	Due: 10/23/23
; 	Description: This program is meant to convert celcius to fahrenheit using
;				 imul and idiv operands


		INCLUDE PCMAC.INC	
		.model SMALL
		.586

		.stack 100h

		.data
Prompt	db "Please enter the Celcius tempeature -> ", '$'	; message to prompt the user to input a tempeature
Celcius		dw ?	; variable Celcius uses ? as a holder until value is entered by user
Fahrenheit	dw ?	; variable Fahrenheit uses ? as a holder until value is found
outputMsg	db "The degrees you entered in Celcius was $"		; message to show the user the tempeature they entered in celcius
outputMsg2	db ", so the degrees in Fahrenheit is ",13,10, '$'		; message to show the user the tempeature in fahrenheit

		.code
		extrn PutDec : near
		extrn GetDec : near    
Main   	proc
        _begin	; initialize the program
		_PutStr Prompt	; moves Prompt into the ax directory and displays its contents ("Please enter the Celcius tempeature -> ")
		call GetDec	;	; takes in the user input value and moves the value into the al directory
		mov Celcius, ax	; moves the data stored in al into celcius
		
; Now convert the Celcius to Fahrenheit using the formula (9/5)*Celcius + 32 = Fahrenheit
		mov ax, Celcius	; moves celcius into the ax directory
		mov bx, 9 ; moves 9 into the bx directory
		imul bx	; multiples the ax (celcius) directory and the bx (9) directory 
		mov cl, 5 ; moves 5 into the cx directory
		idiv cx	; divides the AX (celcius) directory by the cx (5) directory
		add ax, 32	; adds 32 to the ax (celcius) directory
		
; store the celcius to fahrenheit conversion
		mov Fahrenheit, ax	; moves the ax directory into the variable Fahrenheit
		
; display the tempeature in celcius
		_PutStr outputMsg	; moves outputMsg into the ax directory and displays its contents ("The degrees you entered in Celcius was $")
		mov ax, Celcius	; moves celcius back into the ax directory
		call PutDec ; calls the ax directory to display its contents
		
; display the tempeature in fahrenheit
		_PutStr outputMsg2 ; moves outputMsg2 into the ax directory and displays its contents (" degrees Fahrenheit",13,10, '$')
		mov ax, Fahrenheit	; moves fahrenheit into the ax directory
		call PutDec	; calls the ax directory to display its contents (fahrenheit)
		
        _Exit 0	; exits the program
Main 	ENDP
		end Main
