#include <iostream>
#include <cmath>

using namespace std;

int plus_numbers(int n, int m)
{
	if (n < 0 || m < 0) {
		return 0;
	}
	else {
		if (m != 0) {
			return plus_numbers(n + 1, m - 1);
		}
		else {
			return n;
		}
	}
}

int minus_numbers(int n, int m) 
{
	if (n < 0 && m < 0) {
		return 0;
	}
	else {
		if (m != 0) {
			return minus_numbers(n - 1, m - 1);
		}
		else {
			return n;
		}
	}
}

int multi_numbers(int n, int m)
{
	if (n < 0 && m < 0) {
		return 0;
	}
	else {
		if (m > 1) {
			plus_numbers(n, multi_numbers(n, m - 1));
		}
		else if (m == 1) {
			return n;
		}
		else {
			return 0;
		}
	}
}

int power_numbers(int n, int m)
{
	if (n < 0 && m < 0) {
		return 0;
	}
	else {
		if (m != 0) {
			return multi_numbers(n, power_numbers(n, m - 1));
		}
		else {
			return 1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	int n, m;
	cout << "Введите n и m: ";
	cin >> n >> m;
	int sum = plus_numbers(n, m);
	cout << "Сумма равна: " << sum << endl;
	int diff = minus_numbers(n, m);
	cout << "Разность равна: " << diff << endl;
	int multi = multi_numbers(n, m);
	cout << "Произведение равно: " << multi << endl;
	int power = power_numbers(n, m);
	cout << "Возведение n в m равно: " << power << endl;
	return 0;
}
