#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (c <= a) {
        d = 2 * b;
    }
    else if (c * 2 % a == 0) {
        d = b * (c * 2 / a);
    }
    else {
        d = b * (1 + (c * 2 / a));
    }

    printf("%d", d);

    return EXIT_SUCCESS;
}