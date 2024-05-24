#include <iostream>
#include <cstdarg>
using namespace std;

bool simple_numbers(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void print_numbers(int a, int b) {
    for (int i = a; i <= b; i++) {
        if (simple_numbers(i)) {
            cout << i << " ";
        }
    }
}

void sum(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int a = va_arg(args, int);
        int b = va_arg(args, int);
        print_numbers(a, b);
    }
    va_end(args);
}

int main() {
    setlocale(LC_ALL, "RU");
    int count;
    cout << "¬ведите количество интервалов: ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        int a, b;
        cout << "¬ведите границы интервала " << i + 1 << ": ";
        cin >> a >> b;
        print_numbers(a, b);
        cout << endl;
    }
    return 0;
}
