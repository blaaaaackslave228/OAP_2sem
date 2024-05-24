#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    cout << "Введите строку символов: ";
    char inputString[100];
    cin.getline(inputString, 100);

    ofstream outFile("D:/Денис/2 сем/оаип/лабы/files/File3.txt");
    if (!outFile) {
        cout << "Невозможно открыть файл для записи";
        return 1;
    }
    outFile << inputString;
    outFile.close();

    cout << "Введите значение k: ";
    int k;
    cin >> k;

    ifstream inFile("D:/Денис/2 сем/оаип/лабы/files/File3.txt");
    if (!inFile) {
        cout << "Невозможно открыть файл для чтения";
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
                cout << "Номер слова, содержащего " << k << "-й символ: " << wordNumber << endl;
                found = true;
                break;
            }
        }
    }

    inFile.close();

    if (!found) {
        cout << "В строке нет достаточно символов для заданной позиции." << endl;
    }

    return 0;
}
