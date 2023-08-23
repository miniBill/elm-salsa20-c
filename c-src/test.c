#include <stdint.h>
#include <stdio.h>

#include "reference.h"

void print_hex(uint32_t array[16])
{
    for (int row = 0; row < 8; row++)
    {
        printf("  ");
        for (int column = 0; column < 8; column++)
        {
            if (column > 0)
            {
                printf(" ");
            }
            uint8_t byte = array[row * 2 + column / 4] >> (column % 4 * 8);
            printf("%3d", byte);
        }
        printf("\n");
    }
}

int main()
{
    uint8_t example[64] = {
        211, 159, 13, 115, 76, 55, 82, 183,
        3, 117, 222, 37, 191, 187, 234, 136,
        49, 237, 179, 48, 1, 106, 178, 219,
        175, 199, 166, 48, 86, 16, 179, 207,
        31, 240, 32, 63, 15, 83, 93, 161,
        116, 147, 48, 113, 238, 55, 204, 36,
        79, 201, 235, 79, 3, 81, 156, 47,
        203, 26, 244, 243, 88, 118, 104, 54};
    uint32_t arr[16];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 4; j >= 0; j--)
        {
            arr[i] <<= 8;
            arr[i] |= example[i * 4 + j];
        }
    }
    printf("Init:\n");
    print_hex(arr);
    salsa20_word_specification(arr, arr);
    printf("After one round:\n");
    print_hex(arr);
}
