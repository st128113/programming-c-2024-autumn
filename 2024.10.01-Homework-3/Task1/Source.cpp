#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d", &a);

    for (int i = 0; i < a; ++i) {
        int q = 0;
        scanf("%d", &q);
        if (q == 0) {
            b = b + 1;
        }
        else {
            c = c + 1;
        }
    }

    if (b > c) {
        printf("%d", c);
    }
    else {
        printf("%d", b);
    }



    return EXIT_SUCCESS;
}