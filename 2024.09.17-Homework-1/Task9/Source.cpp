#include<iostream>

int main(int argc, char* argv[])
{
    int h = 0;
    int a = 0;
    int b = 0;
    scanf("%d", &h);
    scanf("%d", &a);
    scanf("%d", &b);

    int n = a - b;
    int d = (h <= a) ? 1 : ((h - a + n - 1) / n + 1);
    printf("%d", d);

    return EXIT_SUCCESS;
}