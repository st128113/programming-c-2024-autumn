#include<iostream>

int main(int argc, char* argv[])
{
    int s = 0;
    scanf("%d", &s);
    
    int x = s / 6;
    int k = 4 * x;

    printf("%d\n", x);
    printf("%d\n", k);
    printf("%d\n", x);
    
    return EXIT_SUCCESS;
}