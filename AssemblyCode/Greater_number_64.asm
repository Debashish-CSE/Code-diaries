section .bss
inbuf1 resb 64 ; Input buffer for first number
inbuf2 resb 64 ; Input buffer for second number

section .data
prompt1 db "Enter first number: ", 0
prompt2 db "Enter second number: ", 0
result_msg db "Greater number is: ", 0
newline db 10, 0
zero_digit db "0", 0

section .text
global _start

_start:
    ; Display first prompt and read number
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt1
    mov rdx, 20
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, inbuf1
    mov rdx, 64
    syscall

    ; Parse first number
    mov rsi, inbuf1
    call parse_number
    mov r8, rax

    ; Display second prompt and read number
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt2
    mov rdx, 21
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, inbuf2
    mov rdx, 64
    syscall

    ; Parse second number
    mov rsi, inbuf2
    call parse_number
    mov r9, rax

    ; Compare and select maximum
    cmp r8, r9
    jge first_is_greater
    mov rbx, r9
    jmp display_result

first_is_greater:
    mov rbx, r8

display_result:
    ; Display result message
    mov rax, 1
    mov rdi, 1
    mov rsi, result_msg
    mov rdx, 19
    syscall

    ; Convert and display the greater number
    mov rax, rbx
    call print_number

    ; Program termination
    mov rax, 60
    xor rdi, rdi
    syscall

parse_number:
    ; Convert ASCII string to integer
    xor rax, rax
    xor rbx, rbx
    parse_loop:
        mov bl, [rsi]
        cmp bl, 10
        je parse_done
        cmp bl, '0'
        jl parse_done
        cmp bl, '9'
        jg parse_done
        sub bl, '0'
        imul rax, 10
        add rax, rbx
        inc rsi
        jmp parse_loop
    parse_done:
        ret

print_number:
    ; Convert integer to ASCII and display
    push rax
    push rbx
    push rcx
    push rdx
    push rsi

    ; Handle special case of 0
    cmp rax, 0
    je print_zero

    ; Convert number to string (reverse order)
    mov rbx, 10 ; divisor for base 10
    mov rcx, 0 ; digit counter
    mov rsi, rsp ; use stack as buffer
    sub rsp, 32 ; allocate stack space

convert_loop:
    xor rdx, rdx ; clear remainder
    div rbx ; divide by 10
    add dl, '0' ; convert remainder to ASCII
    dec rsi
    mov [rsi], dl ; store digit
    inc rcx ; increment digit count
    cmp rax, 0 ; check if more digits
    jne convert_loop ; continue if more digits

    ; Print the converted string
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rdx, rcx ; number of digits
    syscall ; invoke system call
    
    add rsp, 32 ; restore stack
    jmp print_number_done

print_zero:
    ; Print single zero character
    mov rax, 1
    mov rdi, 1
    mov rsi, zero_digit
    mov rdx, 1
    syscall

print_number_done:
    ; Print newline after the number
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall
    
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret