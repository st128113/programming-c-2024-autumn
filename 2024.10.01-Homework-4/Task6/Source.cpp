#include<iostream>

int main(int argc, char* argv[])
{
    int c = 0;
    scanf("%d", &c);
    int d[100] = { 0 };
    int p[100] = { 0 };
    int q[100] = { 0 };

    for (int i = 0; i < c; ++i) {
        scanf("%d", &d[i]);
    }
    for (int i = 0; i < c; ++i) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < c; ++i) {
        q[i] = d[i] * p[i];
    }

    int m = 0;
    for (int i = 1; i < c; ++i) {
        if (q[i] > q[m]) {
            m = i;
        }
    }

    printf("%d\n", m + 1);

    return EXIT_SUCCESS;
}
