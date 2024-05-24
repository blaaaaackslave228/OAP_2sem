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
		cout << "�������� ��������: " << endl;
		cout << "1 - ���� ������." << endl;
		cout << "2 - ����� ������." << endl;
		cout << "3 - ����� ����������." << endl;
		cout << "4 - �������� ����������." << endl;
		cout << "5 - ������ � ������� ���������." << endl;
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
			FormsGovernment();
			break;
		}
	} while (choice != 6);
}

void InputInfo()
{
	cout << endl;
	cout << "���� ����������: " << endl;
	cout << "������� ���������� �����: ";
	cin >> number_countries;
	cout << endl;
	if (current_size < size) {
		for (int i = 0; i < number_countries; i++) {
			cout << "������� ���������� ��� " << i + 1 << " ������: " << endl;
			cout << "������� �������� ������: ";
			cin.ignore();
			getline(cin, list_of_countries[current_size].name_country);
			cout << "������� ������� ������: ";
			getline(cin, list_of_countries[current_size].name_center);
			cout << "������� ��������� ������: ";
			cin >> list_of_countries[current_size].quantity_people;
			cout << "������� ������� ������: ";
			cin >> list_of_countries[current_size].square_country;
			cout << "�������� ����� ��������� ��� ����������� (0 - ��������, 1 - ����������): ";
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
	cout << "����� ����������: " << endl;
	for (int i = 0; i < current_size; i++) {
		cout << "���������� � " << i + 1 << " ������: " << endl;
		cout << "�������� ������: ";
		cout << list_of_countries[i].name_country << endl;
		cout << "������� ������: ";
		cout << list_of_countries[i].name_center << endl;
		cout << "��������� ������: ";
		cout << list_of_countries[i].quantity_people << endl;
		cout << "������� ������: ";
		cout << list_of_countries[i].square_country << endl;
		cout << "����� ���������: ";
		if (list_of_countries[i].government == Monarchy) {
			cout << "��������" << endl;
		}
		else
		{
			cout << "����������" << endl;
		}
		cout << endl;
	}
}

void SearchInfo()
{
	cout << endl;
	string capital;
	cout << "������� ������� �����������: ";
	cin.ignore();
	getline(cin, capital);
	for (int i = 0; i < current_size; i++) {
		if (capital == list_of_countries[i].name_center) {
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cout << "�������� ������: ";
			cout << list_of_countries[i].name_country << endl;
			cout << "������� ������: ";
			cout << list_of_countries[i].name_center << endl;
			cout << "��������� ������: ";
			cout << list_of_countries[i].quantity_people << endl;
			cout << "������� ������: ";
			cout << list_of_countries[i].square_country << endl;
			cout << "����� ���������: ";
			if (list_of_countries[i].government == Monarchy) {
				cout << "��������" << endl;
			}
			else
			{
				cout << "����������" << endl;
			}
		}
		else {
			cout << "������ �� �������." << endl;
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
			list_of_countries[del] = list_of_countries[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "�������� ����� ������." << endl;
	}
}

void FormsGovernment()
{
	cout << "�������� ����� ����� ��������� (0 - ��������, 1 - ����������): ";
	int form;
	cin >> form;
	selected_form = static_cast<Forms>(form);
}