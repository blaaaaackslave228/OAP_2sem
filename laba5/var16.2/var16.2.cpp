#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#define size 200

using namespace std;

void input();
void output();
void search();
void infile();
void fromfile();

union ForStudents
{
	char full_name[100];
	char speciality[50];
	int group;
	char faculty[10];
	double middle_point;
};

struct Date
{
	string date;
};

struct Students
{
	ForStudents fio;
	ForStudents profession;
	ForStudents team;
	ForStudents department;
	ForStudents point;
	Date date_of_receipt;
};

Students list_of_students[size];
int choice, current_size = 0, number_students;

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
            output();
            break;
        case 3:
            search();
            break;
        case 4:
            infile();
            break;
        case 5:
            fromfile();
            break;
        }
    } while (choice != 6);
}

void input()
{
    cout << endl;
    cout << "���� ����������: " << endl;
    cout << "������� ���������� ���������: ";
    cin >> number_students;
    cout << endl;
    if (current_size < size) {
        for (int i = 0; i < number_students; i++) {
            cout << "���������� � " << i + 1 << " ��������: " << endl;
            cout << "������� ��� ��������: ";
            cin.ignore();
            cin.getline(list_of_students[current_size].fio.full_name, 95);
            cout << "������� ���� �����������: ";
            getline(cin, list_of_students[current_size].date_of_receipt.date);
            cout << "������� �������������: ";
            cin.getline(list_of_students[current_size].profession.speciality, 45);
            cout << "������� ���������: ";
            cin.getline(list_of_students[current_size].department.faculty, 10);
            cout << "������� ������: ";
            cin >> list_of_students[current_size].team.group;
            cout << "������� ������� ����: ";
            cin >> list_of_students[current_size].point.middle_point;
            current_size++;
            cout << endl;
        }
    }
}

void output()
{
    cout << endl;
    cout << "����� ����������: " << endl;
    for (int i = 0; i < current_size; i++) {
        cout << "���������� � " << i + 1 << " ��������: " << endl;
        cout << "��� ��������: ";
        cout << list_of_students[i].fio.full_name << endl;
        cout << "���� �����������: ";
        cout << list_of_students[i].date_of_receipt.date << endl;
        cout << "�������������: ";
        cout << list_of_students[i].profession.speciality << endl;
        cout << "���������: ";
        cout << list_of_students[i].department.faculty << endl;
        cout << "������: ";
        cout << list_of_students[i].team.group << endl;
        cout << "������� ����: ";
        cout << list_of_students[i].point.middle_point << endl;
        cout << endl;
    }
}

void search()
{
    double mid_point;
    cout << "������� ������� ����: ";
    cin >> mid_point;
    for (int i = 0; i < current_size; i++) {
        if (mid_point == list_of_students[i].point.middle_point) {
            cout << "���������� � " << i + 1 << " ��������: " << endl;
            cout << "��� ��������: ";
            cout << list_of_students[i].fio.full_name << endl;
            cout << "���� �����������: ";
            cout << list_of_students[i].date_of_receipt.date << endl;
            cout << "�������������: ";
            cout << list_of_students[i].profession.speciality << endl;
            cout << "���������: ";
            cout << list_of_students[i].department.faculty << endl;
            cout << "������: ";
            cout << list_of_students[i].team.group << endl;
            cout << "������� ����: ";
            cout << list_of_students[i].point.middle_point << endl;
            cout << endl;
        }
        else
        {
            cout << "���������� �� �������." << endl;
        }
    }
}

void infile()
{
    ofstream file1("D:/�����/2 ���/����/����/files/students.txt", ios::app);
    
    if (!file1) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
    }

    for (int i = 0; i < current_size; i++) {
        file1 << "���������� � " << i + 1 << " ��������: " << endl;
        file1 << "��� ��������: ";
        file1 << list_of_students[i].fio.full_name << endl;
        file1 << "���� �����������: ";
        file1 << list_of_students[i].date_of_receipt.date << endl;
        file1 << "�������������: ";
        file1 << list_of_students[i].profession.speciality << endl;
        file1 << "���������: ";
        file1 << list_of_students[i].department.faculty << endl;
        file1 << "������: ";
        file1 << list_of_students[i].team.group << endl;
        file1 << "������� ����: ";
        file1 << list_of_students[i].point.middle_point << endl;
    }

    file1.close();
    cout << "������ ������� �������� � ����." << endl;
}

void fromfile()
{
    ifstream file2("D:/�����/2 ���/����/����/files/students.txt");

    if (!file2) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
    }

    string line;
    while (getline(file2, line)) {
        cout << line << endl;
    }

    file2.close();
    cout << "������ �� ����� ������� ��������." << endl;
}
