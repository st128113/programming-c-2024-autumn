#include<iostream>

int main(int argc, char* argv[])
{
    int v = 0;
    int t = 0;
    scanf("%d", &v);
    scanf("%d", &t);

    int d = v * t;
    int p = ((d % 109) + 109) % 109 + 1;
    printf("%d", p);

    return EXIT_SUCCESS;
}