#include <iostream>
#include <string>
#include <Windows.h>
#define size 100

using namespace std;

void input();
void output();
void search();
void delete_info();

struct Date
{
	unsigned int day : 5;
	unsigned int month : 5;
	unsigned int year : 12;
};

struct Teachers
{
	string surname;
	string name_exams;
	Date date;
};

Teachers list_of_teachers[size];
int choice, current_size = 0, number_teachers, d;

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
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			search();
			break;
		case 4:
			delete_info();
			break;
		}
	} while (choice != 5);
}

void input()
{
	cout << endl;
	cout << "���� ����������: " << endl;
	cout << "������� ���������� ��������������: ";
	cin >> number_teachers;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_teachers; i++) {
			cout << "���������� � " << i + 1 << " �������������: " << endl;
			cout << "������� ������� �������������: ";
			cin.ignore();
			getline(cin, list_of_teachers[current_size].surname);
			cout << "������� �������� ��������: ";
			getline(cin, list_of_teachers[current_size].name_exams);
			cout << "������� ���� ��������: ";
			cin >> d;
			list_of_teachers[current_size].date.day = d;
			cout << "������� ����� ��������: ";
			cin >> d;
			list_of_teachers[current_size].date.month = d;
			cout << "������� ��� ��������: ";
			cin >> d;
			list_of_teachers[current_size].date.year = d;
			current_size++;
			cout << endl;
		}
	}
}

void output()
{
	cout << endl;
	cout << "����� ����������: ";
	for (int i = 0; i < current_size; i++) {
		cout << "���������� � " << i + 1 << " �������������: " << endl;
		cout << "������� �������������: ";
		cout << list_of_teachers[i].surname << endl;
		cout << "�������� ��������: ";
		cout << list_of_teachers[i].name_exams << endl;
		cout << "���� ��������: " << endl;
		cout << "���� ��������: " << list_of_teachers[i].date.day << endl;
		cout << "����� ��������: " << list_of_teachers[i].date.month << endl;
		cout << "��� ��������: " << list_of_teachers[i].date.year << endl;
		cout << endl;
	}
}

void search()
{
	int day_exam, month_exam, year_exam;
	cout << "������� ���� ��������: ";
	cin >> day_exam;
	cout << "������� ����� ��������: ";
	cin >> month_exam;
	cout << "������� ��� ��������: ";
	cin >> year_exam;
	for (int i = 0; i < current_size; i++) {
		if (day_exam == list_of_teachers[i].date.day && month_exam == list_of_teachers[i].date.month && year_exam == list_of_teachers[i].date.year) {
			cout << "���������� � " << i + 1 << " �������������: " << endl;
			cout << "������� �������������: ";
			cout << list_of_teachers[i].surname << endl;
			cout << "�������� ��������: ";
			cout << list_of_teachers[i].name_exams << endl;
			cout << "���� ��������: " << endl;
			cout << "���� ��������: " << list_of_teachers[i].date.day << endl;
			cout << "����� ��������: " << list_of_teachers[i].date.month << endl;
			cout << "��� ��������: " << list_of_teachers[i].date.year << endl;
			cout << endl;
		}
		else
		{
			cout << "���������� �� �������." << endl;
		}
	}
}

void delete_info()
{
	cout << endl;
	int NumberLine;
	cout << "������� ����� ������, ������� ������ �������: ";
	cin >> NumberLine;
	if (NumberLine > 0 && NumberLine <= current_size) {
		for (int del = NumberLine - 1; del < current_size - 1; del++) {
			list_of_teachers[del] = list_of_teachers[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "�������� ����� ������." << endl;
	}
}


