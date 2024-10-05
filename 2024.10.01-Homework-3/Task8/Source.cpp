#include<iostream>

int gcd(int m, int n) {
    while (m && n) {
        if (m < n) {
            n %= m;
        }
        else {
            m %= n;
        }
    }
    return m + n;
}

int main(int argc, char* argv[])
{
int i = 0;
int j = 0;
int f0 = 0;
int f1 = 1;

scanf("%d %d", &i, &j);

for (i = gcd(i, j); i > 0; --i) {
    int f = (f0 + f1) % 1000000000;
    f0 = f1;
    f1 = f;
}
printf("%d\n", f0);

    return EXIT_SUCCESS;
}