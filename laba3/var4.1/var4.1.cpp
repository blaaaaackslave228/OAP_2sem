#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ifstream file_one("D:/Денис/2 сем/оаип/лабы/files/FileA.txt");
    ofstream file_two("D:/Денис/2 сем/оаип/лабы/files/FileB.txt");
    char str[1000];
    int countA = 0;
    if (!file_one) {
        cout << "Нельзя открыть файл для чтения" << endl;
    }

    if (!file_two) {
        cout << "Нельзя открыть файл для записи" << endl;
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

    cout << "Количество строк, начинающихся с 'A': " << countA << endl;

    file_one.close();
    file_two.close();

    return 0;
}
