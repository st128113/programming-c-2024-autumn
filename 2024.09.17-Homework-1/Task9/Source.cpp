#include<iostream>

int main(int argc, char* argv[])
{
    int H = 0;
    int A = 0;
    int B = 0;
    scanf("%d", &H);
    scanf("%d", &A);
    scanf("%d", &B);
    int N = A - B;
    int D = (H <= A) ? 1 : ((H - A + N - 1) / N + 1);
    printf("%d", D);
    return EXIT_SUCCESS;
}