#include <stdio.h>
#include <float.h>

int main(void){
    printf("Max Float: %f\n", FLT_MAX);
    printf("Min Float: %f\n", -FLT_MAX);

    printf("Max Double: %lf\n", DBL_MAX);
    printf("Min Double: %lf\n", -DBL_MAX);

    printf("Max Long Double: %Lf\n", LDBL_MAX);
    printf("Min Long Double: %Lf\n", -LDBL_MAX);

    return 0;
}