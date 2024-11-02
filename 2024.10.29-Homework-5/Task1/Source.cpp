#include <iostream>

int main(int argc, char* argv[]) {
    int n = 0;
    std::cin >> n;

    if (n <= 0) return 0;

    int* p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        std::cin >> *(p + i);
    }

    int* doubled = (int*)malloc(2 * n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(doubled + i) = *(p + i);
        *(doubled + i + n) = *(p + i);
    }

    int* f = (int*)malloc(2 * n * sizeof(int));
    for (int i = 0; i < 2 * n; ++i) {
        *(f + i) = -1;
    }

    int h = 0;
    for (int i = 1; i < 2 * n; ++i) {
        int j = *(doubled + i);
        int k = *(f + i - h - 1);

        while (k != -1 && j != *(doubled + h + k + 1)) {
            if (j < *(doubled + h + k + 1)) {
                h = i - k - 1;
            }
            k = *(f + k);
        }

        if (j != *(doubled + h + k + 1)) {
            if (j < *(doubled + h)) {
                h = i;
            }
            *(f + i - h) = -1;
        }
        else {
            *(f + i - h) = k + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << *(p + ((h + i) % n)) << " ";
    }

    std::cout << std::endl;

    free(p);
    free(doubled);
    free(f);

    return 0;
}
