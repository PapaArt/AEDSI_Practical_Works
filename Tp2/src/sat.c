#include "sat.h"

void print_binary(int n, int leng)
{
    long long  int bit = 1 << leng - 1;
    while (bit)
    {
        printf("%d", n & bit ? 1 : 0);
        bit >>= 1;
    }
    printf("\n");
}
