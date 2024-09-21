#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    scanf("%d", &a);
    int b = a + 1;
    int c = a - 1;

    printf("The next number for the number %d is %d.\n", a, b);
    printf("The previous number for the number %d is %d.\n", a, c);
    
    return EXIT_SUCCESS;
}