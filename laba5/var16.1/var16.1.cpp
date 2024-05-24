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
		cout << "Выберите операцию: " << endl;
		cout << "1 - Ввод данных." << endl;
		cout << "2 - Вывод данных." << endl;
		cout << "3 - Поиск информации." << endl;
		cout << "4 - Удаление информации." << endl;
		cout << "5 - Выxод." << endl;
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
	cout << "Ввод информации: " << endl;
	cout << "Введите количество преподавателей: ";
	cin >> number_teachers;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_teachers; i++) {
			cout << "Информация о " << i + 1 << " преподавателе: " << endl;
			cout << "Введите фамилию преподавателя: ";
			cin.ignore();
			getline(cin, list_of_teachers[current_size].surname);
			cout << "Введите название экзамена: ";
			getline(cin, list_of_teachers[current_size].name_exams);
			cout << "Введите день экзамена: ";
			cin >> d;
			list_of_teachers[current_size].date.day = d;
			cout << "Введите месяц экзамена: ";
			cin >> d;
			list_of_teachers[current_size].date.month = d;
			cout << "Введите год экзамена: ";
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
	cout << "Вывод информации: ";
	for (int i = 0; i < current_size; i++) {
		cout << "Информация о " << i + 1 << " преподавателе: " << endl;
		cout << "Фамилия преподавателя: ";
		cout << list_of_teachers[i].surname << endl;
		cout << "Название экзамена: ";
		cout << list_of_teachers[i].name_exams << endl;
		cout << "Дата экзамена: " << endl;
		cout << "День экзамена: " << list_of_teachers[i].date.day << endl;
		cout << "Месяц экзамена: " << list_of_teachers[i].date.month << endl;
		cout << "Год экзамена: " << list_of_teachers[i].date.year << endl;
		cout << endl;
	}
}

void search()
{
	int day_exam, month_exam, year_exam;
	cout << "Введите день экзамена: ";
	cin >> day_exam;
	cout << "Введите месяц экзамена: ";
	cin >> month_exam;
	cout << "Введите год экзамена: ";
	cin >> year_exam;
	for (int i = 0; i < current_size; i++) {
		if (day_exam == list_of_teachers[i].date.day && month_exam == list_of_teachers[i].date.month && year_exam == list_of_teachers[i].date.year) {
			cout << "Информация о " << i + 1 << " преподавателе: " << endl;
			cout << "Фамилия преподавателя: ";
			cout << list_of_teachers[i].surname << endl;
			cout << "Название экзамена: ";
			cout << list_of_teachers[i].name_exams << endl;
			cout << "Дата экзамена: " << endl;
			cout << "День экзамена: " << list_of_teachers[i].date.day << endl;
			cout << "Месяц экзамена: " << list_of_teachers[i].date.month << endl;
			cout << "Год экзамена: " << list_of_teachers[i].date.year << endl;
			cout << endl;
		}
		else
		{
			cout << "Информация не найдена." << endl;
		}
	}
}

void delete_info()
{
	cout << endl;
	int NumberLine;
	cout << "Введите номер строки, которую хотите удалить: ";
	cin >> NumberLine;
	if (NumberLine > 0 && NumberLine <= current_size) {
		for (int del = NumberLine - 1; del < current_size - 1; del++) {
			list_of_teachers[del] = list_of_teachers[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "Неверный номер строки." << endl;
	}
}


