.intel_syntax noprefix
.global main
.text

main:
    mov eax, 9
    call fib
    push eax
    mov eax, offset msg
    push eax
    call printf
    add esp, 8
    ret

fib:
    cmp eax, 3
    ja rekursja
    mov eax, 1
    ret

rekursja:
    push ebp
    mov ebp, esp
    sub esp, 8
    mov [ebp - 8], eax
    dec eax
    call fib

    mov [ebp - 4], eax
    mov eax, [ebp - 8]
    dec eax
    dec eax
    call fib
    add eax, eax
    add eax, [ebp - 4]

    mov [ebp - 4], eax
    mov eax, [ebp - 8]

    dec eax
    dec eax
    dec eax
    call fib
    add eax, [ebp - 4]

    leave
    ret

.data

msg: .asciz "fib = %i\n"
