#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void InputInfo();
void OutputInfo();
void SearchInfo();
void SortMedicalProfiles();

struct Sanat
{
	string NameSanat;
	string DestinationPoint;
	string MedicalProfile;
	int NumberTrip;
};

Sanat* list_of_sanat;
int num_sanats;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	cout << "Введите количество рассматриваемых санаториев: ";
	cin >> num_sanats;
	list_of_sanat = new Sanat[num_sanats];
	InputInfo();
	cout << endl;
	cout << "Таблица: " << endl;
	cout << endl;
	OutputInfo();
	cout << endl;
	SearchInfo();
}

void InputInfo()
{
	for (int i = 0; i < num_sanats; i++) {
		cout << "Введите информацию " << i + 1 << " санатория: " << endl;
		cout << "Введите название санатория: ";
		cin.ignore();
		getline(cin, list_of_sanat[i].NameSanat);
		cout << "Введите местоположение санатория: ";
		getline(cin, list_of_sanat[i].DestinationPoint);
		cout << "Укажите лечебный профиль санатория: ";
		getline(cin, list_of_sanat[i].MedicalProfile);
		cout << "Введите количество путевок: ";
		cin >> list_of_sanat[i].NumberTrip;
		cout << endl;
	}
	cout << endl;
}

void SortMedicalProfiles() {
	for (int i = 0; i < num_sanats - 1; i++) {
		for (int j = 0; j < num_sanats - i - 1; j++) {
			if (list_of_sanat[j].MedicalProfile > list_of_sanat[j + 1].DestinationPoint) {
				Sanat temp = list_of_sanat[j];
				list_of_sanat[j] = list_of_sanat[j + 1];
				list_of_sanat[j + 1] = temp;
			}
		}
	}
}

void OutputInfo()
{
	SortMedicalProfiles();
	for (int i = 0; i < num_sanats; i++) {
		cout << "Краткий справочник " << i + 1 << " санатория: " << endl;
		cout << "Лечебный профиль санатория: ";
		cout << list_of_sanat[i].MedicalProfile << endl;
		cout << "Название санатория: ";
		cout << list_of_sanat[i].NameSanat << endl;
		cout << "Местоположение санатория: ";
		cout << list_of_sanat[i].DestinationPoint << endl;
		cout << "Количество путевок: ";
		cout << list_of_sanat[i].NumberTrip;
		cout << endl;
	}
	cout << endl;
}

void SearchInfo()
{
	string name;
	cout << "Введите название санатория: ";
	cin.ignore();
	getline(cin, name);
	bool found = false;
	for (int i = 0; i < num_sanats; i++) {
		if (name == list_of_sanat[i].NameSanat)
		{
			cout << "Инфоромация о " << i + 1 << " санатории: " << endl;
			cout << "Название санатория: ";
			cout << list_of_sanat[i].NameSanat << endl;
			cout << "Местоположение санатория: ";
			cout << list_of_sanat[i].DestinationPoint << endl;
			cout << "Количество путевок: ";
			cout << list_of_sanat[i].NumberTrip << endl;
			cout << "Лечебный профиль: ";
			cout << list_of_sanat[i].MedicalProfile << endl;
			cout << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Информации о таком санатории нет." << endl;
	}
	cout << endl;
}



