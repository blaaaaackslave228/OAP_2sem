#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ifstream file_one("D:/�����/2 ���/����/����/files/FileA.txt");
    ofstream file_two("D:/�����/2 ���/����/����/files/FileB.txt");
    char str[1000];
    int countA = 0;
    if (!file_one) {
        cout << "������ ������� ���� ��� ������" << endl;
    }

    if (!file_two) {
        cout << "������ ������� ���� ��� ������" << endl;
    }

    while (file_one.getline(str, 1000)) {
        bool numbers = false;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                numbers = true;
                break;
            }
        }
        if (!numbers) {
            file_two << str << endl;
            if (str[0] == 'A') {
                countA++;
            }
        }
    }

    cout << "���������� �����, ������������ � 'A': " << countA << endl;

    file_one.close();
    file_two.close();

    return 0;
}
