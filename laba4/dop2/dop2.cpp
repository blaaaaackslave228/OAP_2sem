#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void InputInfo();
void SearchInfo();
void SortDestinations();

struct TRAIN
{
	string DestinationPoint;
	int NumberTrain;
	int hours;
	int minutes;
};

TRAIN list_of_train[8];
const int ElementsTrain = 8;
int numTrains;

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RU");
	cout << "���������� � �������: " << endl;
	cout << "������� ���������� �������: ";
	cin >> numTrains;
	cout << endl;
	if (numTrains > ElementsTrain) {
		cout << "���������� ������� �� ����� ���� ������ " << ElementsTrain << endl;
	}
	InputInfo();
	SearchInfo();
}

void SortDestinations() {
	for (int i = 0; i < numTrains - 1; i++) {
		for (int j = 0; j < numTrains - i - 1; j++) {
			if (list_of_train[j].DestinationPoint > list_of_train[j + 1].DestinationPoint) {
				TRAIN temp = list_of_train[j];
				list_of_train[j] = list_of_train[j + 1];
				list_of_train[j + 1] = temp;
			}
		}
	}
}

void InputInfo()
{
	for (int i = 0; i < numTrains; i++) {
		cout << "������� ���������� ��� " << i + 1 << " ������: " << endl;
		cout << "������� ����� ����������: ";
		cin.ignore();
		getline(cin, list_of_train[i].DestinationPoint);
		do {
			cout << "������� ���� �����������: ";
			cin >> list_of_train[i].hours;
			if (list_of_train[i].hours > 23 && list_of_train[i].hours < 0) {
				cout << "������� ���������� ��������." << endl;
			}
		} while (list_of_train[i].hours > 23);
		do {
			cout << "������� ������ �����������: ";
			cin >> list_of_train[i].minutes;
			if (list_of_train[i].minutes > 59 && list_of_train[i].minutes < 0) {
				cout << "������� ���������� ��������." << endl;
			}
		} while (list_of_train[i].minutes > 59);
		cout << "������� ����� ������: ";
		cin >> list_of_train[i].NumberTrain;
		cout << endl;
	}
}

void SearchInfo()
{
	SortDestinations();
	int hours1, minutes1;
	cout << "������� ���(�) ����������� ������: ";
	cin >> hours1;
	cout << "������� ������(�) ����������� ������: ";
	cin >> minutes1;
	bool found = false;
	for (int i = 0; i < numTrains; i++) {
		if ((hours1 < list_of_train[i].hours) && (minutes1 < list_of_train[i].minutes)) {
			cout << "����� ���������� ��� " << i + 1 << " ������: " << endl;
			cout << "����� ����������: ";
			cout << list_of_train[i].DestinationPoint << endl;
			cout << "���(�) �����������: ";
			cout << list_of_train[i].hours << endl;
			cout << "������(������) �����������: ";
			cout << list_of_train[i].minutes << endl; 
			cout << "����� ������: ";
			cout << list_of_train[i].NumberTrain << endl;
			cout << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "����� ������� ���." << endl;
	}
}
