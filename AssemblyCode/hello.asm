.model small
.stack 100h

.data
    msg db 'Hello, World!$'   ; $-terminated string for INT 21h AH=09h

.code
start:
    mov ax, @data
    mov ds, ax               ; set DS to point to data segment

    mov ah, 9h              ; DOS function to print string
    mov dx, offset msg       ; offset of the message
    int 21h                  ; call DOS interrupt

    mov ah, 4Ch              ; DOS function to exit program
    int 21h                  ; exit to DOS

end start

