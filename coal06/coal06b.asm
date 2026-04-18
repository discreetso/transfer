; a program to add three numbers using byte variables

[org 0x0100]

xor ax, ax              ; check effect on ZF

mov bx, num1            ; indirect addressing (register based addressing)

add ax, [bx]
add bx, 2

add ax, [bx]
add bx, 2

add ax, [bx]
add bx, 2

mov [result], ax

mov ax, 0x4c00
int 0x21

; to turn this into an iteration, we need a couple of things:
; - branching instruction
; - checking constraints--e.g. c>0; Intel software development manual-figure3-8(page80)

num1: dw 5, 10, 15
result: dw 0
