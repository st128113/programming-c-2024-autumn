#include<iostream>
#include <math.h>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("-1\n");
            }
            else {
                printf("0\n");
            }
        }
        else {
            double x = -c / (double)b;
            printf("1\n");
            printf("%.6f\n", x);
        }
    }
    else {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            double sqrt_d = sqrt(d);
            double x1 = (-b + sqrt_d) / (2 * a);
            double x2 = (-b - sqrt_d) / (2 * a);
            printf("2\n");
            printf("%.6f\n", x1);
            printf("%.6f\n", x2);
        }
        else if (d == 0) {
            double x = -b / (2 * a);
            printf("1\n");
            printf("%.6f\n", x);
        }
        else {
            printf("-1\n");
        }
    }


    return EXIT_SUCCESS;
}