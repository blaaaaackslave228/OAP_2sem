#include <iostream>
#include "func.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int choice, x;
    Stack* myStk = nullptr;
    for (;;) {
        cout << "�������� �������:" << endl;
        cout << "1 - ���������� �������� � ����" << endl;
        cout << "2 - ���������� ������� �������� �� �����, ������� ������ 100" << endl;
        cout << "3 - ������ � ����" << endl;
        cout << "4 - ������ �� �����" << endl;
        cout << "5 - ������� �����" << endl;
        cout << "6 - ����� ����� �� �����" << endl;
        cout << "7 - �����" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������� �������: " << endl;
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
            cout << "��������� ����: " << endl;
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
