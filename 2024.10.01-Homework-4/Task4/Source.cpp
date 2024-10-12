#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    int b[1000];
    int m = 0;
    scanf("%d", &n);    
    
    for (int c = 0; c < n; ++c) {
        scanf("%d", &b[c]);
    }

    for (int k = 0; k < n; ++k) {
        int s = b[k] + b[(k + 1) % n] + b[(k + 2) % n];
        if (s > m) {
            m = s;
        }
    }

    printf("%d", m);

    return EXIT_SUCCESS;
}