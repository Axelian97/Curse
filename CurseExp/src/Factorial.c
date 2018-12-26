#include "Factorial.h"

long factorial(int arg)
{
    long result = 1;
    int i;
    for (i = 2; i <= arg; ++i) {
        result *= i;
     }
    return result;
}