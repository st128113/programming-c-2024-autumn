#include<iostream>

int main(int argc, char* argv[])
{
    int A = 0;
    int N = 0;
    int B = 0;
    scanf("%d", &N);
    scanf("%d", &A);
    scanf("%d", &B);
    int C = A * B * 2 * N;
    printf("%d", C);
    return EXIT_SUCCESS;
}