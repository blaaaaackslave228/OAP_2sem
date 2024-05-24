#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#define size 100

using namespace std;

void input();
void out();
void search();
void infile();
void onfile();

union ForBook
{
	char name[50];
	char surname[50];
	char dadname[50];
	char address[50];
	char number_phone[20];
	char place_work_or_study[10];
	char post[20];
};

struct Birthday
{
	string date_birthday;
};

struct Book
{
	ForBook yourself_name;
	ForBook last_name;
	ForBook dad_name;
	ForBook direction;
	ForBook phone;
	ForBook place;
	ForBook position;
	Birthday date;
};

Book list_of_book[size];
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
            cout << "���������� � " << i + 1 << " �������: " << endl;
            cout << "������� ���: ";
            cin.ignore();
            cin.getline(list_of_book[current_size].yourself_name.name, 40);
            cout << "������� �������: ";
            cin.getline(list_of_book[current_size].last_name.surname, 40);
            cout << "������� ��������: ";
            cin.getline(list_of_book[current_size].dad_name.dadname, 40);
            cout << "������� �����: ";
            cin.getline(list_of_book[current_size].direction.address, 40);
            cout << "������� ����� ��������: ";
            cin.getline(list_of_book[current_size].phone.number_phone, 15);
            cout << "������� ����� ������ ��� �����: ";
            cin.getline(list_of_book[current_size].place.place_work_or_study, 10);
            cout << "������� ���������: ";
            cin.getline(list_of_book[current_size].position.post, 20);
            cout << "������� ���� ��������: ";
            getline(cin, list_of_book[current_size].date.date_birthday);
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
        cout << "���������� � " << i + 1 << " �������: " << endl;
        cout << "���: ";
        cout << list_of_book[i].yourself_name.name << endl;
        cout << "�������: ";
        cout << list_of_book[i].last_name.surname << endl;
        cout << "��������: ";
        cout << list_of_book[i].dad_name.dadname << endl;
        cout << "�����: ";
        cout << list_of_book[i].direction.address << endl;
        cout << "����� ��������: ";
        cout << list_of_book[i].phone.number_phone << endl;
        cout << "����� ������ ��� �����: ";
        cout << list_of_book[i].place.place_work_or_study << endl;
        cout << "���������: ";
        cout << list_of_book[i].position.post << endl;
        cout << "���� ��������: ";
        cout << list_of_book[i].date.date_birthday << endl;
        cout << endl;
    }
}

void search()
{
    char lastname[50];
    cout << "������� �������: ";
    cin.ignore();
    cin.getline(lastname, 40);
    for (int i = 0; i < current_size; i++) {
        if (strcmp(lastname, list_of_book[i].last_name.surname) == 0) {
            cout << "���������� � " << i + 1 << " �������: " << endl;
            cout << "���: ";
            cout << list_of_book[i].yourself_name.name << endl;
            cout << "�������: ";
            cout << list_of_book[i].last_name.surname << endl;
            cout << "��������: ";
            cout << list_of_book[i].dad_name.dadname << endl;
            cout << "�����: ";
            cout << list_of_book[i].direction.address << endl;
            cout << "����� ��������: ";
            cout << list_of_book[i].phone.number_phone << endl;
            cout << "����� ������ ��� �����: ";
            cout << list_of_book[i].place.place_work_or_study << endl;
            cout << "���������: ";
            cout << list_of_book[i].position.post << endl;
            cout << "���� ��������: ";
            cout << list_of_book[i].date.date_birthday << endl;
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
    ofstream file1("D:/�����/2 ���/����/����/files/book.txt", ios::app);

    if (!file1) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
    }

    for (int i = 0; i < current_size; i++) {
        file1 << "���������� � " << i + 1 << " �������: " << endl;
        file1 << "���: ";
        file1 << list_of_book[i].yourself_name.name << endl;
        file1 << "�������: ";
        file1 << list_of_book[i].last_name.surname << endl;
        file1 << "��������: ";
        file1 << list_of_book[i].dad_name.dadname << endl;
        file1 << "�����: ";
        file1 << list_of_book[i].direction.address << endl;
        file1 << "����� ��������: ";
        file1 << list_of_book[i].phone.number_phone << endl;
        file1 << "����� ������ ��� �����: ";
        file1 << list_of_book[i].place.place_work_or_study << endl;
        file1 << "���������: ";
        file1 << list_of_book[i].position.post << endl;
        file1 << "���� ��������: ";
        file1 << list_of_book[i].date.date_birthday << endl;
    }

    file1.close();
    cout << "������ ������� ��������." << endl;
}

void onfile()
{
    ifstream file2("D:/�����/2 ���/����/����/files/book.txt");

    if (!file2) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
    }

    string line;
    while (getline(file2, line)) {
        cout << line << endl;
    }

    file2.close();
    cout << "������ ������� �������� �� �����." << endl;
}


