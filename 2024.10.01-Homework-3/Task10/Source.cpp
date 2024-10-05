#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf("%d", &n);
    int c = 0;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        scanf("%d", &x);
        if (x > 0) {
            ++c;
            if (c > m) {
                m = c;
            }
        }
        else {
            c = 0;
        }
    }
    printf("%d", m);

    return EXIT_SUCCESS;
}