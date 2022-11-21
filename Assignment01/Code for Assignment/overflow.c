#include <stdio.h>
#include <limits.h>
#define UINT_MIN 0

int main(void){
    printf("Integer Positive Overflow: %i\n", INT_MAX + 1);
    printf("Integer Negative Overflow: %i\n", INT_MIN - 1);

    printf("Unsigned Integer Positive Overflow: %lu\n", UINT_MAX + 1);
    printf("Unsigned Integer Negative Overflow: %lu\n", UINT_MIN - 1);

    return 0;
}