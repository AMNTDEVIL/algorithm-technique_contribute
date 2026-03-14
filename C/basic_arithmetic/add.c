#include <stdio.h> //contains main, printf, scanf and so on
#include <stdint.h> //provides signed and unsigned int
#include <limits.h>
//normal add for integer
int add_int(int x, int y){
    return x+y;
}
//addition of 2 positive number with unsigned int 32bit
int32_t add_32bit(int32_t x, int32_t y){
    if(y>0 && x > INT32_MAX -y ) return INT32_MAX;
    if(y<0 && x<INT32_MIN-y) return INT32_MIN;
    return x+y;
}

//addition of floating point
float add_float(float x, float y){
    return x+y;
}
double add_double(double x, double y){
    return x+y;
}
void main(){
    //integer add
    printf("Result of addition of int\n");
    printf("%d\n",add_int(2,3)); //result 5
    printf("%d\n",add_int(-1,2));
    printf("%d\n",add_int(-1,-1));
    //32 bit
    printf("Result of addition of signed int 32bit\n");
    printf("%d\n",add_32bit(2,3));
    printf("%d\n",add_32bit(-1,2));
    printf("%d\n",add_32bit(9999999,999999));
    printf("%d\n",add_32bit(-1,-1));
    //float
    printf("Result of addition of float\n");
    printf("%.f\n",add_float(2.0,3.0));
    printf("%.f\n",add_float(2.1,-1.1));
    //double
    printf("Result of addition of double\n");
    printf("%.6f\n",add_double(2.1212,3.2121));
    printf("%.6f\n",add_double(2.1212,-1.1212));
}