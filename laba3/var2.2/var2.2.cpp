#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "������� ������ ��������, ��������� �� ����� ���� � �����: ";
    string input;
    getline(cin, input);
    ofstream file_one("D:/�����/2 ���/����/����/files/FileZ.txt");
    if (!file_one) {
        cout << "���������� ������� ���� ��� ������" << endl;
    }
    file_one << input;
    file_one.close();

    ifstream file_two("D:/�����/2 ���/����/����/files/FileZ.txt");
    if (!file_two) {
        cout << "���������� ������� ���� ��� ������" << endl;
        return 1;
    }

    string min_group;
    file_two >> min_group;
    string group;
    while (file_two >> group) {
        if (group.length() < min_group.length()) {
            min_group = group;
        }
    }

    file_two.close();

    cout << "����� �������� ������: " << min_group << endl;

    return 0;
}
