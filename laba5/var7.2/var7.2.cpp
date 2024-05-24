#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

#define size 100

using namespace std;

void input();
void out();
void search();
void ofile();
void ifile();

union ForStore
{
    char name_product[50];
    int quantity_product;
    double price_product;
};

struct Store
{
    ForStore name_of_product;
    ForStore cost;
    ForStore many;
    ForStore percent;
};
Store list_of_store[size];

int current_size = 0, choice, number_product;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    do{
        cout << "�������� ��������:" << endl;
        cout << "1 - ���� ����������." << endl;
        cout << "2 - ����� ����������." << endl;
        cout << "3 - ����� ����������." << endl;
        cout << "4 - ������ � ����." << endl;
        cout << "5 - ������ �� �����." << endl;
        cout << "6 - �����." << endl;
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
            ofile();
            break;
        case 5:
            ifile();
            break;
        }
    } while (choice != 6);
}

void input()
{
    cout << endl;
    cout << "���� ����������: " << endl;
    cout << "������� ���������� �������: ";
    cin >> number_product;
    cout << endl;
    if (current_size < size) {
        for (int i = 0; i < number_product; i++) {
            cout << "������� ���������� ��� " << i + 1 << " ������: " << endl;
            cout << "������� �������� ������: ";
            cin.ignore();
            cin.getline(list_of_store[current_size].name_of_product.name_product, 40);
            cout << "������� ���� ������: ";
            cin >> list_of_store[current_size].cost.price_product;
            cout << "�������, � ����� ���������� ������ ����� ��������� �� ������: ";
            cin >> list_of_store[current_size].many.quantity_product;
            cout << "������� ���������� ��������: ";
            cin >> list_of_store[current_size].percent.quantity_product;
            current_size++;
            cout << endl;
        }
    }
}

void out() 
{
    cout << endl;
    cout << "����� ����������: " << endl;
    for (int i = 0; i < current_size; i++) {
        cout << "���������� � " << i + 1 << " ������: " << endl;
        cout << "�������� ������: ";
        cout << list_of_store[i].name_of_product.name_product << endl;
        cout << "���� ������: ";
        cout << list_of_store[i].cost.price_product << endl;
        cout << "���������� ������� ������ �� ������: ";
        cout << list_of_store[i].many.quantity_product << endl;
        cout << "���������� ��������: ";
        cout << list_of_store[i].percent.quantity_product;
        cout << endl;
    }
}

void search() {
    char first_name[50];
    cout << "������� ������������ ������: ";
    cin.ignore();
    cin.getline(first_name, 40);
    for (int i = 0; i < current_size; i++) {
        if (strcmp(first_name, list_of_store[i].name_of_product.name_product) == 0) {
            cout << "���������� � " << i + 1 << " ������: " << endl;
            cout << "�������� ������: ";
            cout << list_of_store[i].name_of_product.name_product << endl;
            cout << "���� ������: ";
            cout << list_of_store[i].cost.price_product << endl;
            cout << "���������� ������� ������ �� ������: ";
            cout << list_of_store[i].many.quantity_product << endl;
            cout << "���������� ��������: ";
            cout << list_of_store[i].percent.quantity_product;            
            cout << endl;
        }
    }
}

void ofile()
{
    ofstream file1("D:/�����/2 ���/����/����/files/store.txt", ios::app);
    if (!file1) {
        cout << "�� ������� ������� ����" << endl;
    }

    for (int i = 0; i < current_size; i++) {
        file1 << "���������� � " << i + 1 << " ������: " << endl;
        file1 << "�������� ������: " << list_of_store[i].name_of_product.name_product << endl;
        file1 << "���� ������:  " << list_of_store[i].cost.price_product << endl;
        file1 << "���������� ������: " << list_of_store[i].many.quantity_product << endl;
        file1 << "���������� ��������: " << list_of_store[i].percent.quantity_product << endl;
    }
    file1.close();
    cout << "������ ������� �������� � ����." << endl;
}

void ifile()
{
    ifstream file2("D:/�����/2 ���/����/����/files/store.txt");

    if (!file2) {
        cout << "�� ������� ������� ����." << endl;
    }

    string line;
    while (getline(file2, line)) {
        cout << line << endl;
    }
    file2.close();
    cout << "������ ������� �������� �� �����." << endl;
}
