#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

#define size 300

using namespace std;

void input();
void out();
void search();
void infile();
void onfile();

union Person
{
	int year_birthday;
	char address_and_gender_and_name[200];
};

struct ForPerson
{
	Person name;
	Person birthday;
	Person point;
	Person gender_person;
};

ForPerson list_of_person[size];
int choice, current_size = 0, number_persons;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    do {
        cout << "�������� ��������:" << endl;
        cout << "1 - ���� ����������." << endl;
        cout << "2 - ����� ����������." << endl;
        cout << "3 - ����� ����������." << endl;
        cout << "4 - ������ � ����." << endl;
        cout << "5 - ������ �� �����." << endl;
        cout << "6 - �����." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            out();
            break;
        case 3:
            search();
            break;
        case 4:
            infile();
            break;
        case 5:
            onfile();
            break;
        }
    } while (choice != 6);
}

void input()
{
    cout << endl;
    cout << "���� ����������: " << endl;
    cout << "������� ���������� �������: ";
    cin >> number_persons;
    cout << endl;
    if (current_size < size) {
        for (int i = 0; i < number_persons; i++) {
            cout << "������� ���������� ��� " << i + 1 << " ����������: " << endl;
            cout << "������� ��� ����������: ";
            cin.ignore();
            cin.getline(list_of_person[current_size].name.address_and_gender_and_name, 190);
            cout << "������� ����� ����������: ";
            cin.getline(list_of_person[current_size].point.address_and_gender_and_name, 190);
            cout << "������� ��� ���������� (�/�): ";
            cin.getline(list_of_person[current_size].gender_person.address_and_gender_and_name, 190);
            cout << "������� ��� �������� ����������: ";
            cin >> list_of_person[current_size].birthday.year_birthday;
            current_size++;
            cout << endl;
        }
    }
}

void out()
{
    cout << endl;
    cout << "����� ����������: " << endl;
    for (int i = 0; i < current_size; i++) {
        cout << "���������� � " << i + 1 << " ����������: " << endl;
        cout << "��� ����������: ";
        cout << list_of_person[i].name.address_and_gender_and_name << endl;
        cout << "����� ����������: ";
        cout << list_of_person[i].point.address_and_gender_and_name << endl;
        cout << "��� ���������� (�/�): ";
        cout << list_of_person[i].gender_person.address_and_gender_and_name << endl;
        cout << "��� �������� ����������: ";
        cout << list_of_person[i].birthday.year_birthday;
        cout << endl;
    }
}

void search()
{
    int year;
    cout << "������� ��� �������� ����������: ";
    cin >> year;
    for (int i = 0; i < current_size; i++) {
        if (year == list_of_person[i].birthday.year_birthday) {
            cout << "���������� � " << i + 1 << " ����������: " << endl;
            cout << "��� ����������: ";
            cout << list_of_person[i].name.address_and_gender_and_name << endl;
            cout << "����� ����������: ";
            cout << list_of_person[i].point.address_and_gender_and_name << endl;
            cout << "��� ���������� (�/�): ";
            cout << list_of_person[i].gender_person.address_and_gender_and_name << endl;
            cout << "��� �������� ����������: ";
            cout << list_of_person[i].birthday.year_birthday;
            cout << endl;
        }
        else {
            cout << "���������� �� �������." << endl;
        }
    }
}

void infile()
{
    ofstream file1("D:/�����/2 ���/����/����/files/person.txt", ios::app);
    if (!file1) {
        cout << "�� ������� ������� ����." << endl;
    }

    for (int i = 0; i < current_size; i++) {
        file1 << "���������� � " << i + 1 << " ����������: " << endl;
        file1 << "��� ����������: " << list_of_person[i].name.address_and_gender_and_name << endl;
        file1 << "����� ����������: " << list_of_person[i].point.address_and_gender_and_name << endl;
        file1 << "��� ���������� (�/�): " << list_of_person[i].gender_person.address_and_gender_and_name << endl;
        file1 << "��� �������� ����������: " << list_of_person[i].birthday.year_birthday;
    }

    file1.close();
    cout << "������ ������� ��������." << endl;
}

void onfile()
{
    ifstream file2("D:/�����/2 ���/����/����/files/person.txt");
    if (!file2) {
        cout << "�� ������� ������� ����." << endl;
    }

    string line;
    while (getline(file2, line)) {
        cout << line << endl;
    }
    file2.close();
    cout << "������ ������� �������� �� �����." << endl;
}


