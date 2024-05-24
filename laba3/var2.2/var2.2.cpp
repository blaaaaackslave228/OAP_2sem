#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите строку символов, состоящую из групп цифр и нулей: ";
    string input;
    getline(cin, input);
    ofstream file_one("D:/Денис/2 сем/оаип/лабы/files/FileZ.txt");
    if (!file_one) {
        cout << "Невозможно открыть файл для записи" << endl;
    }
    file_one << input;
    file_one.close();

    ifstream file_two("D:/Денис/2 сем/оаип/лабы/files/FileZ.txt");
    if (!file_two) {
        cout << "Невозможно открыть файл для чтения" << endl;
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

    cout << "Самая короткая группа: " << min_group << endl;

    return 0;
}
