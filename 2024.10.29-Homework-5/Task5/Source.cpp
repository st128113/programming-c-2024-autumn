#include <iostream>


int main(int argc, char* argv[]) {
    int a = 0;
    std::cin >> a;

    int* b = (int*)malloc(a * sizeof(int));
    for (int c = 0; c < a; ++c) {
        std::cin >> *(b + c);
    }

    int d = 0;
    int e = 1;
    int f = -1;

    for (int g = 0; g < a; ++g) {
        int h = 0;
        int i = -1;

        for (int j = g; j < a; ++j) {
            if (*(b + j) > h) {
                h = *(b + j);
                i = j;
            }
        }

        if (i != -1) {
            d += h * (i - f);
            f = i;
        }
    }

    std::cout << d << std::endl;

    free(b);

    return 0;
}