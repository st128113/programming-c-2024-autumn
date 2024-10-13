#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);
    int a[1000] = { 0 };

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int m = 0;
    scanf("%d", &m);

    for (int k = 0; k < m; ++k) {
        int ik = 0;
        int jk = 0;
        scanf("%d", &ik);
        scanf("%d", &jk);

        for (int i = ik - 1; i < jk; ++i) {
            printf("%d ", a[i]);
        }
    }

    return EXIT_SUCCESS;
}
