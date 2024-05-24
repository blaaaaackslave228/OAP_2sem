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
	cout << "¬ведите x: ";
	cin >> x;
	int n;
	cout << "¬ведите количество членов р€да: ";
	cin >> n;
	double y = SumSin(n, x);
	cout << "—умма: " << y;
	return 0;

}