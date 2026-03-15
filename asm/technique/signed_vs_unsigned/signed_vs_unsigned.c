#include <stdio.h>
#include <stdint.h>

extern int32_t asm_shr(int32_t value, int32_t shift);
extern int32_t asm_shl(int32_t value, int32_t shift);
extern int32_t asm_sar(int32_t value, int32_t shift);
extern int32_t asm_sal(int32_t value, int32_t shift);

int main(){
    int32_t value=-3;
    int8_t shift=1;
    printf("Original=%d \n", value);
    printf("shift right unsigned is %d\n",asm_shr(value,shift));
    printf("shift right signed is %d\n",asm_sar(value,shift));
    printf("shift left unsigned is %d\n", asm_shl(value,shift));
    printf("shift left signed is %d\n", asm_sal(value,shift));

}