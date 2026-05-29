section .bss
inbuf resb 64 ; Input buffer for count
outbuf resb 20 ; Output buffer for numbers

section .data
prompt db "Enter N: ", 0
space db " ", 0
newline db 10, 0
zero_char db '0' ; character for printing zero

section .text
global _start

_start:
    ; Display prompt
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rsi, prompt ; prompt message address
    mov rdx, 9 ; message length
    syscall ; invoke system call

    ; Read count
    mov rax, 0 ; sys_read system call
    mov rdi, 0 ; stdin file descriptor
    mov rsi, inbuf ; input buffer address
    mov rdx, 64 ; buffer size
    syscall ; invoke system call

    ; Parse count into RCX
    mov rsi, inbuf ; source buffer
    call parse_number ; convert to integer
    mov rcx, rax ; store count in rcx

    ; Initialize Fibonacci sequence
    mov r8, 0 ; F(0) = 0
    mov r9, 1 ; F(1) = 1

    ; Check if count is 0
    cmp rcx, 0 ; compare count with 0
    je exit_program ; exit if no numbers to print

    ; Print first number (0)
    mov rax, r8 ; move first number to rax
    call print_number ; display the number
    call print_space ; print space

    ; Check if count is 1
    dec rcx ; decrement count
    cmp rcx, 0 ; compare with 0
    je exit_program ; exit if only one number

    ; Print second number (1)
    mov rax, r9 ; move second number to rax
    call print_number ; display the number
    call print_space ; print space

    ; Decrement count for remaining numbers
    dec rcx ; decrement count

fibonacci_loop:
    ; Check if more numbers needed
    cmp rcx, 0 ; compare count with 0
    je print_newline ; exit loop if done

    ; Calculate next Fibonacci number
    mov rax, r8 ; load F(n-2)
    add rax, r9 ; add F(n-1) to get F(n)
    mov r8, r9 ; F(n-2) = old F(n-1)
    mov r9, rax ; F(n-1) = new F(n)

    ; Display the new number
    call print_number ; display F(n)
    call print_space ; print space

    ; Continue loop
    dec rcx ; decrement counter
    jmp fibonacci_loop ; continue loop

print_newline:
    ; Print newline character
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rsi, newline ; newline character
    mov rdx, 1 ; character length
    syscall ; invoke system call

exit_program:
    ; Program termination
    mov rax, 60 ; sys_exit system call
    xor rdi, rdi ; exit status 0
    syscall ; invoke system call

parse_number:
    ; Convert ASCII string to integer
    xor rax, rax ; clear result accumulator
    xor rbx, rbx ; clear temporary register
    parse_digit_loop:
        mov bl, [rsi] ; load current character
        cmp bl, 10 ; check for newline
        je parse_complete ; exit if newline found
        cmp bl, '0' ; validate lower bound
        jl parse_complete ; exit if not a digit
        cmp bl, '9' ; validate upper bound
        jg parse_complete ; exit if not a digit
        sub bl, '0' ; convert ASCII to digit
        imul rax, 10 ; multiply result by 10
        add rax, rbx ; add current digit to result
        inc rsi ; move to next character
        jmp parse_digit_loop ; continue parsing
    parse_complete:
        ret ; return with result in RAX

print_number:
    ; Convert integer to ASCII and display
    push rax
    push rbx
    push rcx
    push rdx

    ; Handle special case of 0
    cmp rax, 0
    je print_zero

    ; Convert number to string (reverse order)
    mov rbx, 10 ; divisor for base 10
    mov rcx, 0 ; digit counter
    mov rsi, outbuf ; output buffer
    add rsi, 19 ; point to end of buffer
    mov byte [rsi], 0 ; null terminator

convert_loop:
    dec rsi ; move backward in buffer
    xor rdx, rdx ; clear remainder
    div rbx ; divide by 10
    add dl, '0' ; convert remainder to ASCII
    mov [rsi], dl ; store digit
    inc rcx ; increment digit count
    cmp rax, 0 ; check if more digits
    jne convert_loop ; continue if more digits

    ; Print the converted string
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rdx, rcx ; number of digits
    syscall ; invoke system call
    jmp print_number_done ; skip zero handling

print_zero:
    ; Print single zero character
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rsi, zero_char ; zero character
    mov rdx, 1 ; single character
    syscall ; invoke system call

print_number_done:
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

print_space:
    ; Print space character for formatting
    mov rax, 1 ; sys_write system call
    mov rdi, 1 ; stdout file descriptor
    mov rsi, space ; space character
    mov rdx, 1 ; single character
    syscall ; invoke system call
    ret