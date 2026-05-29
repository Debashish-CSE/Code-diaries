section .bss
inbuf resb 64 ; Input buffer for number

section .data
prompt db "Enter a number: ", 0
prime_msg db "Prime", 10, 0
not_prime_msg db "Not Prime", 10, 0

section .text
global _start

_start:
    ; Display prompt
    mov rax, 1 ; sys_write
    mov rdi, 1 ; stdout
    mov rsi, prompt
    mov rdx, 16 ; length of prompt
    syscall

    ; Read number
    mov rax, 0 ; sys_read
    mov rdi, 0 ; stdin
    mov rsi, inbuf
    mov rdx, 64
    syscall

    ; Parse number
    mov rsi, inbuf
    call parse_number
    mov r8, rax ; store number in r8

    ; Check if number is less than 2
    cmp r8, 2
    jl not_prime

    ; Check if number equals 2
    cmp r8, 2
    je is_prime

    ; Check if number is even (except 2)
    mov rax, r8
    mov rdx, 0
    mov rbx, 2
    div rbx
    cmp rdx, 0
    je not_prime

    ; Initialize divisor for trial division
    mov rbx, 3 ; Start with divisor 3

loop_check:
    ; Check if divisor * divisor > number
    mov rax, rbx
    mul rbx ; RBX * RBX
    cmp rax, r8
    jg is_prime ; If divisor^2 > number, it's prime

    ; Check if number is divisible by current divisor
    mov rax, r8
    mov rdx, 0
    div rbx
    cmp rdx, 0
    je not_prime ; If remainder is 0, not prime

    ; Increment divisor by 2 (check only odd numbers)
    add rbx, 2
    jmp loop_check

is_prime:
    ; Display prime message
    mov rax, 1
    mov rdi, 1
    mov rsi, prime_msg
    mov rdx, 6 ; length of "Prime\n"
    syscall
    jmp exit

not_prime:
    ; Display not prime message
    mov rax, 1
    mov rdi, 1
    mov rsi, not_prime_msg
    mov rdx, 10 ; length of "Not Prime\n"
    syscall

exit:
    ; Program termination
    mov rax, 60 ; sys_exit
    xor rdi, rdi ; exit status 0
    syscall

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