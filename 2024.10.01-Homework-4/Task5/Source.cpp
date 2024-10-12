#include<iostream>

int main(int argc, char* argv[])
{
    int c = 0;
    scanf("%d", &c);
    int a[1000];
    
    for (int i = 0; i < c; ++i) {
        scanf("%d", &a[i]);
    }

    int f;
    scanf("%d", &f);
    int g = a[0];
    int h = a[0] - f;

    if (h < 0) {
        h = -h;
    }

    for (int i = 1; i < c; ++i) {
        int e = a[i] - f;
        if (e < 0) e = -e;

        if (e < h || (e == h && a[i] < g)) {
            g = a[i];
            h = e;
        }
    }

    printf("%d", g);

    return EXIT_SUCCESS;
}