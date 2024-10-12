#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    int q[1000];

    for (int i = 0; i < n; ++i) {
        q[i] = i + 1;
    }
    for (int i = a - 1, j = b - 1; i < j; ++i, --j) {
        int t = q[i];
        q[i] = q[j];
        q[j] = t;
    }
    for (int i = c - 1, j = d - 1; i < j; ++i, --j) {
        int t = q[i];
        q[i] = q[j];
        q[j] = t;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", q[i]);
    }

    return EXIT_SUCCESS;
}