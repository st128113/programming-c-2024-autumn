#include<iostream>

int main(int argc, char* argv[])
{
    long long a = 0;
    long long b = 0;
    scanf("%lld", &a);
    scanf("%lld", &b);
    long long c = a;
    long long d = b;

    while (d != 0) {
        long long t = d;
        d = c % d;
        c = t;
    }
    long long s = a / c;
    printf("%lld", s);

    return EXIT_SUCCESS;
}