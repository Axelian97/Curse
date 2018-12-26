#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Results{
  double x1, x2;
  int ExistenceRealRoots;
}Results;
int RootsCount(double a, double b, double c);
Results FindRoots(double a, double b, double c);
