#include <iostream>
#include <cstdlib>

int* sozdatMassiv(int razmer) {
    int* rezultat = (int*)malloc(sizeof(int) * razmer);
    if (!rezultat) {
        std::cerr << "������ ��������� ������!" << std::endl;
        return 0;
    }
    return rezultat;
}

void printMassiv(int* massiv, int razmer) {
    for (int i = 0; i < razmer; ++i) {
        std::cout << massiv[i] << " ";
    }
    std::cout << std::endl;
}

void rasshiritMassiv(int** massiv, int* razmer) {
    int* noviyMassiv = (int*)malloc(sizeof(int) * (*razmer + 1));
    if (!noviyMassiv) {
        std::cerr << "������ ��������� ������!" << std::endl;
        return;
    }
    for (int i = 0; i < *razmer; ++i) {
        noviyMassiv[i + 1] = (*massiv)[i];
    }
    free(*massiv);
    *massiv = noviyMassiv;
    (*razmer)++;
}

void dobavitVKonets(int** massiv, int* razmer, int znachenie) {
    rasshiritMassiv(massiv, razmer);
    (*massiv)[*razmer - 1] = znachenie;
}

void dobavitVNachalo(int** massiv, int* razmer, int znachenie) {
    int* noviyMassiv = (int*)malloc(sizeof(int) * (*razmer + 1));
    if (!noviyMassiv) {
        std::cerr << "������ ��������� ������!" << std::endl;
        return;
    }
    noviyMassiv[0] = znachenie;
    for (int i = 0; i < *razmer; ++i) {
        noviyMassiv[i + 1] = (*massiv)[i];
    }
    free(*massiv);
    *massiv = noviyMassiv;
    (*razmer)++;
}

void udalitPosledniy(int** massiv, int* razmer) {
    if (*razmer > 0) {
        (*razmer)--;
        if (*razmer == 0) {
            free(*massiv);
            *massiv = 0;
        }
    }
    else {
        std::cout << "������: ������ ����." << std::endl;
    }
}

void udalitPerviy(int** massiv, int* razmer) {
    if (*razmer > 0) {
        for (int i = 0; i < *razmer - 1; ++i) {
            (*massiv)[i] = (*massiv)[i + 1];
        }
        (*razmer)--;
        if (*razmer == 0) {
            free(*massiv);
            *massiv = 0;
        }
    }
    else {
        std::cout << "������: ������ ����." << std::endl;
    }
}

int vvodChisla() {
    int znachenie;
    while (true) {
        std::cout << "������� �����: ";
        if (std::cin >> znachenie) {
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "������ �����! ����������, ������� ����� �����." << std::endl;
        }
    }
    return znachenie;
}

void printMenu() {
    std::cout << "\n����:\n";
    std::cout << "1 - ������ �������\n";
    std::cout << "2 - �������� ������� � ������\n";
    std::cout << "3 - �������� ������� � �����\n";
    std::cout << "4 - ������� ������� � ������\n";
    std::cout << "5 - ������� ������� � �����\n";
    std::cout << "0 - �����\n";
}

int main(int argc, char* argv[]) {
    int razmer;
    std::cout << "������� ���������� ��������� � �������: \n";
    razmer = vvodChisla();

    int* massiv = sozdatMassiv(razmer);

    std::cout << "������� �������� �������:" << std::endl;
    for (int i = 0; i < razmer; ++i) {
        massiv[i] = vvodChisla();
    }

    bool flag = true;
    while (flag) {
        printMenu();
        int vibor = vvodChisla();
        switch (vibor) {
        case 1:
            printMassiv(massiv, razmer);
            break;
        case 2: {
            int znachenie = vvodChisla();
            dobavitVNachalo(&massiv, &razmer, znachenie);
            break;
        }
        case 3: {
            int znachenie = vvodChisla();
            dobavitVKonets(&massiv, &razmer, znachenie);
            break;
        }
        case 4:
            udalitPerviy(&massiv, &razmer);
            break;
        case 5:
            udalitPosledniy(&massiv, &razmer);
            break;
        case 0:
            flag = false;
            break;
        default:
            std::cout << "�������� �����! ���������� �����." << std::endl;
        }
    }

    free(massiv);
    return 0;
}