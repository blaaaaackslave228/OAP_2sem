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
	cout << "Ввод информации: " << endl;
	cout << "Введите количество персон: ";
	cin >> number_persons;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_persons; i++) {
			cout << "Информация о " << i + 1 << " персоне: " << endl;
			cout << "Введите имя: ";
			cin.ignore();
			getline(cin, list_of_book[current_size].name);
			cout << "Введите фамилию: ";
			getline(cin, list_of_book[current_size].last_name);
			cout << "Введите отчество: ";
			getline(cin, list_of_book[current_size].dadname);
			cout << "Введите адрес: ";
			getline(cin, list_of_book[current_size].address);
			cout << "Введите мобильный телефон: ";
			getline(cin, list_of_book[current_size].number_phone);
			cout << "Введите день рождения: ";
			cin >> d;
			list_of_book[current_size].date.day = d;
			cout << "Введите месяц рождения: ";
			cin >> d;
			list_of_book[current_size].date.month = d;
			cout << "Введите год рождения: ";
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
	cout << "Вывод информации: " << endl;
	for (int i = 0; i < current_size; i++) {
		cout << "Информация о " << i + 1 << " персоне: " << endl;
		cout << "Имя: ";
		cout << list_of_book[i].name << endl;
		cout << "Фамилия: ";
		cout << list_of_book[i].last_name << endl;
		cout << "Отчество: ";
		cout << list_of_book[i].dadname << endl;
		cout << "Адрес: ";
		cout << list_of_book[i].address << endl;
		cout << "Мобильный телефон: ";
		cout << list_of_book[i].number_phone << endl;
		cout << "Дата рождения: " << endl;
		cout << "День: " << list_of_book[i].date.day << endl;
		cout << "Месяц: " << list_of_book[i].date.month << endl;
		cout << "Год: " << list_of_book[i].date.year << endl;
		cout << endl;
	}
}

void DeleteInfo()
{
	cout << endl;
	int NumberLine;
	cout << "Введите номер строки, которую хотите удалить: ";
	cin >> NumberLine;
	if (NumberLine > 0 && NumberLine <= current_size) {
		for (int del = NumberLine - 1; del < current_size - 1; del++) {
			list_of_book[del] = list_of_book[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "Неверный номер строки." << endl;
	}
}

void SearchInfo()
{
	string surname;
	cout << "Введите фамилию: ";
	cin.ignore();
	getline(cin, surname);
	for (int i = 0; i < current_size; i++) {
		if (surname == list_of_book[i].last_name) {
			cout << "Информация о " << i + 1 << " персоне: " << endl;
			cout << "Имя: ";
			cout << list_of_book[i].name << endl;
			cout << "Фамилия: ";
			cout << list_of_book[i].last_name << endl;
			cout << "Отчество: ";
			cout << list_of_book[i].dadname << endl;
			cout << "Адрес: ";
			cout << list_of_book[i].address << endl;
			cout << "Мобильный телефон: ";
			cout << list_of_book[i].number_phone << endl;
			cout << "Дата рождения: " << endl;
			cout << "День: " << list_of_book[i].date.day << endl;
			cout << "Месяц: " << list_of_book[i].date.month << endl;
			cout << "Год: " << list_of_book[i].date.year << endl;
			cout << endl;
		}
	}
}
