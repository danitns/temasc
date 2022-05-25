extern printf
extern scanf

section .data
    x dq 1
    counter dq 0
    e_x dq 1.0
    e_nx dq 1.0
    summ dq 1.0
    subb dq 1.0
    divv dq 1.0
    e dq 2.79
    plus dq 1
    ec dq 1.0

    f_ecuatie db "%lf / %lf = %lf",10,0

    f_lf db "%lf",10,0

    f_read db "%d\n",0

    ec_msg db "tanh(x) = ( e^x + e^(-x) ) / ( e^x - e^(-x) )",10,0
    len_ec_msg equ $ - ec_msg

    scanf_msg db "x: ", 9,10
    len_scanf_msg equ $ - scanf_msg

section .text

global main
main:

    push rbp
    mov rbp, rsp

    ; Print ec_msg
    mov ecx, 0
    mov edx, 0
    mov ecx, ec_msg
    mov edx, len_ec_msg
    mov ebx, 1
    mov eax, 4
    int 0x80

    ; Print scanf_msg
    mov ecx, 0
    mov edx, 0
    mov ecx, scanf_msg
    mov edx, len_scanf_msg
    mov ebx, 1 
    mov eax, 4
    int 0x80

    ; Scanf, x
    mov rdi, f_read
    mov rax, 0 
    mov rsi, x
    call scanf
    ; movsd qword [x], xmm0
    ; movsd xmm0, [x]

    ; e^x

    movsd xmm0, [e_x]
    movsd xmm1, [e]
    mulsd xmm0, xmm1
    movsd [e_x], xmm0
    movsd [e_nx], xmm0

    movsd xmm0, [e_x]
    movsd xmm1, [e]
    mulsd xmm0, xmm1
    movsd [e_x], xmm0
    movsd [e_nx], xmm0

    ; jloop:

    ; mov rax, [x]
    ; jnz multiply
    ; jmp out


    ; multiply:
    ; ;e^x * e
    ; movsd xmm0, [e_x]
    ; movsd xmm1, [e]
    ; mulsd xmm0, xmm1
    ; movsd [e_x], xmm0
    ; ;x--
    ; dec byte [x]
    ; jmp jloop 

    ; out:

    ; e^(-x)
    movsd xmm0, [divv]
    movsd xmm1, [e_nx]
    divsd xmm0, xmm1
    movsd [e_nx], xmm0

    ; e^x + e^(-x)
    movsd xmm0, [e_x]
    addsd xmm0, [e_nx]
    movsd [summ], xmm0

    ; e^x - e^(-x)
    movsd xmm0, [e_x]
    subsd xmm0, [e_nx]
    movsd [subb], xmm0

    ; e^x + e^(-x) / e^x - e^(-x)
    movsd xmm0, [summ]
    movsd xmm1, [subb]
    divsd xmm0, xmm1
    movsd [ec], xmm0

    ; print
    mov ecx, 0
    mov edx, 0
    mov rdi,f_ecuatie
    movsd xmm0, [summ]
    movsd xmm1, [subb]
    movsd xmm2, [ec]
    mov rax, 3 
    call printf

    mov rsp, rbp
    pop rbp 
    ret

