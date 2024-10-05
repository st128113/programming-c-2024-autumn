#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    int p = 0;
    if (a > b) {
        p = a;
    }
    else {
        p = b;
    }

    for (int i = p; i <= a * b; i += p) {
        if ((i % a == 0) && (i % b == 0)) {
            printf("%d", i);
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}