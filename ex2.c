// majac liczbe w systemie szesnastkowym, znajdz najdluzszy ciag jedynek 
// w jej systemie binarnym

#include <stdio.h>

int main() {

    int liczba = 0xc37e0a10;
    int wynik;

    asm(
            ".intel_syntax noprefix;"
            "mov eax, %1;"
            "mov ebx, 32;"
            "mov ecx, 0;"            
            "mov edx, 0;"
            "petla:"
                "shl eax;"
                "jnc skok;"
                "inc ecx;"
                "mov edx, ecx;"
            "skok:"
                "dec ebx;"
                "jnz petla;"
                "mov %0, edx;"
            ".att_syntax prefix;"
            : "=r" (wynik)
            : "r" (liczba)
            : "eax", "ebx", "ecx", "edx"
    );

    printf("wynik: %i\n", wynik);

    return 0;

}
