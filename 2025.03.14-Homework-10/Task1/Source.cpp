#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdio>

using namespace std;

struct Student
{
    string name;
    int hp;
    int base_dmg;
    int luck;
    int strength;
    int stamina;
    int attack;
    int defense;
    int block;

    Student() : name(""), hp(0), base_dmg(0), luck(0), strength(0), stamina(0), attack(0), defense(0), block(0) {}

    Student(string name, int hp = 100, int dmg = 5, int luck = 10, int strength = 0, int stamina = 0, int attack = 0, int defense = 0, int block = 0) :
        name(name), hp(hp), base_dmg(dmg), luck(luck), strength(strength), stamina(stamina), attack(attack), defense(defense), block(block)
    {
    }

    bool luckWorks() const
    {
        return (rand() % 100 < luck);
    }

    bool isDead() const
    {
        return (hp < 1);
    }

    void getDmg(int damage)
    {
        int actualDamage = damage - defense;
        if (actualDamage < 0) actualDamage = 0;
        if (luckWorks())
        {
            cout << "\t" << name << " - �����! ���������� ���� ��������.\n";
            actualDamage /= 2;
        }
        hp -= actualDamage;
        if (hp < 0) hp = 0;
    }

    int makeDmg() const
    {
        int damage = base_dmg + strength + attack;
        if (luckWorks())
        {
            cout << "\t" << name << " - �����! ���������� ���� ��������.\n";
            return damage * 2;
        }
        else
        {
            return damage;
        }
    }

    void print() const
    {
        cout << name << " [HP: " << hp << "] (�����: " << luck << "; ����: " << base_dmg;
        cout << "; ����: " << strength << "; ������������: " << stamina;
        cout << "; �����: " << attack << "; ������: " << defense << "; ����: " << block << ")\n";
    }
};

void generateStudent(Student& student, int index) {
    char nameBuffer[20];
    sprintf(nameBuffer, "student %d", index);
    student.name = nameBuffer;
    student.hp = 80 + rand() % 41;
    student.base_dmg = 10 + rand() % 11;
    student.luck = 5 + rand() % 21;
    student.strength = rand() % 11;
    student.stamina = rand() % 11;
    student.attack = rand() % 11;
    student.defense = rand() % 11;
    student.block = rand() % 11;
    student.hp += student.stamina * 5;
}

Student battle(Student student1, Student student2) {
    cout << "����� �����:\n";
    student1.print();
    cout << "������\n";
    student2.print();

    while (!student1.isDead() && !student2.isDead()) {
        student1.getDmg(student2.makeDmg());
        cout << "\t" << student2.name << " �������. � " << student1.name << " �������� " << student1.hp << " HP.\n";
        if (student1.isDead()) break;

        student2.getDmg(student1.makeDmg());
        cout << "\t" << student1.name << " �������. � " << student2.name << " �������� " << student2.hp << " HP.\n";
    }

    if (student1.isDead() && student2.isDead()) {
        cout << "�����!\n";
        return Student("�����", 0, 0, 0);
    }
    else if (student1.isDead()) {
        cout << student2.name << " ���������!\n";
        return student2;
    }
    else {
        cout << student1.name << " ���������!\n";
        return student1;
    }
}

void runRound(Student* participants, int numParticipants, Student* nextRoundParticipants, int& nextRoundCount) {
    cout << "\n--- ������ ������ (" << numParticipants << " ����������) ---\n";
    nextRoundCount = 0;
    for (int i = 0; i < numParticipants; i += 2) {
        if (i + 1 < numParticipants) {
            Student winner = battle(participants[i], participants[i + 1]);
            if (winner.name != "�����") {
                nextRoundParticipants[nextRoundCount++] = winner;
            }
        }
        else {
            nextRoundParticipants[nextRoundCount++] = participants[i];
            cout << participants[i].name << " �������� � ��������� ����� ��� ���.\n";
        }
    }
    cout << "--- ����� ��������. � ��������� ����� ����� " << nextRoundCount << " ���������� ---\n";
}

void tournament() {
    cout << "--- ������ ������� �� 1000 ���������� ---\n";
    const int NUM_PARTICIPANTS = 1000;
    Student* participants = new Student[NUM_PARTICIPANTS];
    for (int i = 0; i < NUM_PARTICIPANTS; ++i) {
        generateStudent(participants[i], i + 1);
        cout << "�������� " << i + 1 << ": ";
        participants[i].print();
    }

    Student* currentRoundParticipants = participants;
    int currentRoundCount = NUM_PARTICIPANTS;
    Student* nextRoundParticipants = new Student[NUM_PARTICIPANTS];
    int nextRoundCountVal = 0;
    int roundNumber = 1;

    while (currentRoundCount > 1) {
        cout << "\n===== ����� " << roundNumber++ << " =====\n";
        runRound(currentRoundParticipants, currentRoundCount, nextRoundParticipants, nextRoundCountVal);

        Student* temp = currentRoundParticipants;
        currentRoundParticipants = nextRoundParticipants;
        nextRoundParticipants = temp;
        currentRoundCount = nextRoundCountVal;
    }

    if (currentRoundCount == 1) {
        cout << "\n***** ���������� �������: *****\n";
        currentRoundParticipants[0].print();
    }
    else {
        cout << "\n������ ���������� ��� ���������� (��������, ��� ��� ����������� ������)." << endl;
    }

    delete[] participants;
    delete[] nextRoundParticipants;
}

int main() {
    srand(time(0));
    tournament();
    return 0;
}