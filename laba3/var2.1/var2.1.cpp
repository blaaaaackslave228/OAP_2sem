#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char str[500];
    ifstream file_one("D:/�����/2 ���/����/����/files/FileG.txt");
    if (!file_one) {
        cout << "������ ������� ���� ��� ������";
    }

    ofstream file_two("D:/�����/2 ���/����/����/files/FileF.txt");
    if (!file_two) {
        cout << "������ ������� ��������� ���� ��� ������";
    }

    while (file_one.getline(str, 500)) {
        if (str[0] == 'A') {
            file_two << str << endl;
        }
    }

    file_one.close();
    file_two.close();

    return 0;
}
