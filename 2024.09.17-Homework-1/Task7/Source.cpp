#include<iostream>

int main(int argc, char* argv[])
{
    int V = 0;
    int T = 0;
    scanf("%d", &V);
    scanf("%d", &T);
    int D = V * T;
    int P = ((D % 109) + 109) % 109 + 1;
    printf("%d", P);
    return EXIT_SUCCESS;
}