#include<iostream>
#include<math.h>

int main(int argc, char* argv[])
{
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long d = 0;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    scanf("%lld", &d);

    for (int i = -100; i <= 100; ++i) {
        if (pow(i, 3) * a + pow(i, 2) * b + c * i + d == 0) {
            printf("%d\n", i);
        }
    }

    return EXIT_SUCCESS;
}