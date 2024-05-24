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
		cout << "Выберите операцию: " << endl;
		cout << "1 - Ввод записи." << endl;
		cout << "2 - Вывод записи." << endl;
		cout << "3 - Поиск информации." << endl;
		cout << "4 - Удаление записи." << endl;
		cout << "5 - Ввод записи в файл." << endl;
		cout << "6 - Вывод записи из файлы." << endl;
		cout << "7 - Выход." << endl;
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
	cout << "Ввод информации: " << endl;
	cout << "Введите количество рейсов: ";
	cin >> num_flightes;
	cout << endl;
	if (current_size < size)
	{
		for (int i = 0; i < num_flightes; i++)
		{
			cout << "Введите информацию для " << i + 1 << " рейса: " << endl;
			cout << "Номер рейса: ";
			cin >> list_of_fly[current_size].NumberFlights;
			cout << "Пункт назначения: ";
			cin.ignore();
			getline(cin, list_of_fly[current_size].DestinationPoint);
			cout << "Время вылета: ";
			getline(cin, list_of_fly[current_size].Time);
			cout << "Дата вылета: ";
			getline(cin, list_of_fly[current_size].Date);
			cout << "Стоимость билета: ";
			cin >> list_of_fly[current_size].PriceTicket;
			cout << "Введите количество мест: ";
			cin >> list_of_fly[current_size].NumberOfSeats;
			cout << endl;
			current_size++;
		}
	}
}

void OutputInfo()
{
	cout << endl;
	cout << "Вывод информации: " << endl;
	for (int i = 0; i < current_size; i++)
	{
		cout << "Информация о " << i + 1 << " рейсе: " << endl;
		cout << "Номер рейса: ";
		cout << list_of_fly[i].NumberFlights<<endl;
		cout << "Пункт назначения: ";
		cout << list_of_fly[i].DestinationPoint<<endl;
		cout << "Время вылета: ";
		cout << list_of_fly[i].Time << endl;
		cout << "Дата вылета: ";
		cout << list_of_fly[i].Date << endl;
		cout << "Стоимость билета: ";
		cout << list_of_fly[i].PriceTicket << endl;
		cout << "Введите количество мест: ";
		cout << list_of_fly[i].NumberOfSeats << endl;
		cout << endl;
	}
}

void SearchInfo()
{
	string point;
	cout << "Введите пункт назначения: ";
	cin.ignore();
	getline(cin, point);
	for (int i = 0; i < current_size; i++) {
		if (point == list_of_fly[i].DestinationPoint)
		{
			cout << "Инфоромация о " << i + 1 << " рейсе: " << endl;
			cout << "Номер рейса: ";
			cout << list_of_fly[i].NumberFlights << endl;
			cout << "Пункт назначения: ";
			cout << list_of_fly[i].DestinationPoint << endl;
			cout << "Время вылета: ";
			cout << list_of_fly[i].Time << endl;
			cout << "Дата вылета: ";
			cout << list_of_fly[i].Date << endl;
			cout << "Стоимость билета: ";
			cout << list_of_fly[i].PriceTicket << endl;
			cout << "Введите количество мест: ";
			cout << list_of_fly[i].NumberOfSeats << endl;
			cout << endl;
		}
		else if(point!=list_of_fly[i].DestinationPoint) {
			cout << "Информации о таком рейсе нет." << endl;
		}
	}
}

void DeleteInfo()
{
	int NumberLine;
	cout << "Введите номер строки, которую хотите удалить: ";
	cin >> NumberLine;
	if (NumberLine > 0 && NumberLine <= current_size) {
		for (int del = NumberLine - 1; del < current_size - 1; del++) {
			list_of_fly[del] = list_of_fly[del + 1];
		}
		current_size = current_size - 1;
	}
	else {
		cout << "Неверный номер строки." << endl;
	}
}

void WritingToFile()
{
	ofstream file1("D:/Денис/2 сем/оаип/лабы/files/fly.txt");
	if (!file1) {
		cout << "Не удалось открыть файл" << endl;
	}

	for (int i = 0; i < current_size; i++) {
		file1 << "Информация о " << i + 1 << " рейсе: " << endl;
		file1 << "Номер рейса: " << list_of_fly[i].NumberFlights << endl;
		file1 << "Пункт назначения: " << list_of_fly[i].DestinationPoint << endl;
		file1 << "Время вылета: " << list_of_fly[i].Time << endl;
		file1 << "Дата вылета: " << list_of_fly[i].Date << endl;
		file1 << "Стоимость билета: " << list_of_fly[i].PriceTicket << endl;
		file1 << "Количество мест: " << list_of_fly[i].NumberOfSeats << endl;
	}
	file1.close();
	cout << "Данные успешно записаны в файл." << endl;
}

void WritingOutFile()
{
	ifstream file2("D:/Денис/2 сем/оаип/лабы/files/fly.txt");

	if (!file2) {
		cout << "Не удалось открыть файл." << endl;
	}

	string line;
	while(getline(file2, line)){
		cout << line << endl;
	}
	file2.close();
	cout << "Данные успешно прочтены из файла." << endl;
}