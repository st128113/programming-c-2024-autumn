#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);
    int a[100] = { 0 };

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    int p = 0;
    scanf("%d", &p);
    int q = n + 1;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= p) {
            q = i + 2;
        } else {
        break;
        }
    }
    
    printf("%d", q);

    return EXIT_SUCCESS;
}
