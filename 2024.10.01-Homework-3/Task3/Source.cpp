#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 437;
    scanf("%d", &a);

    for (int i = 0; i < a; ++i) {
        int m = 0;
        scanf("%d", &m);
        if (b >= m) {
            printf("Crash %d\n", i + 1);
            break;
        }
        else if (i + 1 == a) {
            printf("No crash \n");
        }
    }

    return EXIT_SUCCESS;
}