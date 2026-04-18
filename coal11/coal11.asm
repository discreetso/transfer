[org 0x0100]

jmp start

num1: dw 0x40FF

dest: dw 0x40FF
src: dw 0x1001

start:

    ; extended shift
    shl byte[num1], 1
    rcl byte[num1+1], 1




    ; addition (extended addition)
    xor ax, ax          ; clear

    mov al, byte[src]
    add byte[dest], al

    mov al, byte[src+1]
    add byte[dest+1], al

    mov ax, 0x4c00
    int 0x21