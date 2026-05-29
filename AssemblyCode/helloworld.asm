section .data
    msg db "Hello, World!", 0xA
    len equ $ - msg

section .text
    global _start
 
_start:
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; stdout
    mov rsi, msg        ; message to print
    mov rdx, len        ; message length
    syscall

    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; exit code 0
    syscall