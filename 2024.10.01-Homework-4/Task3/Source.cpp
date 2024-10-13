#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);
    int a[1000] = { 0 };

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    if (n == 0) {
        return EXIT_SUCCESS;
    }
    
    int q = a[0];
    int p = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i] > q) {
            q = a[i];
        }
        if (a[i] < p) {
            p = a[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == q) {
            a[i] = p;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

    return EXIT_SUCCESS;
}
