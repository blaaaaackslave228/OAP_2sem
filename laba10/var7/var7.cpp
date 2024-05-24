#include <iostream>
#include <cmath>

using namespace std;

double SumSin(double x, int n, int i = 0)
{
	if (i > n) {
		return 0;
	}
		return sin(i * x) + SumSin(x, n, i + 1);
}

int main()
{
	setlocale(LC_ALL, "RU");
	double x;
	cout << "������� x: ";
	cin >> x;
	int n;
	cout << "������� ���������� ������ ����: ";
	cin >> n;
	double y = SumSin(n, x);
	cout << "�����: " << y;
	return 0;

}