#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char str[500];
    ifstream file_one("D:/Денис/2 сем/оаип/лабы/files/FileG.txt");
    if (!file_one) {
        cout << "Нельзя открыть файл для чтения";
    }

    ofstream file_two("D:/Денис/2 сем/оаип/лабы/files/FileF.txt");
    if (!file_two) {
        cout << "Нельзя открыть временный файл для записи";
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
