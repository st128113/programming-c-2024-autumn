#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    scanf("%d", &a);

    for (int c = 1; c <= a; c++) {
        for (int d = 1; d <= a; d++) {
            int e;
            scanf("%d", &e);

            if (e == 1 && c < d) {
                b++;
            }
        }
    }
    printf("%d\n", b);

    return EXIT_SUCCESS;
}