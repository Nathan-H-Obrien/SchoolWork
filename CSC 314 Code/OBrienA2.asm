;	Name: Nathan O'Brien
;	Class: CSC 314 
;	Assignment: 2
; 	Due: 09/20/23
; 	Description: This program is meant to print my name and the show I binged
;				 over the summer to the screen.

.MODEL SMALL
.586
.STACK 100h
.DATA
Message DB 'Hello, my name is Nathan OBrien', 13, 10, '$'
Sentence DB 'The show I binged watched last summer was The Rookie', 13, 10, '$'
.CODE
Hello PROC
mov ax, @data
mov ds, ax
mov dx, OFFSET Message

mov ah, 9h ; The function code for 'display string'
int 21h ; The standard way to call MS/PCDOS
mov al, 0 ; Return code of 0

mov ax, @data
mov ds, ax
mov dx, OFFSET Sentence

mov ah, 9h ; The function code for 'display string'
int 21h ; The standard way to call MS/PCDOS
mov al, 0 ; Return code of 0

mov ah, 4ch ; Exit back to MS/PCDOS
int 21h
Hello ENDP
END Hello ; Tells where to start execution