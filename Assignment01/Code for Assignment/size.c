#include <stdio.h>
#include <limits.h>
#define UCHAR_MIN 0
#define USHRT_MIN 0
#define UINT_MIN 0
#define ULONG_MIN 0
#define ULLONG_MIN 0

int main(void){
    printf("Max char: %i\n", CHAR_MAX);
    printf("Min char: %i\n", CHAR_MIN);
    printf("Max unsigned char: %i\n", UCHAR_MAX);
    printf("Min unsigned char: %i\n", UCHAR_MIN);

    printf("Max short: %hi\n", SHRT_MAX);
    printf("Min short: %hi\n", SHRT_MIN);
    printf("Max unsigned short: %i\n", USHRT_MAX);
    printf("Min unsigned short: %i\n", USHRT_MIN);


    printf("Max int: %i\n", INT_MAX);
    printf("Min int: %i\n", INT_MIN);
    printf("Max unsigned int: %li\n", UINT_MAX);
    printf("Min unsigned int: %i\n", UINT_MIN);

    printf("Max long: %li\n", LONG_MAX);
    printf("Min long: %li\n", LONG_MIN);
    printf("Max unsigned long: %lu\n", ULONG_MAX);
    printf("Min unsigned long: %i\n", ULONG_MIN);

    printf("Max long long: %lli\n", LLONG_MAX);
    printf("Min long long: %lli\n", LLONG_MIN);
    printf("Max unsigned long long: %llu\n", ULLONG_MAX);
    printf("Min unsigned long long: %i\n", ULLONG_MIN);

    return 0;
}
