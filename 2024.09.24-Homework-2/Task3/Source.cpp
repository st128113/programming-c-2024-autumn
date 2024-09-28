#include <iostream> 
#include <cmath> 

int main(int argc, char* argv[])
{
    double a = 0;
    double b = 0;
    double c= 0;
    double d = 0;
    double e = 0;
    double f = 0;
    double dl = 0;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);
    scanf("%lf", &e);
    scanf("%lf", &f);
    dl = sqrt((a - d) * (a - d) + (b - e) * (b - e));
    if (dl <= (c + f) && dl + c >= f && dl + f >= c) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    

    return EXIT_SUCCESS;
}