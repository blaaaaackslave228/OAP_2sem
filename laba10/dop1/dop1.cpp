#include <iostream>
#include <fstream>

using namespace std;

int A;
int arr[256];
ofstream file1;

void func(int k) {
    if (k == A) {
        for (int p = 0; p < A; p++)
            file1 << arr[p];
        file1 << endl;
    }
    else {
        for (int i = k; i < A; i++) {
            swap(arr[k], arr[i]);
            func(k + 1);
            swap(arr[k], arr[i]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    file1.open("file.txt");
    cout << "Введите цифру: ";
    cin >> A;
    cout << endl;
    for (int i = 0; i < A; i++)
        arr[i] = i + 1;
    func(0);
    file1.close();
    cout << "Данные записаны в файл." << endl;
    return 0;
}
