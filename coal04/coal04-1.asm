; a program to add three variables uisng memory addresses

[org 0x0100]
; start of code

mov ax, [num1]          ; load first number in ax
mov bx, [num2]

add ax, bx

mov bx, [num3]
mov [num4], ax

mov ax, 0x4c00
int 0x21

num1: dw 5
num2: dw 10
num3: dw 15
num4: dw 0

; watch the listing carefully