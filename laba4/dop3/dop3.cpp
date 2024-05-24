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
	cout << "������� ���������� ��������������� ����������: ";
	cin >> num_sanats;
	list_of_sanat = new Sanat[num_sanats];
	InputInfo();
	cout << endl;
	cout << "�������: " << endl;
	cout << endl;
	OutputInfo();
	cout << endl;
	SearchInfo();
}

void InputInfo()
{
	for (int i = 0; i < num_sanats; i++) {
		cout << "������� ���������� " << i + 1 << " ���������: " << endl;
		cout << "������� �������� ���������: ";
		cin.ignore();
		getline(cin, list_of_sanat[i].NameSanat);
		cout << "������� �������������� ���������: ";
		getline(cin, list_of_sanat[i].DestinationPoint);
		cout << "������� �������� ������� ���������: ";
		getline(cin, list_of_sanat[i].MedicalProfile);
		cout << "������� ���������� �������: ";
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
		cout << "������� ���������� " << i + 1 << " ���������: " << endl;
		cout << "�������� ������� ���������: ";
		cout << list_of_sanat[i].MedicalProfile << endl;
		cout << "�������� ���������: ";
		cout << list_of_sanat[i].NameSanat << endl;
		cout << "�������������� ���������: ";
		cout << list_of_sanat[i].DestinationPoint << endl;
		cout << "���������� �������: ";
		cout << list_of_sanat[i].NumberTrip;
		cout << endl;
	}
	cout << endl;
}

void SearchInfo()
{
	string name;
	cout << "������� �������� ���������: ";
	cin.ignore();
	getline(cin, name);
	bool found = false;
	for (int i = 0; i < num_sanats; i++) {
		if (name == list_of_sanat[i].NameSanat)
		{
			cout << "����������� � " << i + 1 << " ���������: " << endl;
			cout << "�������� ���������: ";
			cout << list_of_sanat[i].NameSanat << endl;
			cout << "�������������� ���������: ";
			cout << list_of_sanat[i].DestinationPoint << endl;
			cout << "���������� �������: ";
			cout << list_of_sanat[i].NumberTrip << endl;
			cout << "�������� �������: ";
			cout << list_of_sanat[i].MedicalProfile << endl;
			cout << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "���������� � ����� ��������� ���." << endl;
	}
	cout << endl;
}



