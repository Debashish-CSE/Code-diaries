section .bss
inbuf1 resb 64 ; Input buffer for first number
inbuf2 resb 64 ; Input buffer for second number

section .data
prompt1 db "Enter first number: ", 0
prompt2 db "Enter second number: ", 0
before_msg db "Before swap: ", 0
after_msg db "After swap: ", 0
newline db 10, 0
space_char db " ", 0
zero_digit db "0", 0

section .text
global _start

_start:
    ; Print first prompt
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rsi, prompt1 ; message address
    mov rdx, 20 ; message length
    syscall ; invoke system call

    ; Read first number
    mov rax, 0 ; sys_read system call
    mov rdi, 0 ; stdin file descriptor
    mov rsi, inbuf1 ; buffer address
    mov rdx, 64 ; buffer size
    syscall ; invoke system call

    ; Parse first number into r8
    mov rsi, inbuf1 ; source buffer
    call parse_number ; convert ASCII to integer
    mov r8, rax ; store first number in r8

    ; Print second prompt
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rsi, prompt2 ; message address
    mov rdx, 21 ; message length
    syscall ; invoke system call

    ; Read second number
    mov rax, 0 ; sys_read system call
    mov rdi, 0 ; stdin file descriptor
    mov rsi, inbuf2 ; buffer address
    mov rdx, 64 ; buffer size
    syscall ; invoke system call

    ; Parse second number into r9
    mov rsi, inbuf2 ; source buffer
    call parse_number ; convert ASCII to integer
    mov r9, rax ; store second number in r9

    ; Display before swap
    call print_before_swap

    ; Perform swap using register exchange
    xchg r8, r9 ; Exchange values in r8 and r9

    ; Display after swap
    call print_after_swap

    ; Program termination
    mov rax, 60 ; sys_exit system call
    xor rdi, rdi ; exit status 0
    syscall ; invoke system call

parse_number:
    ; Function to convert ASCII string to integer
    ; Input: RSI = string address
    ; Output: RAX = integer value
    xor rax, rax ; clear result
    xor rbx, rbx ; clear temporary register
    parse_loop:
        mov bl, [rsi] ; load character
        cmp bl, 10 ; check for newline
        je parse_done ; exit if newline
        cmp bl, '0' ; check if less than '0'
        jl parse_done ; exit if not digit
        cmp bl, '9' ; check if greater than '9'
        jg parse_done ; exit if not digit
        sub bl, '0' ; convert to digit
        imul rax, 10 ; multiply result by 10
        add rax, rbx ; add current digit
        inc rsi ; move to next character
        jmp parse_loop ; continue parsing
    parse_done:
        ret ; return with result in RAX

print_before_swap:
    ; Print before swap message
    mov rax, 1
    mov rdi, 1
    mov rsi, before_msg
    mov rdx, 13 ; length of "Before swap: "
    syscall
    
    ; Print first number
    mov rax, r8
    call print_number
    call print_space
    
    ; Print second number
    mov rax, r9
    call print_number
    call print_newline
    ret

print_after_swap:
    ; Print after swap message
    mov rax, 1
    mov rdi, 1
    mov rsi, after_msg
    mov rdx, 12 ; length of "After swap: "
    syscall
    
    ; Print first number (now swapped)
    mov rax, r8
    call print_number
    call print_space
    
    ; Print second number (now swapped)
    mov rax, r9
    call print_number
    call print_newline
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
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

print_space:
    mov rax, 1
    mov rdi, 1
    mov rsi, space_char
    mov rdx, 1
    syscall
    ret

print_newline:
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall
    ret