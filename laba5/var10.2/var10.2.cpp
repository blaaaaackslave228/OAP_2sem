#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

#define size 300

using namespace std;

void input();
void out();
void search();
void infile();
void onfile();

union Person
{
	int year_birthday;
	char address_and_gender_and_name[200];
};

struct ForPerson
{
	Person name;
	Person birthday;
	Person point;
	Person gender_person;
};

ForPerson list_of_person[size];
int choice, current_size = 0, number_persons;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    do {
        cout << "Выберите операцию:" << endl;
        cout << "1 - Ввод информации." << endl;
        cout << "2 - Вывод информации." << endl;
        cout << "3 - Поиск информации." << endl;
        cout << "4 - Запись в файл." << endl;
        cout << "5 - Чтение из файла." << endl;
        cout << "6 - Выход." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            out();
            break;
        case 3:
            search();
            break;
        case 4:
            infile();
            break;
        case 5:
            onfile();
            break;
        }
    } while (choice != 6);
}

void input()
{
    cout << endl;
    cout << "Ввод информации: " << endl;
    cout << "Введите количество граждан: ";
    cin >> number_persons;
    cout << endl;
    if (current_size < size) {
        for (int i = 0; i < number_persons; i++) {
            cout << "Введите информацию для " << i + 1 << " гражданина: " << endl;
            cout << "Введите ФИО гражданина: ";
            cin.ignore();
            cin.getline(list_of_person[current_size].name.address_and_gender_and_name, 190);
            cout << "Введите адрес гражданина: ";
            cin.getline(list_of_person[current_size].point.address_and_gender_and_name, 190);
            cout << "Введите пол гражданина (м/ж): ";
            cin.getline(list_of_person[current_size].gender_person.address_and_gender_and_name, 190);
            cout << "Введите год рождения гражданина: ";
            cin >> list_of_person[current_size].birthday.year_birthday;
            current_size++;
            cout << endl;
        }
    }
}

void out()
{
    cout << endl;
    cout << "Вывод информации: " << endl;
    for (int i = 0; i < current_size; i++) {
        cout << "Информацию о " << i + 1 << " гражданине: " << endl;
        cout << "ФИО гражданина: ";
        cout << list_of_person[i].name.address_and_gender_and_name << endl;
        cout << "Адрес гражданина: ";
        cout << list_of_person[i].point.address_and_gender_and_name << endl;
        cout << "Пол гражданина (м/ж): ";
        cout << list_of_person[i].gender_person.address_and_gender_and_name << endl;
        cout << "Год рождения гражданина: ";
        cout << list_of_person[i].birthday.year_birthday;
        cout << endl;
    }
}

void search()
{
    int year;
    cout << "Введите год рождения гражданина: ";
    cin >> year;
    for (int i = 0; i < current_size; i++) {
        if (year == list_of_person[i].birthday.year_birthday) {
            cout << "Информацию о " << i + 1 << " гражданине: " << endl;
            cout << "ФИО гражданина: ";
            cout << list_of_person[i].name.address_and_gender_and_name << endl;
            cout << "Адрес гражданина: ";
            cout << list_of_person[i].point.address_and_gender_and_name << endl;
            cout << "Пол гражданина (м/ж): ";
            cout << list_of_person[i].gender_person.address_and_gender_and_name << endl;
            cout << "Год рождения гражданина: ";
            cout << list_of_person[i].birthday.year_birthday;
            cout << endl;
        }
        else {
            cout << "Информация не найдена." << endl;
        }
    }
}

void infile()
{
    ofstream file1("D:/Денис/2 сем/оаип/лабы/files/person.txt", ios::app);
    if (!file1) {
        cout << "Не удалось открыть файл." << endl;
    }

    for (int i = 0; i < current_size; i++) {
        file1 << "Информацию о " << i + 1 << " гражданине: " << endl;
        file1 << "ФИО гражданина: " << list_of_person[i].name.address_and_gender_and_name << endl;
        file1 << "Адрес гражданина: " << list_of_person[i].point.address_and_gender_and_name << endl;
        file1 << "Пол гражданина (м/ж): " << list_of_person[i].gender_person.address_and_gender_and_name << endl;
        file1 << "Год рождения гражданина: " << list_of_person[i].birthday.year_birthday;
    }

    file1.close();
    cout << "Данные успешно записаны." << endl;
}

void onfile()
{
    ifstream file2("D:/Денис/2 сем/оаип/лабы/files/person.txt");
    if (!file2) {
        cout << "Не удалось открыть файл." << endl;
    }

    string line;
    while (getline(file2, line)) {
        cout << line << endl;
    }
    file2.close();
    cout << "Данные успешно прочтены из файла." << endl;
}


