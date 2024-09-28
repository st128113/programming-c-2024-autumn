#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    if (a == 1 || b == 1) {
        printf("%d", (a * b) * 4);
    }
    else {
        int c = (b + 2) * a + b * (a + 2);
        if (a % 2 == 1 && b % 2 == 1) {
            c -= 2;
        }
        printf("%d", c);
    }

    return EXIT_SUCCESS;
}