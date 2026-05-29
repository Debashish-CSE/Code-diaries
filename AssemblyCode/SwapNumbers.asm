org 100h

.data
    msg1 db 'Enter first number: $'
    msg2 db 0Dh,0Ah,'Enter second number: $'
    msg3 db 0Dh,0Ah,'Before swapping:$'
    msg4 db 0Dh,0Ah,'First number: $'
    msg5 db 0Dh,0Ah,'Second number: $'
    msg6 db 0Dh,0Ah,'After swapping:$'
    msg7 db 0Dh,0Ah,'First number: $'
    msg8 db 0Dh,0Ah,'Second number: $'
    num1 db ?
    num2 db ?
    temp db ?

.code
start:
    ; Print msg1
    mov ah, 09h
    lea dx, msg1
    int 21h

    ; Read first number (single digit)
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

    ; Display numbers before swapping
    mov ah, 09h
    lea dx, msg3
    int 21h

    mov ah, 09h
    lea dx, msg4
    int 21h

    mov al, num1
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

    mov ah, 09h
    lea dx, msg5
    int 21h

    mov al, num2
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

    ; Swap the numbers
    ; temp = num1
    mov al, num1
    mov temp, al

    ; num1 = num2
    mov al, num2
    mov num1, al

    ; num2 = temp
    mov al, temp
    mov num2, al

    ; Display numbers after swapping
    mov ah, 09h
    lea dx, msg6
    int 21h

    mov ah, 09h
    lea dx, msg7
    int 21h

    mov al, num1
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

    mov ah, 09h
    lea dx, msg8
    int 21h

    mov al, num2
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h

end start
