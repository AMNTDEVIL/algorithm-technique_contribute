#include<stdio.h>
#include<stdint.h>
#include <limits.h>

void signed_vs_unsigned(){
    int8_t signed_positive=3;
    int8_t signed_negative=-3;
    uint8_t unsigned_positive=3;
    uint8_t unsigned_negative=-3;
    printf("signed positive for 3=%d \t signed negative for -3 =%d\n",signed_positive, signed_negative);
    printf("unsigned positive for 3=%d \t unsigned negative for -3=%hhu\n",unsigned_positive, unsigned_negative);
}
void range(){
    printf("range of unsigned for 8bit is 0 to %d\n",UINT8_MAX);
    printf("range of signed for 8bit is %d to %d \n",INT8_MIN,INT8_MAX);
    printf("range of unsigned for 16bit is 0 to %d\n",UINT16_MAX);
    printf("range of signed for 16bit is %d to %d \n",INT16_MIN,INT16_MAX);
    printf("range of unsigned for 32bit is 0 to %u\n",UINT32_MAX);
    printf("range of signed for 32bit is %d to %d \n",INT32_MIN,INT32_MAX);
    printf("range of unsigned for 64bit is 0 to %lu\n",UINT64_MAX);
    printf("range of unsigned for 64bit is %ld to %lu\n",INT64_MIN,INT64_MAX);
}
int main(){
    signed_vs_unsigned();
    range();
    return 0;
}