org 100h

start:
    mov ax, cs
    mov ds, ax

    ; prompt
    mov ah, 09h
    mov dx, offset prompt
    int 21h

    ; read 1 digit
    mov ah, 01h
    int 21h          ; AL = key pressed
    sub al, '0'      ; convert ASCII -> number
    mov cl, al       ; CL = total rows

    cmp cl, 0
    jz program_exit  ; if 0, exit

    ; print newline after input
    mov ah, 09h
    mov dx, offset newline
    int 21h

    mov si, 1        ; current row = 1

row_loop:
    mov bx, si       ; BX = number of stars to print
star_loop:
    mov dl, '*'
    mov ah, 02h
    int 21h
    dec bx
    jnz star_loop

    ; print newline (CR LF)
    mov ah, 09h
    mov dx, offset newline
    int 21h

    inc si           ; next row
    cmp si, cx
    jle row_loop

program_exit:
    mov ah, 4Ch
    int 21h

; -------------------
; Data
; -------------------
prompt  db 'Enter number of rows (0-9): $'
newline db 13,10,'$'
