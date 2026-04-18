; a program to add three numbers accessed using a single label

[org 0x0100]

mov ax, [num1]
mov bx, [num1+2]          ; notice how we can do arithmetic here

add ax, bx                ; also why +2, not +1?

mov bx, [num1+4]

add ax, bx

mov [num1+6], ax          ; store sum at num1+6

mov ax, 0x4c00
int 0x21

num1: dw 5, 10, 15, 0     ; another way to define words