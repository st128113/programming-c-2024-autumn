#include<iostream>

int main(int argc, char* argv[])
{
    int k = 0;
    int w = 0;
    int a1 = 0;
    int b1 = 0;
    int a2 = 0;
    int b2 = 0;
    int a3 = 0;
    int b3 = 0;
    scanf("%d", &k);
    scanf("%d", &w);
    scanf("%d", &a1);
    scanf("%d", &b1);
    scanf("%d", &a2);
    scanf("%d", &b2);
    scanf("%d", &a3);
    scanf("%d", &b3);

    if (b1 >= k && a1 <= w) {
        printf("YES\n");
        return EXIT_SUCCESS;
    }

    if (b2 >= k && a2 <= w) {
        printf("YES\n");
        return EXIT_SUCCESS;
    }

    if (b3 >= k && a3 <= w) {
        printf("YES\n");
        return EXIT_SUCCESS;
    }

    if ((b1 + b2) >= k && (a1 + a2) <= w) {
        printf("YES\n");
        return EXIT_SUCCESS;
    }

    if ((b1 + b3) >= k && (a1 + a3) <= w) {
        printf("YES\n");
        return EXIT_SUCCESS;
    }

    if ((b2 + b3) >= k && (a2 + a3) <= w) {
        printf("YES\n");
        return EXIT_SUCCESS;
    }

    if ((b1 + b2 + b3) >= k && (a1 + a2 + a3) <= w)
    {
        printf("YES\n");
        return EXIT_SUCCESS;
    }

    printf("NO\n");

    return EXIT_SUCCESS;
}