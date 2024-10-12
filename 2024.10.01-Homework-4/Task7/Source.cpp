#include<iostream>

int main(int argc, char* argv[])
{
    int c = 0;
    scanf("%d", &c);
    int d[1000];


    for (int i = 0; i < c; ++i) {
        scanf("%d", &d[i]);
    }

    for (int i = c - 1; i >= 0; --i) {
        printf("%d ", d[i]);
    }

    return EXIT_SUCCESS;
}