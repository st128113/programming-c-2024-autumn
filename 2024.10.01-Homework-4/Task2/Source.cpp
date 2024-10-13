#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);
    int a[1000] = { 0 };

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    int b = 0;
    int c = 0;
    scanf("%d", &b);
    scanf("%d", &c);
    --b;
    --c;

    int q = -1001;
    int p = -1;

    for (int i = b; i <= c; ++i) {
        if (a[i] > q) {
            q = a[i];
            p = i;
        }
    }

    printf("%d ", q);
    printf("%d", p + 1);

    return EXIT_SUCCESS;
}
