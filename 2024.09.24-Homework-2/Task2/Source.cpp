#include<iostream>

int main(int argc, char* argv[])
{
    long long a = 0;
    long long b = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    if (a == 1 && b == 1) {
        printf("0");
    }
    else if (a != b) {
        printf("1");
    }
    else {
        printf("2");
    }

    return EXIT_SUCCESS;
}