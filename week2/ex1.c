#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int maxInt = INT_MAX;
    float maxFloat = FLT_MAX;
    double maxDouble = DBL_MAX;
    printf("Maximum integer value: %d and sise %d bytes\n", maxInt, sizeof(maxInt));
    printf("Maximum float value: %f and sise %d bytes\n", maxFloat, sizeof(maxFloat));
    printf("Maximum double value: %f and sise %d bytes\n", maxDouble, sizeof(maxDouble));
    return 0;
}
