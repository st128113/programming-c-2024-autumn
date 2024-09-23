#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int n = 0;
    int b = 0;

    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);

    int c = a * b * 2 * n;
    printf("%d", c);
    
    return EXIT_SUCCESS;
}
