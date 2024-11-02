#include <iostream>

int main(int argc, char* argv[]) {
    int a = 0;
    std::cin >> a;

    int* c = (int*)malloc(a * sizeof(int));
    for (int d = 0; d < a; ++d) {
        std::cin >> *(c + d);
    }

    int* e = (int*)malloc(a * sizeof(int));
    int* q = (int*)malloc(a * sizeof(int));
    int o = 0;
    int p = 0;

    for (int d = 0; d < a; ++d) {
        if (*(c + d) % 2 == 0) {
            *(e + o) = *(c + d);
            o++;
        }
        else {
            *(q + p) = *(c + d);
            p++;
        }
    }

    for (int d = 0; d < p; ++d) {
        std::cout << *(q + d) << " ";
    }
    std::cout << std::endl;

    for (int d = 0; d < o; ++d) {
        std::cout << *(e + d) << " ";
    }
    std::cout << std::endl;

    if (o >= p) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

    free(c);
    free(q);
    free(e);

    return 0;
}
