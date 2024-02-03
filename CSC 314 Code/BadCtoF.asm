;;	
;;	Class: CSC 314 Fall 2021
;;	Assignment: 4
;;	Description: Converts celcius to an approximate Fahrenheit using both imul and idiv
;;				 
;;


		INCLUDE PCMAC.INC	
		.model SMALL
		.586

		.stack 100h

		.data
Prompt	db "Please enter the Celcius tempeature -> ", '$'	;; message to prompt the user to input a tempeature
Celcius		db ?	;; variable Celcius uses ? as a holder until value is entered by user
Fahrenheit	db ?	;; variable Fahrenheit uses ? as a holder until value is found
outputMsg	db "The degrees you entered in Celcius was $"		;; message to show the user the tempeature they entered in celcius
outputMsg2	db " and the degrees in Fahrenheit is ",13,10, '$'		;; message to show the user the tempeature in fahrenheit

		.code
		extrn PutDec : near
		extrn GetDec : near    
Main   	proc
        _begin	; initialize the program
		_PutStr Prompt	; moves Prompt into the ax directory and displays its contents ("Please enter the Celcius tempeature -> ")
		call GetDec	;	; takes in the user input value and moves the value into the al directory
		mov Celcius, al	; moves the data stored in al into celcius
		
						; Now convert the Celcius to Fahrenheit using the formula (9/5)*Celcius + 32 = Fahrenheit
		mov al, Celcius	; moves celcius into the al directory
		mov ah, 0; converts celcius into 16 bits, entire ax directory
		mov bl, 9 ; moves 9 into the lower half of the bx directory
		imul bl	; multiples the ax (celcius) directory and the bl (9) directory 
		mov cl, 5 ; moves 5 into the lower half of the cx directory
		idiv cl	; divides the AX (celcius) directory by the cl directory
		add al, 32	; adds 32 to the al (celcius) directory
		
		mov Fahrenheit, al	; moves the al directory into the variable Fahrenheit
		_PutStr outputMsg	; moves outputMsg into the ax directory and displays its contents ("The degrees you entered in Celcius was $")
		mov al, Celcius	; moves celcius back into the al directory
		mov ah, 0	; converts celcius into 16 bits, entire ax directory (celcius)
		call PutDec ; calls the ax directory to display its contents
		_PutStr outputMsg2 ; moves outputMsg2 into the ax directory and displays its contents (" degrees Fahrenheit",13,10, '$')
		mov al, Fahrenheit	; moves fahrenheit into the al directory
		mov ah, 0	; converts fahrenheit into 16 bits, entire ax directory
		call PutDec	; calls the ax directory to display its contents (fahrenheit)
        _Exit 0	; exits the program
Main 	ENDP
		end Main
