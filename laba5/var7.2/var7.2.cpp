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
    cout << "Ввод информации: " << endl;
    cout << "Введите количество товаров: ";
    cin >> number_product;
    cout << endl;
    if (current_size < size) {
        for (int i = 0; i < number_product; i++) {
            cout << "Введите информацию для " << i + 1 << " товара: " << endl;
            cout << "Введите название товара: ";
            cin.ignore();
            cin.getline(list_of_store[current_size].name_of_product.name_product, 40);
            cout << "Введите цену товара: ";
            cin >> list_of_store[current_size].cost.price_product;
            cout << "Введите, в каком количестве данный товар находится на складе: ";
            cin >> list_of_store[current_size].many.quantity_product;
            cout << "Введите процентную надбавку: ";
            cin >> list_of_store[current_size].percent.quantity_product;
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
        cout << "Информация о " << i + 1 << " товаре: " << endl;
        cout << "Название товара: ";
        cout << list_of_store[i].name_of_product.name_product << endl;
        cout << "Цена товара: ";
        cout << list_of_store[i].cost.price_product << endl;
        cout << "Количество данного товара на складе: ";
        cout << list_of_store[i].many.quantity_product << endl;
        cout << "Процентная надбавка: ";
        cout << list_of_store[i].percent.quantity_product;
        cout << endl;
    }
}

void search() {
    char first_name[50];
    cout << "Введите наименование товара: ";
    cin.ignore();
    cin.getline(first_name, 40);
    for (int i = 0; i < current_size; i++) {
        if (strcmp(first_name, list_of_store[i].name_of_product.name_product) == 0) {
            cout << "Информация о " << i + 1 << " товаре: " << endl;
            cout << "Название товара: ";
            cout << list_of_store[i].name_of_product.name_product << endl;
            cout << "Цена товара: ";
            cout << list_of_store[i].cost.price_product << endl;
            cout << "Количество данного товара на складе: ";
            cout << list_of_store[i].many.quantity_product << endl;
            cout << "Процентная надбавка: ";
            cout << list_of_store[i].percent.quantity_product;            
            cout << endl;
        }
    }
}

void ofile()
{
    ofstream file1("D:/Денис/2 сем/оаип/лабы/files/store.txt", ios::app);
    if (!file1) {
        cout << "Не удалось открыть файл" << endl;
    }

    for (int i = 0; i < current_size; i++) {
        file1 << "Информация о " << i + 1 << " товаре: " << endl;
        file1 << "Название товара: " << list_of_store[i].name_of_product.name_product << endl;
        file1 << "Цена товара:  " << list_of_store[i].cost.price_product << endl;
        file1 << "Количество товара: " << list_of_store[i].many.quantity_product << endl;
        file1 << "Процентная надбавка: " << list_of_store[i].percent.quantity_product << endl;
    }
    file1.close();
    cout << "Данные успешно записаны в файл." << endl;
}

void ifile()
{
    ifstream file2("D:/Денис/2 сем/оаип/лабы/files/store.txt");

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
