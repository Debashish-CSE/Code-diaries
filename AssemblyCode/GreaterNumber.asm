org 100h

.data
    msg1 db 'Enter first number: $'
    msg2 db 0Dh,0Ah,'Enter second number: $'
    msg3 db 0Dh,0Ah,'Greater number is: $'
    num1 db ?
    num2 db ?

.code
start:
    ; Print msg1
    mov ah, 09h
    lea dx, msg1
    int 21h

    ; Read first number (single digit for simplicity)
    mov ah, 01h
    int 21h
    sub al, '0'
    mov num1, al

    ; Print msg2
    mov ah, 09h
    lea dx, msg2
    int 21h

    ; Read second number
    mov ah, 01h
    int 21h
    sub al, '0'
    mov num2, al

    ; Compare numbers
    mov al, num1
    mov bl, num2
    cmp al, bl
    jge first_is_greater

    ; Second is greater
    mov al, bl

first_is_greater:
    ; Print msg3
    mov ah, 09h
    lea dx, msg3
    int 21h

    ; Print greater number
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h

end start