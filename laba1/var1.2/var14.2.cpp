#include <iostream>
#include <cstdarg>

using namespace std;

void compr(int n, ...) {
    va_list arg;
    va_start(arg, n);
    for (int i = 0; i < n; i++) {
        char* str = va_arg(arg, char*);
        for (int j = 0; str[j]; j++) {
            if (str[j] != ' ') {
                cout << str[j];
            }
        }
        cout << endl;
    }
    va_end(arg);
}

int main()
{
    setlocale(LC_ALL, "RU");
    char str1[] = "Groove Street - home";
    char str2[] = "My name is Gustavo";
    char str3[] = "Мое имя Вито Скалетто, я родился на Сицилии";
    compr(3, str1, str2, str3);
    return 0;
}
