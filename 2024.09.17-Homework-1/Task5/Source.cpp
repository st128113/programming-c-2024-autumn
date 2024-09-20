#include<iostream>

int main(int argc, char* argv[])
{
    int A = 0;
    scanf("%d", &A);
    int B = A + 1;
    int C = A - 1;
    printf("The next number for the number %d is %d.\n", A, B);
    printf("The previous number for the number %d is %d.\n", A, C);
    return EXIT_SUCCESS;
}