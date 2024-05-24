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
    cout << "������� ���: ";
    cin >> name;
    cout << "������� �������: ";
    cin >> surname;
    cout << "������� ��������: ";
    cin >> dadname;
    cout << "������� ����� ��������: ";
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
            cout << "����: " << i << endl;
            cout << "���: " << current->surname << " " << current->name << " " << current->dadname << endl;
            cout << "����� ��������: " << current->number_phone << endl;
            current = current->next;
        }
    }
    if (isEmpty) {
        cout << "������� �����" << endl;
    }
}

void Search_Element(Node** mas, int table_size)
{
    int num;
    cout << "������� ����� ��������, ������� ������ �����: ";
    cin >> num;
    int key = Hash_Function(num, table_size);
    Node* temp = mas[key];
    auto start_time = chrono::high_resolution_clock::now();
    while (temp != NULL) {
        if (temp->number_phone == num) {
            cout << "����: " << key << endl;
            cout << "���: " << temp->surname << " " << temp->name << " " << temp->dadname << endl;
            cout << "����� ��������: " << temp->number_phone << endl;
            break;
        }
        temp = temp->next;
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto search_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "����� ������: " << search_time.count() << " �����������" << endl;
}

void Del_Element(Node** mas, int table_size)
{
    int num;
    cout << "������� �����, ������� ������ �������: ";
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
            cout << "����� ������" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "������ ������ ���" << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int table_size;
    cout << "������� ������ �������: ";
    cin >> table_size;
    Node** mas = new Node * [table_size];
    for (int i = 0; i < table_size; ++i) {
        mas[i] = NULL;
    }
    int choice;
    cout << "1 - ���������� �������� � �������" << endl;
    cout << "2 - �������� �������� �������" << endl;
    cout << "3 - ����� �������� � �������" << endl;
    cout << "4 - ����� �������" << endl;
    do {
        cout << "�������� ��������: ";
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
