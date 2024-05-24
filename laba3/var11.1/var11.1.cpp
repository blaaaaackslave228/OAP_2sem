#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    char str[1000];
    ifstream file_one("D:/Денис/2 сем/оаип/лабы/files/FileD.txt");
    ofstream file_two("D:/Денис/2 сем/оаип/лабы/files/FileE.txt");

    if (!file_one) {
        cout << "Нельзя открыть файл для чтения" << endl;
    }

    if (!file_two) {
        cout << "Нельзя открыть записывающий файл" << endl;
    }

    while (file_one.getline(str, 1000)) {
        if (str[0] != ' ') {
            file_two << str << endl;
        }
    }

    file_one.close();
    file_two.close();

    ifstream file_three("D:/Денис/2 сем/оаип/лабы/files/FileE.txt");
    if (!file_three) {
        cout << "нельзя открыть файл для чтения" << endl;
    }

    while (file_three.getline(str, 1000)) {
        int total_symbols = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            total_symbols++;
        }
        cout << "Количество символов в слове: " << total_symbols << endl;
    }

    file_three.close();
    return 0;
}
