#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#define size 200

using namespace std;

void input();
void output();
void search();
void infile();
void fromfile();

union ForStudents
{
	char full_name[100];
	char speciality[50];
	int group;
	char faculty[10];
	double middle_point;
};

struct Date
{
	string date;
};

struct Students
{
	ForStudents fio;
	ForStudents profession;
	ForStudents team;
	ForStudents department;
	ForStudents point;
	Date date_of_receipt;
};

Students list_of_students[size];
int choice, current_size = 0, number_students;

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
            output();
            break;
        case 3:
            search();
            break;
        case 4:
            infile();
            break;
        case 5:
            fromfile();
            break;
        }
    } while (choice != 6);
}

void input()
{
    cout << endl;
    cout << "Ввод информации: " << endl;
    cout << "Введите количество студентов: ";
    cin >> number_students;
    cout << endl;
    if (current_size < size) {
        for (int i = 0; i < number_students; i++) {
            cout << "Информация о " << i + 1 << " студенте: " << endl;
            cout << "Введите ФИО студента: ";
            cin.ignore();
            cin.getline(list_of_students[current_size].fio.full_name, 95);
            cout << "Введите дату поступления: ";
            getline(cin, list_of_students[current_size].date_of_receipt.date);
            cout << "Введите специальность: ";
            cin.getline(list_of_students[current_size].profession.speciality, 45);
            cout << "Введите факультет: ";
            cin.getline(list_of_students[current_size].department.faculty, 10);
            cout << "Введите группу: ";
            cin >> list_of_students[current_size].team.group;
            cout << "Введите средний балл: ";
            cin >> list_of_students[current_size].point.middle_point;
            current_size++;
            cout << endl;
        }
    }
}

void output()
{
    cout << endl;
    cout << "Вывод информации: " << endl;
    for (int i = 0; i < current_size; i++) {
        cout << "Информация о " << i + 1 << " студенте: " << endl;
        cout << "ФИО студента: ";
        cout << list_of_students[i].fio.full_name << endl;
        cout << "Дата поступления: ";
        cout << list_of_students[i].date_of_receipt.date << endl;
        cout << "Специальность: ";
        cout << list_of_students[i].profession.speciality << endl;
        cout << "Факультет: ";
        cout << list_of_students[i].department.faculty << endl;
        cout << "Группа: ";
        cout << list_of_students[i].team.group << endl;
        cout << "Средний балл: ";
        cout << list_of_students[i].point.middle_point << endl;
        cout << endl;
    }
}

void search()
{
    double mid_point;
    cout << "Введите средний балл: ";
    cin >> mid_point;
    for (int i = 0; i < current_size; i++) {
        if (mid_point == list_of_students[i].point.middle_point) {
            cout << "Информация о " << i + 1 << " студенте: " << endl;
            cout << "ФИО студента: ";
            cout << list_of_students[i].fio.full_name << endl;
            cout << "Дата поступления: ";
            cout << list_of_students[i].date_of_receipt.date << endl;
            cout << "Специальность: ";
            cout << list_of_students[i].profession.speciality << endl;
            cout << "Факультет: ";
            cout << list_of_students[i].department.faculty << endl;
            cout << "Группа: ";
            cout << list_of_students[i].team.group << endl;
            cout << "Средний балл: ";
            cout << list_of_students[i].point.middle_point << endl;
            cout << endl;
        }
        else
        {
            cout << "Информация не найдена." << endl;
        }
    }
}

void infile()
{
    ofstream file1("D:/Денис/2 сем/оаип/лабы/files/students.txt", ios::app);
    
    if (!file1) {
        cout << "Не удалось открыть файл для записи." << endl;
    }

    for (int i = 0; i < current_size; i++) {
        file1 << "Информация о " << i + 1 << " студенте: " << endl;
        file1 << "ФИО студента: ";
        file1 << list_of_students[i].fio.full_name << endl;
        file1 << "Дата поступления: ";
        file1 << list_of_students[i].date_of_receipt.date << endl;
        file1 << "Специальность: ";
        file1 << list_of_students[i].profession.speciality << endl;
        file1 << "Факультет: ";
        file1 << list_of_students[i].department.faculty << endl;
        file1 << "Группа: ";
        file1 << list_of_students[i].team.group << endl;
        file1 << "Средний балл: ";
        file1 << list_of_students[i].point.middle_point << endl;
    }

    file1.close();
    cout << "Данные успешно записаны в файл." << endl;
}

void fromfile()
{
    ifstream file2("D:/Денис/2 сем/оаип/лабы/files/students.txt");

    if (!file2) {
        cout << "Не удалось октрыть файл для чтения." << endl;
    }

    string line;
    while (getline(file2, line)) {
        cout << line << endl;
    }

    file2.close();
    cout << "Данные из файла успешно прочтены." << endl;
}
