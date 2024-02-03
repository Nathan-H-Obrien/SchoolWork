;	Name: Nathan O'Brien
;	Class: CSC 314 
;	Assignment: 5
; 	Due: 11/15/23
; 	Description: This program is meant print a desired character across the screen back and forth
;				 a desired amount of spaces (1-78) and repeat teh desired amount of times (1-3).


		INCLUDE PCMAC.INC	
		.model SMALL
		.586
		.stack 100h
		.data
DelayCount dw ? ; Variable to hold the number of loops desired by the user
Character dw ?	; Variable to hold the character desired by the user
SpaceCount dw ? ; Variable to hold the number of spaces travelled desired by the user
Msg1	db "Please enter a value between 1-3 to print the Character across the screen: ", '$'	; Message to prompt the user to enter number of loops
Msg2	db "Please enter the desired Character to print across the screen: ", '$'	; Message to prompt the user to enter the desired character
Msg3	db "Please enter the desired number of spaces travelled (1-78): ", '$'		; Message to prompt the user to enter the desired number of spaces travelled
Msg4	db "Thank you for using the Program!", 13, 10, '$'	; Message to thank the user for using the program
		.code
		extrn PutDec : near	
		extrn GetDec : near 

Prompt	proc	; Proc to print out prompt messages and store data given into appropriate locations
		_Begin	; initialize the program
c_1:    _PutStr Msg1	; Print out Msg1 to the user
		call GetDec	; Take in the desired number of loops from the user by modifying the ax register
		cmp ax, 0	; Comparing the ax register to 0
		jle c_1		; Jumping to c_1 if the value entered into ax is less than or equal to 0, falls through if jump condition is false
		cmp ax, 4	; Comparing the ax register to 4
		jge c_1		; Jumping to c_1 if value entered into ax is greater than or equal to 4, falls through if jump condition is false
		mov DelayCount, ax	; Storing the value of the ax register into DelayCount for later use
		
		_PutStr Msg2	; Print out Msg2 to the user
		_GetCh		; Take in the desired character from the user by modifying the ax register
		mov Character, ax	; Storing the character of the ax register into Character for later use
		_PutCh 13	; Move cursor to a new line
		_PutCh 10	; Move cursor back to start of the line
		
c_2:	_PutStr Msg3	; Print out Msg3 to the user
		call GetDec	; Take in the desired number of spaces from the user by modifying the ax register
		cmp ax, 0	; Comparing the ax register to 0
		jle c_2		; Jumping to c_2 if the value entered into ax is less than or equal to 0, falls through if jump condition is false 
		cmp ax, 79	; Comparing the ax register to 79
		jge c_2 	; Jumping to c_2 if the value entered into ax is greater than or equal to 79, falls through if jump condition is false
		mov SpaceCount, ax	; Storing the value of the ax register into SpaceCount for later use
		ret	; Return to wherever called from
Prompt 	ENDP

MoveCh	proc	; Proc to move the desired character across the screen the desired amount of times
		mov bx, DelayCount	; Stores the value in DelayCount into the bx register

for_3:	_PutCh 8	; Enters a backspace keystroke
		_PutCh 32	; Enters a space keystroke
		mov cx, SpaceCount	; Stores SpaceCount into the cx register
		
for_1:	
		mov dx, Character	; Stores the character stored in Character into the dx register
		_PutCh	; Places the character value that is stored in the dx register
		call Delay	; Calls the Delay Proc
		_PutCh 8	; Enters a backspace keystroke	
		_PutCh 32	; Enters a space keystroke
		dec cx		; Decrement cx
		jnz for_1	; Jumping to for_1 if cx is not equal to 0, falls through if jump condition is false

		_PutCh 8	; Enters a backspace keystroke
		mov cx, SpaceCount	; Stores SpaceCount into the cx register

for_2:	_PutCh 8	; Enters a backspace keystroke
		_putCh 32	; Enters a space keystroke
		_PutCh 8	; Enters a backspace keystroke
		_PutCh 8	; Enters a backspace keystroke
		mov dx, Character	; Stores the character stored in Character into the dx register
		_PutCh		; Places the character value that is stored in the dx register
		call Delay	; Calls the Delay Proc
		dec cx		; Decrement cx
		jnz for_2	; Jumping to for_2 if cx is not equal to 0, falls through if jump condition is false
		dec bx		; Decrement bx
		jnz for_3	; Jumping to for_3 if bx is not equal to 0, falls through if jump condition is false
		_putCh 8	; Enters a backspace keystroke
		_PutCh 32	; Enters a space keystroke
		ret			; Return to wherever called from
MoveCh	ENDP

Delay 	proc	; Proc to cause a delay in order for the user to see the character move across the screen
		push cx	; Push the value of cx onto the stack to save the value
		mov cx, 0	; Store 0 into the cx register
		
for_4:	nop		; Wait one clock tick
		dec cx	; Decrement cx causing for it to loop back to 65,536
		jnz for_4	; Jumping to for_4 if cx is not equal to 0
		pop cx	; Pops the top stack value into the cx register
		ret		; Return to wherever called from
Delay 	ENDP

Exit	proc	; Proc to print out exiting message and exit the program
		_PutCh 8	; Enters a backspace keystroke
		_PutStr Msg4	; Print out Msg4 to the user
		_Exit	; Exits the program
Exit ENDP

		
		
Main   	proc
		call Prompt	; Call the Prompt Proc
		call MoveCh	; Call the MoveCh Proc
		call Exit	; Call the Exit Proc
Main 	ENDP

		END Main
		
