#include<iostream>

int main(int argc, char* argv[])
{
    int k = 0;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        int n = 0;
        int m = 0;
        scanf("%d", &n);
        scanf("%d", &m);
        int d = 19 * m + ((n + 239) * (n + 366)) / 2;
        printf("%d\n", d);
    }

    return EXIT_SUCCESS;
}