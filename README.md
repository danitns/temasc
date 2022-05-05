# Tema arhitectura sistemelor de calcul

Se citeste un numar natural n. Se se afiseze un mesaj pe ecran de n ori.

NASM Assembly:

```
section .text

global _start

_start:
    mov edx, 1
    mov ecx, nr
    mov ebx, 0
    mov eax, 3
    int 0x80
    
    mov eax, [nr]
    sub eax, '0'
    mov [nr], eax
    
    top:
    mov eax, [nr]
    jnz print
    jmp done
    
    print:
    mov edx, len1
    mov ecx, msg1
    mov ebx, 1
    mov eax, 4
    int 0x80
    dec byte [nr]
    jmp top
    
    done:
    mov eax, 1
    mov ebx, 0
    int 0x80

section .data
    msg1 db "Mesaj 1", 0xd
    len1 equ $ - msg1

segment .bss
    nr resb 1

```

C: 
```
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n != 0)
    {
        printf("mesaj\n");
        n--;
    }
    return 0;
}
/*
.LC0:
        .byte 0x25,0x64,0x0
.LC1:
        .byte 0x6d,0x65,0x73,0x61,0x6a,0xa,0x0
main:
        pushl %ebp
        movl %esp,%ebp
        subl $4,%esp
        leal -4(%ebp),%eax
        pushl %eax
        pushl $.LC0
        call __isoc99_scanf
        leal 8(%esp),%esp
.L2:
        cmpl $0,-4(%ebp)
        je .L3
        pushl $.LC1
        call printf
        decl -4(%ebp)
        leal 4(%esp),%esp
        jmp .L2
.L3:
        xorl %eax,%eax
        jmp .L1
.L1:
        leave
        ret
 */
```
