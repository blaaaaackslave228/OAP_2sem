#include <iostream>
#include <string>
#include <Windows.h>
#define size 50

using namespace std;

void InputInfo();
void OutputInfo();
void DeleteInfo();
void SearchInfo();
void ChangePercent();

enum Percent
{
	percent_1 = 5,
	percent_2 = 10,
	percent_3 = 15,
	percent_4 = 20,
	percent_5 = 25,
	percent_6 = 30
};

struct Store
{
	string name_product;
	double price_product;
	int quantity;
};

Store list_of_store[size];
int choice, current_size = 0, number_product;
Percent selected_percent = percent_1;

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
		cout << "5 - Работа с надбавкой." << endl;
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
			ChangePercent();
			break;
		}
	} while (choice != 6);
}

void InputInfo()
{
	cout << endl;
	cout << "Ввод информации: " << endl;
	cout << "Введите количество товаров: ";
	cin >> number_product;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_product; i++) {
			cout << "Введите информацию для " << i + 1 << " товара: " << endl;
			cout << "Введите название товара: ";
			cin.ignore();
			getline(cin, list_of_store[current_size].name_product);
			cout << "Введите цену товара: ";
			cin >> list_of_store[current_size].price_product;
			cout << "Введите, в каком количестве данный товар находится на складе: ";
			cin >> list_of_store[current_size].quantity;
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
		cout << "Информация о " << i + 1 << " товаре: " << endl;
		cout << "Название товара: ";
		cout << list_of_store[i].name_product << endl;
		cout << "Цена товара с учётом надбавки: ";
		cout << list_of_store[i].price_product * (1 + static_cast<double>(selected_percent) / 100) << endl;
		cout << "Количество данного товара на складе: ";
		cout << list_of_store[i].quantity;
		cout << endl;
	}
}

void SearchInfo()
{
	cout << endl;
	string name;
	cout << "Введите название товара: ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < current_size; i++) {
		if (name == list_of_store[i].name_product) {
			cout << "Информация о " << i + 1 << " товаре: " << endl;
			cout << "Название товара: ";
			cout << list_of_store[i].name_product << endl;
			cout << "Цена товара с учетом надбавки: ";
			cout << list_of_store[i].price_product * (1 + static_cast<double>(selected_percent) / 100) << endl;
			cout << "Количество данного товара на складе: ";
			cout << list_of_store[i].quantity;
			cout << endl;
		}
		else {
			cout << "Ничего не найдено.";
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
			list_of_store[del] = list_of_store[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "Неверный номер строки." << endl;
	}
}

void ChangePercent()
{
	cout << endl;
	cout << "Выберите процент надбавки: " << endl;
	cout << "1 - 5%" << endl;
	cout << "2 - 10%" << endl;
	cout << "3 - 15%" << endl;
	cout << "4 - 20%" << endl;
	cout << "5 - 25%" << endl;
	cout << "6 - 30%" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		selected_percent = percent_1;
		break;
	case 2:
		selected_percent = percent_2;
		break;
	case 3:
		selected_percent = percent_3;
		break;
	case 4:
		selected_percent = percent_4;
		break;
	case 5:
		selected_percent = percent_5;
		break;
	case 6:
		selected_percent = percent_6;
		break;
	default:
		cout << "Нет такого варианта." << endl;
		break;
	}
}