#include<iostream>

int main(int argc, char* argv[])
{
    int G = 0;
    int L = 0;
    scanf("%d", &G);
    scanf("%d", &L);
    int B = G + L - 1;
    int X = L - 1;
    int Y = G - 1;
    printf("%d %d\n", X, Y);
    return EXIT_SUCCESS;
}