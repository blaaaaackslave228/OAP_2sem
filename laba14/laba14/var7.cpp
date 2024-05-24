#include <iostream>
#include <string>
#include <chrono>
#include <Windows.h>
using namespace std;

struct Node
{
    int number_phone;
    string name;
    string surname;
    string dadname;
    Node* next;
};

unsigned int Hash_Function(int number_phone, int table_size)
{
    return number_phone % table_size;
}

void Add_Element(Node** mas, int table_size)
{
    int phone;
    string name;
    string surname;
    string dadname;
    cout << "Введите имя: ";
    cin >> name;
    cout << "Введите фамилию: ";
    cin >> surname;
    cout << "Введите отчество: ";
    cin >> dadname;
    cout << "Введите номер телефона: ";
    cin >> phone;
    int key = Hash_Function(phone, table_size);
    Node* temp = new Node;
    temp->number_phone = phone;
    temp->name = name;
    temp->surname = surname;
    temp->dadname = dadname;
    temp->next = NULL;
    if (mas[key] == NULL) {
        mas[key] = temp;
    }
    else {
        Node* current = mas[key];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void Print_Table(Node** mas, int table_size)
{
    bool isEmpty = true;
    for (int i = 0; i < table_size; i++) {
        Node* current = mas[i];
        while (current != NULL) {
            isEmpty = false;
            cout << "Ключ: " << i << endl;
            cout << "ФИО: " << current->surname << " " << current->name << " " << current->dadname << endl;
            cout << "Номер телефона: " << current->number_phone << endl;
            current = current->next;
        }
    }
    if (isEmpty) {
        cout << "Таблица пуста" << endl;
    }
}

void Search_Element(Node** mas, int table_size)
{
    int num;
    cout << "Введите номер телефона, который хотите найти: ";
    cin >> num;
    int key = Hash_Function(num, table_size);
    Node* temp = mas[key];
    auto start_time = chrono::high_resolution_clock::now();
    while (temp != NULL) {
        if (temp->number_phone == num) {
            cout << "Ключ: " << key << endl;
            cout << "ФИО: " << temp->surname << " " << temp->name << " " << temp->dadname << endl;
            cout << "Номер телефона: " << temp->number_phone << endl;
            break;
        }
        temp = temp->next;
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Время поиска: " << search_time.count() << " микросекунд" << endl;
}

void Del_Element(Node** mas, int table_size)
{
    int num;
    cout << "Введите номер, который хотите удалить: ";
    cin >> num;
    int key = Hash_Function(num, table_size);
    Node* current = mas[key];
    Node* prev = NULL;
    while (current != NULL) {
        if (current->number_phone == num) {
            if (prev == NULL) {
                mas[key] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Номер удален" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Такого номера нет" << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int table_size;
    cout << "Введите размер таблицы: ";
    cin >> table_size;
    Node** mas = new Node * [table_size];
    for (int i = 0; i < table_size; ++i) {
        mas[i] = NULL;
    }
    int choice;
    cout << "1 - Добавление элемента в таблицу" << endl;
    cout << "2 - Удаление элемента таблицы" << endl;
    cout << "3 - Поиск элемента в таблице" << endl;
    cout << "4 - Вывод таблицы" << endl;
    do {
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_Element(mas, table_size);
            break;
        case 2:
            Del_Element(mas, table_size);
            break;
        case 3:
            Search_Element(mas, table_size);
            break;
        case 4:
            Print_Table(mas, table_size);
            break;
        }
    } while (choice != 0);

    for (int i = 0; i < table_size; ++i) {
        Node* current = mas[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] mas;
    return 0;
}
