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
