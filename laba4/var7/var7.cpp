#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#define size 30

using namespace std;

void InputInfo();
void OutputInfo();
void SearchInfo();
void DeleteInfo();
void WritingToFile();
void WritingOutFile();

struct Flights
{
	int NumberFlights;
	string DestinationPoint;
	string Time;
	string Date;
	int PriceTicket;
	int NumberOfSeats;
};

Flights list_of_fly[size];
int choice, current_size = 0, num_flightes;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	do {
		cout << "�������� ��������: " << endl;
		cout << "1 - ���� ������." << endl;
		cout << "2 - ����� ������." << endl;
		cout << "3 - ����� ����������." << endl;
		cout << "4 - �������� ������." << endl;
		cout << "5 - ���� ������ � ����." << endl;
		cout << "6 - ����� ������ �� �����." << endl;
		cout << "7 - �����." << endl;
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
			WritingToFile();
			break;
		case 6:
			WritingOutFile();
			break;
		}
	} while (choice != 7);
}

void InputInfo()
{
	cout << endl;
	cout << "���� ����������: " << endl;
	cout << "������� ���������� ������: ";
	cin >> num_flightes;
	cout << endl;
	if (current_size < size)
	{
		for (int i = 0; i < num_flightes; i++)
		{
			cout << "������� ���������� ��� " << i + 1 << " �����: " << endl;
			cout << "����� �����: ";
			cin >> list_of_fly[current_size].NumberFlights;
			cout << "����� ����������: ";
			cin.ignore();
			getline(cin, list_of_fly[current_size].DestinationPoint);
			cout << "����� ������: ";
			getline(cin, list_of_fly[current_size].Time);
			cout << "���� ������: ";
			getline(cin, list_of_fly[current_size].Date);
			cout << "��������� ������: ";
			cin >> list_of_fly[current_size].PriceTicket;
			cout << "������� ���������� ����: ";
			cin >> list_of_fly[current_size].NumberOfSeats;
			cout << endl;
			current_size++;
		}
	}
}

void OutputInfo()
{
	cout << endl;
	cout << "����� ����������: " << endl;
	for (int i = 0; i < current_size; i++)
	{
		cout << "���������� � " << i + 1 << " �����: " << endl;
		cout << "����� �����: ";
		cout << list_of_fly[i].NumberFlights<<endl;
		cout << "����� ����������: ";
		cout << list_of_fly[i].DestinationPoint<<endl;
		cout << "����� ������: ";
		cout << list_of_fly[i].Time << endl;
		cout << "���� ������: ";
		cout << list_of_fly[i].Date << endl;
		cout << "��������� ������: ";
		cout << list_of_fly[i].PriceTicket << endl;
		cout << "������� ���������� ����: ";
		cout << list_of_fly[i].NumberOfSeats << endl;
		cout << endl;
	}
}

void SearchInfo()
{
	string point;
	cout << "������� ����� ����������: ";
	cin.ignore();
	getline(cin, point);
	for (int i = 0; i < current_size; i++) {
		if (point == list_of_fly[i].DestinationPoint)
		{
			cout << "����������� � " << i + 1 << " �����: " << endl;
			cout << "����� �����: ";
			cout << list_of_fly[i].NumberFlights << endl;
			cout << "����� ����������: ";
			cout << list_of_fly[i].DestinationPoint << endl;
			cout << "����� ������: ";
			cout << list_of_fly[i].Time << endl;
			cout << "���� ������: ";
			cout << list_of_fly[i].Date << endl;
			cout << "��������� ������: ";
			cout << list_of_fly[i].PriceTicket << endl;
			cout << "������� ���������� ����: ";
			cout << list_of_fly[i].NumberOfSeats << endl;
			cout << endl;
		}
		else if(point!=list_of_fly[i].DestinationPoint) {
			cout << "���������� � ����� ����� ���." << endl;
		}
	}
}

void DeleteInfo()
{
	int NumberLine;
	cout << "������� ����� ������, ������� ������ �������: ";
	cin >> NumberLine;
	if (NumberLine > 0 && NumberLine <= current_size) {
		for (int del = NumberLine - 1; del < current_size - 1; del++) {
			list_of_fly[del] = list_of_fly[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "�������� ����� ������." << endl;
	}
}

void WritingToFile()
{
	ofstream file1("D:/�����/2 ���/����/����/files/fly.txt");
	if (!file1) {
		cout << "�� ������� ������� ����" << endl;
	}

	for (int i = 0; i < current_size; i++) {
		file1 << "���������� � " << i + 1 << " �����: " << endl;
		file1 << "����� �����: " << list_of_fly[i].NumberFlights << endl;
		file1 << "����� ����������: " << list_of_fly[i].DestinationPoint << endl;
		file1 << "����� ������: " << list_of_fly[i].Time << endl;
		file1 << "���� ������: " << list_of_fly[i].Date << endl;
		file1 << "��������� ������: " << list_of_fly[i].PriceTicket << endl;
		file1 << "���������� ����: " << list_of_fly[i].NumberOfSeats << endl;
	}
	file1.close();
	cout << "������ ������� �������� � ����." << endl;
}

void WritingOutFile()
{
	ifstream file2("D:/�����/2 ���/����/����/files/fly.txt");

	if (!file2) {
		cout << "�� ������� ������� ����." << endl;
	}

	string line;
	while(getline(file2, line)){
		cout << line << endl;
	}
	file2.close();
	cout << "������ ������� �������� �� �����." << endl;
}