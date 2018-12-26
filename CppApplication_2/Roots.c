#include "Roots.h"

int RootsCount(double a, double b, double c)
{
    double d=b*b-4*a*c;
    if(!d) return 1;
    if(d>0) return 2; 
    return 0;
}


 
Results FindRoots(double a, double b, double c){
    double x1;
    double x2;
    int ExistenceRealRoots;
    int roots = RootsCount(a,b,c);
    switch(roots)
    {
            case 0:{
                x1=0;
                x2=0;
                ExistenceRealRoots=0;
                break;
            }
            case 1:{
                x1=(-b)/(2*a);
                x2=x1;
                ExistenceRealRoots=1;
                break;
            }
            case 2:{
                x1=(-b+sqrt(b*b-4*a*c))/(2*a);
                x2=(-b-sqrt(b*b-4*a*c))/(2*a);
                ExistenceRealRoots=1;
                break;
            }
    }
    Results res = {x1,x2,ExistenceRealRoots};
    return res;
}