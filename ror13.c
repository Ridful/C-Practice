#include <stdio.h>
#include <stdint.h> //fixed-width types (uint32_t)
#include <string.h>
#include <windows.h>

uint32_t ror(uint32_t value, int bits) {
    return (value >> bits) | (value << (32 - bits));
}

uint32_t ror13_hash(const char *str) {
    uint32_t hash = 0;
    while (*str) {
        hash = ror(hash, 13);
        hash += (unsigned char)(*str);
        str++;
    }
    return hash;
}

int main() {
    const char *name = "VirtualAlloc";
    printf("ROR13 hash of \"%s\" = 0x%08X\n", name, ror13_hash(name));

    return 0;
}