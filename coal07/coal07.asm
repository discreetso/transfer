; a program to add ten numbers

[org 0x0100]

; initialize stuff
xor ax, ax          ; reset the accumulator
mov bx, 0           ; set the base
mov cx, 10          ; set the iterator count

outerloop:
    add ax, [num1+bx]
    add bx, 2

    sub cx, 1
    jnz outerloop

mov [result], ax
mov ax, 0x4c00
int 0x21

; Intel Software Development Manual - EFLAGS AND INSTRUCTIONS (page 435)

num1: dw 10, 20, 30, 40, 50, 10, 20, 30, 40, 50
result: dw 0