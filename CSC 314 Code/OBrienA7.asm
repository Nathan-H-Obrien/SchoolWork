;	Name: Nathan O'Brien
;	Class: CSC 314 
;	Assignment: 5
; 	Due: 11/15/23
; 	Description: This program prompts the user to enter their full name (first middle last), and then prints 
;                their name in 'last, first middle' format

include pcmac.inc
.model small
.586

.stack 100h

.data
promptMessage   DB 'Please write your full name (First Middle Last) then hit enter: ', 13, 10, '$'

nameLength      DW ?
nameStorage     DB 80 DUP(?)    ; Define an array of 80 bytes to store the user's name

inputPtr        DW ?
charCount       DW ?
spaceIndex      DW ?
nextIndex       DW ?
currentChar     DB ?

.code
EXTRN   PutDec:near
EXTRN   GetDec:near

getUserInput   proc

    mov inputPtr, offset nameStorage    ; Get the starting address of the nameStorage array
    mov cx, 0        ; Initialize the character counter to 0

userInputLoop:          
    _GetCh
    cmp al, 13        ; Check if the user presses the 'enter' key
    je endUserInputLoop
    mov di, inputPtr    ; Load the address into the register
    mov [di], al        ; Store the character from the user into the array
    inc inputPtr        ; Move to the next position in memory
    inc cx        ; Increment the character counter
    cmp cx, 80    ; Check if the maximum length of the array is reached
    jl userInputLoop

endUserInputLoop:    mov nameLength, cx    ; Store the final character count in nameLength
    ret

getUserInput   endp

printFormattedName  proc

    mov inputPtr, offset nameStorage    ; Get the starting address of the nameStorage array
    mov cx, nameLength    ; Get the character count

    dec cx    ; Move to the last character

    mov spaceIndex, cx    ; spaceIndex will be used to search for the last space in the name

findSpace:        
    cmp spaceIndex, 0    ; Check if it's a single name case
    je noSpace

    mov di, inputPtr                ; Load the effective address of inputPtr into di
	mov si, inputPtr                ; Load the effective address of inputPtr into si
	add si, spaceIndex              ; Add spaceIndex to si
	mov al, [si]                    ; Get the current character



    cmp al, ' '    ; Check if it's a space
    je lastName
    dec spaceIndex
    jmp findSpace

noSpace:        
    mov si, inputPtr                ; Load the effective address of inputPtr into si
	add si, spaceIndex              ; Add spaceIndex to si
	mov dl, [si]                    ; Print the character

    _PutCh
    inc spaceIndex
    cmp spaceIndex, cx    ; Check if we reached the end
    jle noSpace
    jmp printFormattedNameEnd

lastName:        
    mov ax, spaceIndex           ; Move the value of spaceIndex to a temporary register (ax)
	inc ax                       ; Increment ax to get the position right after the space
	mov nextIndex, ax            ; Store the result in nextIndex


printLastName:    
    mov si, inputPtr        ; Load the effective address of inputPtr into si
	add si, spaceIndex      ; Add spaceIndex to si
	mov dl, [si]            ; Print the character

    _PutCh
    inc spaceIndex
    cmp spaceIndex, cx        ; Check if we have printed the entire last name
    jle printLastName

    _PutCh ','        ; Print a comma
    _PutCh ' '        ; Print a space
    mov spaceIndex, 0    ; Reset spaceIndex to the starting position

restOfName:        
    mov ax, spaceIndex       ; Move the value of spaceIndex to a temporary register (ax)
	cmp ax, nextIndex        ; Compare the position of the start of the last name

    je printFormattedNameEnd
    mov si, inputPtr        ; Load the effective address of inputPtr into si
	add si, spaceIndex      ; Add spaceIndex to si
	mov dl, [si]            ; Print the character
	
    _PutCh
    inc spaceIndex
    jmp restOfName

printFormattedNameEnd:    ret

printFormattedName  endp

main    proc
    _Begin

    _PutStr promptMessage    ; Print the prompt message

    call getUserInput        ; Get the user's name
    mov ax, nameLength
    cmp ax, 0
    je endProgram        ; If the name length is 0, end the program

    call printFormattedName    ; Print the name in 'last, first middle' format

endProgram:        

    _Exit 0
main    endp
    end main
