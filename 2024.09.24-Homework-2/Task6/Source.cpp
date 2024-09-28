#include <iostream>
#include <math.h>

int main(int argc, char* argv[])
{
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;
    float e = 0;
    float f = 0;
	scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

        if (a != 0)
    {
        d = b * b - 4 * a * c;
        if (d > 0)
        {
            e = (-b + sqrt(d)) / (2 * a);
            f = (-b - sqrt(d)) / (2 * a);
            printf("2 %.6f %.6f\n", e, f);
        }
        else if (d == 0)
        {
            e = -b / (2 * a);
            printf("1 %.6f\n", e);
        }
        else
        {
            printf("0\n");
        }
    }
    else if (b != 0)
    {
        e = -c / b;
        printf("1 %.6f\n", e);
    }
    else if (c == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("0\n");
    }
    
    return EXIT_SUCCESS;
}
