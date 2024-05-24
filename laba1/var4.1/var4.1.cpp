#include <iostream>
#include <cmath>

using namespace std;

float metod_dihotomii(float (*fun)(float), float a, float b, float e) {
    float x;

    do
    {
        x = (a + b) / 2;

        if (fun(x) * fun(a) <= 0)
        {
            b = x;
        }
        else {
            a = x;
        }

    } while (abs(a - b) > 2 * e);

    return x;

}

float f1(float x) {
    return pow(x, 3) + 2 * x - 1;
}
float f2(float x) {
    return exp(x) - 2;
}

void function()
{
    float e = 0.001, a, b;
    cout << "������� a: ";
    cin >> a;
    cout << "������� b: ";
    cin >> b;
    cout << endl;
    cout << "������ ������� ���������: " << metod_dihotomii(f1, a, b, e) << endl;
    cout << "������ ������� ���������: " << metod_dihotomii(f2, a, b, e) << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    function();
    return 0;
}
