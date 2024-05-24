#include <iostream>
#include <string>
#include <Windows.h>
#define size 50

using namespace std;

void InputInfo();
void OutputInfo();
void DeleteInfo();
void SearchInfo();
void FormsGovernment();

enum Forms
{
	Monarchy,
	Republic
};

struct Store
{
	string name_country;
	string name_center;
	double quantity_people;
	double square_country;
	Forms government;
};

Store list_of_countries[size];
int choice, current_size = 0, number_countries;
Forms selected_form = Monarchy;

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
		cout << "5 - Работа с формами правления." << endl;
		cout << "6 - Выxод." << endl;
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
		case 5:
			FormsGovernment();
			break;
		}
	} while (choice != 6);
}

void InputInfo()
{
	cout << endl;
	cout << "Ввод информации: " << endl;
	cout << "Введите количество стран: ";
	cin >> number_countries;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_countries; i++) {
			cout << "Введите информацию для " << i + 1 << " страны: " << endl;
			cout << "Введите название страны: ";
			cin.ignore();
			getline(cin, list_of_countries[current_size].name_country);
			cout << "Введите столицу страны: ";
			getline(cin, list_of_countries[current_size].name_center);
			cout << "Введите население страны: ";
			cin >> list_of_countries[current_size].quantity_people;
			cout << "Введите площадь страны: ";
			cin >> list_of_countries[current_size].square_country;
			cout << "Выберите форму правления для государства (0 - Монархия, 1 - Республика): ";
			int form;
			cin >> form;
			list_of_countries[current_size].government = static_cast<Forms>(form);
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
		cout << "Информация о " << i + 1 << " стране: " << endl;
		cout << "Название страны: ";
		cout << list_of_countries[i].name_country << endl;
		cout << "Столица страны: ";
		cout << list_of_countries[i].name_center << endl;
		cout << "Население страны: ";
		cout << list_of_countries[i].quantity_people << endl;
		cout << "Площадь страны: ";
		cout << list_of_countries[i].square_country << endl;
		cout << "Форма правления: ";
		if (list_of_countries[i].government == Monarchy) {
			cout << "Монархия" << endl;
		}
		else
		{
			cout << "Республика" << endl;
		}
		cout << endl;
	}
}

void SearchInfo()
{
	cout << endl;
	string capital;
	cout << "Введите столицу государства: ";
	cin.ignore();
	getline(cin, capital);
	for (int i = 0; i < current_size; i++) {
		if (capital == list_of_countries[i].name_center) {
			cout << "Информация о " << i + 1 << " стране: " << endl;
			cout << "Название страны: ";
			cout << list_of_countries[i].name_country << endl;
			cout << "Столица страны: ";
			cout << list_of_countries[i].name_center << endl;
			cout << "Население страны: ";
			cout << list_of_countries[i].quantity_people << endl;
			cout << "Площадь страны: ";
			cout << list_of_countries[i].square_country << endl;
			cout << "Форма правления: ";
			if (list_of_countries[i].government == Monarchy) {
				cout << "Монархия" << endl;
			}
			else
			{
				cout << "Республика" << endl;
			}
		}
		else {
			cout << "Ничего не найдено." << endl;
		}
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
			list_of_countries[del] = list_of_countries[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "Неверный номер строки." << endl;
	}
}

void FormsGovernment()
{
	cout << "Выберите новую форму правления (0 - Монархия, 1 - Республика): ";
	int form;
	cin >> form;
	selected_form = static_cast<Forms>(form);
}