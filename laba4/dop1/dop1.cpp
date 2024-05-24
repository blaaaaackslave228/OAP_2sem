#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void AboutStudents(int NumberStudents);
void CharacteristicExams(int NumberStudents);

struct Student {
    string name;
    int num_exams = 4;
    int marks[5];
};

Student* list_of_exams;

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    cout << "����� ���������: " << endl;
    int NumberStudents;
    cout << "������� ���������� ���������: ";
    cin >> NumberStudents;
    list_of_exams = new Student[NumberStudents];
    AboutStudents(NumberStudents);
    CharacteristicExams(NumberStudents);
    delete[] list_of_exams;
    return 0;
}

void AboutStudents(int NumberStudents)
{
    for (int i = 0; i < NumberStudents; i++) {
        cout << "������� ��� " << i + 1 << " ��������: ";
        cin.ignore();
        getline(cin, list_of_exams[i].name);
        for (int j = 0; j < list_of_exams[i].num_exams; j++) {
            cout << "������� ������ " << j + 1 << " ��� �������� " << list_of_exams[i].name << ": ";
            cin >> list_of_exams[i].marks[j];
        }
    }
}

void CharacteristicExams(int NumberStudents)
{
    int ExcellentStudent = 0;
    for (int i = 0; i < NumberStudents; i++) {
        int count = 0;
        for (int j = 0; j < list_of_exams[i].num_exams; j++) {
            if (list_of_exams[i].marks[j] < 4) {
                count++;
            }
        }
        if (count == 0) {
            ExcellentStudent++;
        }
    }
    double percent = ((double)ExcellentStudent / NumberStudents) * 100;
    cout << "�����������: " << percent;
}
