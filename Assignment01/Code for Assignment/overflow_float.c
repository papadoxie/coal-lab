#include <stdio.h>
#include <float.h>

int main(void){
    printf("Float overflow: %f\n", FLT_MAX + FLT_MAX);
    printf("Float underflow: %f\n", 0.0000125);

    return 0;
}