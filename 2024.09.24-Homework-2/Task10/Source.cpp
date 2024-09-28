#include<iostream>

int main(int argc, char* argv[])
{
    int a;
    scanf("%d", &a);

    int b = a / 5;

    if (b < 0) {
        printf("-1 ");
        printf("-1");
        return -1;
    }

    if ((a - b * 5) % 3 == 0) {
        printf("%d ", b);
        printf("%d", (a - b * 5) / 3);
    }
    else if (b > 0) {
        --b;
        if ((a - b * 5) % 3 == 0) {
            printf("%d ", b);
            printf("%d", (a - b * 5) / 3);
        }
        else if (--b >= 0 && (a - b * 5) % 3 == 0) {
            printf("%d ", b);
            printf("%d", (a - b * 5) / 3);
        }
        else {
            printf("-1 ");
            printf("-1");
        }
    }
    else {
        printf("-1 ");
        printf("-1");
    }

    return EXIT_SUCCESS;
}