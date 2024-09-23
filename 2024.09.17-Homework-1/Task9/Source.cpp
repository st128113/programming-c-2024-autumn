#include <iostream>

int main(int argc, char* argv[])
{
    int h = 0;
    int a = 0;
    int b = 0;
    int d = 0;

    scanf_s("%d", &h);
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    int f = (a - b);
    int g = h % f;
    int k = (f - g) % f;

    h += k;

    int i = h - a;
    int j = h / a;
    int l = i / a;

    h = i * (j - l);

    d++;

    h += ((a - b) - h % (a - b)) % (a - b);

    d += h / (a - b);

    printf("%d", d);

    return EXIT_SUCCESS;
}
