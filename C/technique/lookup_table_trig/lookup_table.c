// for 32-bit
//sin value look up table

#include<stdio.h>
#include<stdint.h>
#include<math.h>

#define PI 3.14159265358979323846
#define N 8192
int32_t sin_table[N];

int32_t sin_t(){

for (int i = 0; i < N; i++)
{
    double s = sin((i * 2 * PI) / N);
    int32_t result = (int32_t)round(s*65536);
    sin_table[i]=result;
}   
return 0;
}
int32_t cos_t(int angle){
    return sin_table[(angle+N/4)%N]; // cosine is just sine shifted by 90 degrees (N/4)
}
int32_t calculations(){
    int angle=0;
    int radius=100;
    for(int i=0;i<16;i++){
        
        int64_t x = (radius * cos_t(angle)) >> 16;
        int32_t y = (radius * sin_table[angle]) >> 16;
        printf("angle=%d  x=%ld  y=%d\n", angle, x, y);
        angle += N/16;
    }
}
void main(){
    sin_t();
    calculations();
}