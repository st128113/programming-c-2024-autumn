#include<iostream>

int main(int argc, char* argv[])
{
    int g = 0;
    int l = 0;
    scanf("%d", &g);
    scanf("%d", &l);

    int b = g + l - 1;
    int x = l - 1;
    int y = g - 1;
    printf("%d %d\n", x, y);

    return EXIT_SUCCESS;
}