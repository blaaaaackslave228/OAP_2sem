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
		cout << "�������� ��������: " << endl;
		cout << "1 - ���� ������." << endl;
		cout << "2 - ����� ������." << endl;
		cout << "3 - ����� ����������." << endl;
		cout << "4 - �������� ����������." << endl;
		cout << "5 - ������ � ���������." << endl;
		cout << "6 - ��x��." << endl;
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
	cout << "���� ����������: " << endl;
	cout << "������� ���������� �������: ";
	cin >> number_product;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_product; i++) {
			cout << "������� ���������� ��� " << i + 1 << " ������: " << endl;
			cout << "������� �������� ������: ";
			cin.ignore();
			getline(cin, list_of_store[current_size].name_product);
			cout << "������� ���� ������: ";
			cin >> list_of_store[current_size].price_product;
			cout << "�������, � ����� ���������� ������ ����� ��������� �� ������: ";
			cin >> list_of_store[current_size].quantity;
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
		cout << "���������� � " << i + 1 << " ������: " << endl;
		cout << "�������� ������: ";
		cout << list_of_store[i].name_product << endl;
		cout << "���� ������ � ������ ��������: ";
		cout << list_of_store[i].price_product * (1 + static_cast<double>(selected_percent) / 100) << endl;
		cout << "���������� ������� ������ �� ������: ";
		cout << list_of_store[i].quantity;
		cout << endl;
	}
}

void SearchInfo()
{
	cout << endl;
	string name;
	cout << "������� �������� ������: ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < current_size; i++) {
		if (name == list_of_store[i].name_product) {
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cout << "�������� ������: ";
			cout << list_of_store[i].name_product << endl;
			cout << "���� ������ � ������ ��������: ";
			cout << list_of_store[i].price_product * (1 + static_cast<double>(selected_percent) / 100) << endl;
			cout << "���������� ������� ������ �� ������: ";
			cout << list_of_store[i].quantity;
			cout << endl;
		}
		else {
			cout << "������ �� �������.";
		}
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
			list_of_store[del] = list_of_store[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "�������� ����� ������." << endl;
	}
}

void ChangePercent()
{
	cout << endl;
	cout << "�������� ������� ��������: " << endl;
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
		cout << "��� ������ ��������." << endl;
		break;
	}
}