#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    cout << "������� ������ ��������: ";
    char inputString[100];
    cin.getline(inputString, 100);

    ofstream outFile("D:/�����/2 ���/����/����/files/File3.txt");
    if (!outFile) {
        cout << "���������� ������� ���� ��� ������";
        return 1;
    }
    outFile << inputString;
    outFile.close();

    cout << "������� �������� k: ";
    int k;
    cin >> k;

    ifstream inFile("D:/�����/2 ���/����/����/files/File3.txt");
    if (!inFile) {
        cout << "���������� ������� ���� ��� ������";
        return 1;
    }

    int wordNumber = 0;
    int charCount = 0;
    char c;
    bool found = false;
    while (inFile.get(c)) {
        if (c == ' ') {
            charCount = 0;
        }
        else {
            charCount++;
            if (charCount == 1) {
                wordNumber++;
            }
            if (charCount == k) {
                cout << "����� �����, ����������� " << k << "-� ������: " << wordNumber << endl;
                found = true;
                break;
            }
        }
    }

    inFile.close();

    if (!found) {
        cout << "� ������ ��� ���������� �������� ��� �������� �������." << endl;
    }

    return 0;
}
