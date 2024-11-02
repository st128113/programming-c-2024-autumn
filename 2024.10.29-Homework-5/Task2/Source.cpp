#include <iostream>

int main(int argc, char* argv[]) {
    int a = 0;
    int b = 0;
    std::cin >> a;

    int* c = (int*)malloc(a * sizeof(int));
    for (int d = 0; d < a; ++d) {
        std::cin >> *(c + d);
    }

    std::cin >> b;
    b = ((b % a) + a) % a;

    int* e = (int*)malloc(a * sizeof(int));

    for (int d = 0; d < a; ++d) {
        *(e + ((d + b) % a)) = *(c + d);
    }

    for (int d = 0; d < a; ++d) {
        std::cout << *(e + d) << " ";
    }

    free(c);
    free(e);

    return 0;
}
