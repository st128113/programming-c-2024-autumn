#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    int c = 0;
    int d = 0;
    scanf("%d", &c);
    scanf("%d", &d);
    if (abs(a - c) == abs(b - d) || a == c || b == d) {
        printf("YES");
    }
    else {
        printf("NO");
    }


    return EXIT_SUCCESS;
}