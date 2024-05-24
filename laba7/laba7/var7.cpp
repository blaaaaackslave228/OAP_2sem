#include <iostream>
#include "func.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int choice, x;
    Stack* myStk = nullptr;
    for (;;) {
        cout << "Выберите команду:" << endl;
        cout << "1 - Добавление элемента в стек" << endl;
        cout << "2 - Извлечение первого элемента из стека, который больше 100" << endl;
        cout << "3 - Запись в файл" << endl;
        cout << "4 - Чтение из файла" << endl;
        cout << "5 - Очистка стека" << endl;
        cout << "6 - Вывод стека на экран" << endl;
        cout << "7 - Выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите элемент: " << endl;
            cin >> x;
            Push(x, myStk);
            break;
        case 2:
            FirstElement(myStk, 100);
            break;
        case 3:
            ToFile(myStk);
            break;
        case 4:
            FromFile(myStk);
            break;
        case 5:
            cout << "Очищенный стек: " << endl;
            Clear(myStk);
            break;
        case 6:
            Output(myStk);
            break;
        case 7:
            return 0;
            break;
        }
    }
    return 0;
}
