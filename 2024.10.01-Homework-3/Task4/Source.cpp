#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = -1;
    scanf("%d", &a);
    
    for (int i = 1; i <= a; i++) {
        int e = 0;
        int h = 0;
        scanf("%d", &e);
        scanf("%d", &h);
        if (h == 1 && e > b) {
            b = e;
            c = i;
        }
    }
    printf("%d", c);

    return EXIT_SUCCESS;
}