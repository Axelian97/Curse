#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long factorial(int arg) {
    long result = 1;
    int i;
    for (i = 2; i <= arg; ++i) {
        result *= i;
     }
    return result;
}

int main(int argc, char** argv) {
    printf("Type an integer and press Enter to calculate the integer's factorial: \n");
    int arg;
    fflush(stdout);
    scanf("%d", &arg);
    
    printf("factorial(%d) = %ld\n", arg, factorial(arg));

    return (EXIT_SUCCESS);
}
 