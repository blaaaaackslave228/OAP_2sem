#include <iostream>
#include <Windows.h>
#include <string>
#define size 100

using namespace std;

void InputInfo();
void OutputInfo();
void DeleteInfo();
void SearchInfo();

struct Date
{
	unsigned int day : 5;
	unsigned int month : 5;
	unsigned int year : 12;
};

struct book
{
	Date date;
	string last_name;
	string name;
	string dadname;
	string address;
	string number_phone;
};

book list_of_book[size];
int choice, current_size = 0, number_persons, d;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	do {
		cout << "�������� ��������: " << endl;
		cout << "1 - ���� ������." << endl;
		cout << "2 - ����� ������." << endl;
		cout << "3 - ����� ����������." << endl;
		cout << "4 - �������� ����������." << endl;
		cout << "5 - ��x��." << endl;
		cout << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			InputInfo();
			break;
		case 2:
			OutputInfo();
			break;
		case 3:
			SearchInfo();
			break;
		case 4:
			DeleteInfo();
			break;
		}
	} while (choice != 5);
}

void InputInfo()
{
	cout << endl;
	cout << "���� ����������: " << endl;
	cout << "������� ���������� ������: ";
	cin >> number_persons;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_persons; i++) {
			cout << "���������� � " << i + 1 << " �������: " << endl;
			cout << "������� ���: ";
			cin.ignore();
			getline(cin, list_of_book[current_size].name);
			cout << "������� �������: ";
			getline(cin, list_of_book[current_size].last_name);
			cout << "������� ��������: ";
			getline(cin, list_of_book[current_size].dadname);
			cout << "������� �����: ";
			getline(cin, list_of_book[current_size].address);
			cout << "������� ��������� �������: ";
			getline(cin, list_of_book[current_size].number_phone);
			cout << "������� ���� ��������: ";
			cin >> d;
			list_of_book[current_size].date.day = d;
			cout << "������� ����� ��������: ";
			cin >> d;
			list_of_book[current_size].date.month = d;
			cout << "������� ��� ��������: ";
			cin >> d;
			list_of_book[current_size].date.year = d;
			current_size++;
			cout << endl;
		}
	}
}

void OutputInfo()
{
	cout << endl;
	cout << "����� ����������: " << endl;
	for (int i = 0; i < current_size; i++) {
		cout << "���������� � " << i + 1 << " �������: " << endl;
		cout << "���: ";
		cout << list_of_book[i].name << endl;
		cout << "�������: ";
		cout << list_of_book[i].last_name << endl;
		cout << "��������: ";
		cout << list_of_book[i].dadname << endl;
		cout << "�����: ";
		cout << list_of_book[i].address << endl;
		cout << "��������� �������: ";
		cout << list_of_book[i].number_phone << endl;
		cout << "���� ��������: " << endl;
		cout << "����: " << list_of_book[i].date.day << endl;
		cout << "�����: " << list_of_book[i].date.month << endl;
		cout << "���: " << list_of_book[i].date.year << endl;
		cout << endl;
	}
}

void DeleteInfo()
{
	cout << endl;
	int NumberLine;
	cout << "������� ����� ������, ������� ������ �������: ";
	cin >> NumberLine;
	if (NumberLine > 0 && NumberLine <= current_size) {
		for (int del = NumberLine - 1; del < current_size - 1; del++) {
			list_of_book[del] = list_of_book[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "�������� ����� ������." << endl;
	}
}

void SearchInfo()
{
	string surname;
	cout << "������� �������: ";
	cin.ignore();
	getline(cin, surname);
	for (int i = 0; i < current_size; i++) {
		if (surname == list_of_book[i].last_name) {
			cout << "���������� � " << i + 1 << " �������: " << endl;
			cout << "���: ";
			cout << list_of_book[i].name << endl;
			cout << "�������: ";
			cout << list_of_book[i].last_name << endl;
			cout << "��������: ";
			cout << list_of_book[i].dadname << endl;
			cout << "�����: ";
			cout << list_of_book[i].address << endl;
			cout << "��������� �������: ";
			cout << list_of_book[i].number_phone << endl;
			cout << "���� ��������: " << endl;
			cout << "����: " << list_of_book[i].date.day << endl;
			cout << "�����: " << list_of_book[i].date.month << endl;
			cout << "���: " << list_of_book[i].date.year << endl;
			cout << endl;
		}
	}
}
