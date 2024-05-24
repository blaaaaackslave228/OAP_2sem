#include <iostream>
#include <cstdarg>

using namespace std;

void mn(int n, ...) {
    va_list arg;
    va_start(arg, n);

    int max = va_arg(arg, int);
    for (int i = 1; i < n; i++) {
        int val;
        val = va_arg(arg, int);
        if (val > max) {
            max = val;
        }
    }
    cout << "Максимальное значение: " << max << endl;
    va_end(arg);

}

int main()
{
    setlocale(LC_ALL, "rus");
    mn(5, 10, 12, 4, 3, 9);
    mn(4, 15, 3, 2, 12);
    mn(6, 320, 52, 148, 22, 34, 30);
}