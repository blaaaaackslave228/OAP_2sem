#include <iostream>
using namespace std;

const int n = 5;
int mas[n];

void func(int k)
{
    if (k == n - 1) {
        for (int j = 0; j < n; j++) {
            cout << " " << mas[j];
        }
        cout << endl;
    }
    else {
        for (int i = k; i < n; i++) {
            int temp = mas[k];
            mas[k] = mas[i];
            mas[i] = temp;
            func(k + 1);
            temp = mas[k];
            mas[k] = mas[i];
            mas[i] = temp;
        }
    }
}

int main()
{
    for (int i = 0; i < n; i++) {
        mas[i] = i + 1;
    }
    func(0);
    return 0;
}
