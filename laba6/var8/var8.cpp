#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

struct list
{
    int value;
    list* next;
};

void input();
void del();
void search();
void output();
void infile();
void fromfile(list*& head);
void sum();
void clean(list*& head);

int choice;
list* head = nullptr;

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    do {
        cout << "Выберите операцию: " << endl;
        cout << "1 - Добавление элемента." << endl;
        cout << "2 - Удаление элемента." << endl;
        cout << "3 - Поиск элемента." << endl;
        cout << "4 - Вывод списка в консольное окно." << endl;
        cout << "5 - Запись списка в файл." << endl;
        cout << "6 - Считывание списка из файла." << endl;
        cout << "7 - Сумма отрицательных чисел, которые кратны 2." << endl;
        cout << "8 - Выход." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            del();
            break;
        case 3:
            search();
            break;
        case 4:
            output();
            break;
        case 5:
            infile();
            break;
        case 6:
            fromfile(head);
            break;
        case 7:
            sum();
            break;
        }
    } while (choice != 8);
}

void input()
{
    int number;
    cout << "Введите число: ";
    cin >> number;
    list* newP = new list;
    if (newP != NULL)
    {
        newP->value = number;
        newP->next = head;
        head = newP;
        cout << "Число добавлено в список." << endl;
    }
    else {
        cout << "Операция добавления не выполнена.";
    }
}

void output()
{
    list* temp = head;
    if (temp == NULL) {
        cout << "Список пуст." << endl;
    }
    else {
        cout << "Список: " << endl;
        while (temp != NULL) {
            cout << "-->" << temp->value;
            temp = temp->next;
        }
        cout << "-->NULL" << endl;
    }
}

void search()
{
    int number;
    cout << "Введите число: ";
    cin >> number;
    list* temp = head;
    bool found = false;

    while (temp) {
        if (temp->value == number) {
            cout << "Искомое число: " << number << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Нет такого числа." << endl;
    }
}

void clean(list*& head)
{
    list* current = head;
    while (current != nullptr) {
        list* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void del()
{
    int number = 0;
    cout << "Введите число, которое хотите удалить: ";
    cin >> number;
    list* previous, * current, * temp;
    if (number == head->value) {
        temp = head;
        head = head->next;
        delete temp;
    }
    else {
        previous = head;
        current = head->next;
        while (current != NULL && current->value != number) {
            previous = current;
            current = current->next;
        }
        if (current != NULL) {
            temp = current;
            previous->next = current->next;
            delete(temp);
        }
    }
}

void sum()
{
    int sum = 0;
    bool found = false;
    list* temp = head;

    if (temp == NULL) {
        cout << "Список пуст." << endl;
    }
    else {
        while (temp != NULL) {
            if (temp->value < 0 || temp->value % 2 == 0) {
                sum = sum + temp->value;
                found = true;
            }
            temp = temp->next;
        }
        if (found) {
            cout << "Сумма элементов, меньших 0 и кратных 2: " << sum << endl;
        }
        if (!found) {
            cout << "Таких элементов нет." << endl;
        }
    }
}

void infile()
{
    ofstream fileone("D:/Денис/2 сем/оаип/лабы/files/lab6.8.txt");

    if (!fileone) {
        cout << "Не удалось открыть файл для записи." << endl;
    }

    list* temp = head;
    while (temp != nullptr) {
        fileone << temp->value << ' ';
        temp = temp->next;
    }

    fileone.close();
    cout << "Список успешно записан." << endl;
}

void fromfile(list*& head)
{
    clean(head);
    char buf[10];
    int count = 0;
    int number;
    ifstream filetwo("D:/Денис/2 сем/оаип/лабы/files/lab6.8.txt");

    if (!filetwo) {
        cout << "Не удалось открыть файл для чтения." << endl;
    }

    while (filetwo >> number)
    {
        list* newNode = new list;
        newNode->value = number;
        newNode->next = head;
        head = newNode;
        count++;
    }

    filetwo.close();
    cout << "Список успешно прочитан." << endl;
}

