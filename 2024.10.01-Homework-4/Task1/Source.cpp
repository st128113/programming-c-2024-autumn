#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);
    int a[1000] = { 0 };

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    int x = 0;
    scanf("%d", &x);

    int b = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            b++;
        }
    }
    printf("%d", b);


    return EXIT_SUCCESS;
}
