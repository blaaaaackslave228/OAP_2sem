#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    char str[1000];
    ifstream file_one("D:/�����/2 ���/����/����/files/FileD.txt");
    ofstream file_two("D:/�����/2 ���/����/����/files/FileE.txt");

    if (!file_one) {
        cout << "������ ������� ���� ��� ������" << endl;
    }

    if (!file_two) {
        cout << "������ ������� ������������ ����" << endl;
    }

    while (file_one.getline(str, 1000)) {
        if (str[0] != ' ') {
            file_two << str << endl;
        }
    }

    file_one.close();
    file_two.close();

    ifstream file_three("D:/�����/2 ���/����/����/files/FileE.txt");
    if (!file_three) {
        cout << "������ ������� ���� ��� ������" << endl;
    }

    while (file_three.getline(str, 1000)) {
        int total_symbols = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            total_symbols++;
        }
        cout << "���������� �������� � �����: " << total_symbols << endl;
    }

    file_three.close();
    return 0;
}
