#include <iostream>

int main(int argc, char* argv[]) {
    int a = 0;
    std::cin >> a;

    int* b = (int*)malloc(a * sizeof(int));
    for (int c = 0; c < a; ++c) {
        std::cin >> *(b + c);
    }


    int d = 0;
    int e = 0;
    int f = 0;

    for (int c = 0; c < a; ++c) {
        if (*(b + c) > 0) {
            d += *(b + c);
        }
        if (*(b + c) < *(b + e)) {
            e = c;
        }
        if (*(b + c) > *(b + f)) {
            f = c;
        }
    }

    if (e > f) {
        std::swap(e, f);
    }


    int g = 1;
    for (int c = e + 1; c < f; ++c) {
        g *= *(b + c);
    }

    std::cout << d << " " << g << std::endl;

    free(b);

    return 0;
}
