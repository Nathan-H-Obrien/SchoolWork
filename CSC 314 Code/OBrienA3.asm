;	Name: Nathan O'Brien
;	Class: CSC 314 
;	Assignment: 3
; 	Due: 10/13/23
; 	Description: This program is meant to print out the current date to the
;				 screen

include PCMAC.inc
.MODEL SMALL
.586
.STACK 100h
.DATA
msg db "Today's date is: ", '$' ; message to display the date

month db 0 ; Variable to store month
day db 0 ; Variable to store the current day
year dw 0 ; Variable to store the current year

.CODE
EXTRN PutDec:near
EXTRN GetDec:near
Main PROC
 _Begin ; Initialize the program
 _PutStr msg ; Display the message


    mov ah, 2Ah ;
    int 21h ;

    mov month, dh ; Store the retrieved month value into month variable
    mov day, dl ; Store the retrieved day value into day variable
    mov year, cx ; Store the retrieved year value into year variable

    mov dh, 0 ; Set the value of DH register to 0
    mov dl, month ; Move the value of cmonth variable to DL register
    mov ax, dx ; Move the value of DX register to AX register
    call PutDec ; Call PutDec to display the month value

    mov ah, 2 ; Set the value of AH register to 2 to display a character
    mov dl, '/' ; Set the value of DL register to '/' character
    int 21h ;

    mov dh, 0 ; Set the value of DH register to 0
    mov dl, day ; Move the value of day variable to DL register
    mov ax, dx ; Move the value of DX register to AX register
    call PutDec ; Call PutDec to display the day value

    mov ah, 2 ; Set the value of AH register to 2 to display a character
    mov dl, '/' ; Set the value of DL register to '/' character
    int 21h

    mov ax, year ; Move the value of year variable to AX register
    call PutDec ; Call PutDec to display the year value

    mov ah, 4Ch ; Set the value of AH register to 4Ch to exit the program
    int 21h ; Call DOS Service to exit the program
    
_Exit 0 ; Exit the program
Main ENDP
END Main ; Tells where to start execution