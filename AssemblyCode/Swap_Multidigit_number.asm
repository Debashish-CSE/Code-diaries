org 100h        ; COM file origin

; Data section
.data
num1 dw ?                  ; First number
num2 dw ?                  ; Second number
temp dw ?                  ; Temporary for swap
prompt1 db 'Enter first number: $'
prompt2 db 'Enter second number: $'
before_msg db 'Before swap: $'
after_msg db 'After swap: $'
newline db 13, 10, '$'

; Code section
.code
start:
    ; --- Display first prompt ---
    mov ah, 09h
    lea dx, prompt1
    int 21h

    ; --- Read first number ---
    call read_number
    mov num1, ax

    ; --- Display second prompt ---
    mov ah, 09h
    lea dx, prompt2
    int 21h

    ; --- Read second number ---
    call read_number
    mov num2, ax

    ; --- Display BEFORE SWAP message ---
    mov ah, 09h
    lea dx, before_msg
    int 21h

    ; Print num1
    mov ax, num1
    call print_number

    ; Print space
    mov dl, ' '
    mov ah, 02h
    int 21h

    ; Print num2
    mov ax, num2
    call print_number

    ; Newline
    mov ah, 09h
    lea dx, newline
    int 21h

    ; --- SWAP ---
    mov ax, num1
    mov temp, ax
    mov ax, num2
    mov num1, ax
    mov ax, temp
    mov num2, ax

    ; --- Display AFTER SWAP message ---
    mov ah, 09h
    lea dx, after_msg
    int 21h

    ; Print swapped num1
    mov ax, num1
    call print_number

    ; Space
    mov dl, ' '
    mov ah, 02h
    int 21h

    ; Print swapped num2
    mov ax, num2
    call print_number

    ; Newline
    mov ah, 09h
    lea dx, newline
    int 21h

    ; --- Exit program ---
    mov ah, 4Ch
    int 21h

; --------------------------------------------------
; Read multi-digit number (returns result in AX)
; --------------------------------------------------
read_number:
    push bx
    push cx
    push dx
r
    mov cx, 0          ; result = 0

read_loop:
    mov ah, 01h        ; read char
    int 21h
    cmp al, 13         ; E
