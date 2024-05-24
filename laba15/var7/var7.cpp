#include <iostream>

using namespace std;

int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm], buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};

void insOrd(int m[], int sm, int em, int e)
{
	int buf, i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}
int* sortMerge(int m[], int lm, int sm = 0)
{
	if (lm > 1)
	{
		sortMerge(m, lm / 2, sm);
		sortMerge(m, lm - lm / 2, sm + lm / 2);
		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}

int main()
{
	setlocale(LC_ALL, "RU");

	int N;
	cout << "Введите размер массивов: ";
	cin >> N;

	int* masA = new int[N];
	cout << "Заполните массив A: ";
	for (int i = 0; i < N; i++) {
		cin >> masA[i];
	}
	
	int* masB = new int[N];
	cout << "Заполните массив B: ";
	for (int i = 0; i < N; i++) {
		cin >> masB[i];
	}

	cout << "Массив A: ";
	for (int i = 0; i < N; i++) {
		cout << masA[i] << " ";
	}
	cout << endl;

	cout << "Массив B: ";
	for (int i = 0; i < N; i++) {
		cout << masB[i] << " ";
	}
	cout << endl;

	int* masC = new int [N];
	int count = 0;

	for (int i = 0; i < N; i++) {
		if (masA[i] % 2 == 0) {
			masC[count++] = masA[i];
		}
	}

	for (int i = 0; i < N; i++) {
		if (masB[i] % 2 != 0) {
			masC[count++] = masB[i];
		}
	}

	cout << "Массив C: ";
	for (int i = 0; i < count; i++) {
		cout << masC[i] << " ";
	}
	cout << endl;

	sortHoar(masC, 0, count - 1);

	cout << "Отсортированный массив С в порядке убывания методом Хоара: ";
	for (int i = 0; i < count; i++)
	{
		cout << masC[i] << " ";
	}
	cout << endl;

	sortMerge(masC, 0, count - 1);

	cout << "Отсортированный массив C в порядке убывания сортировкой слияния: ";
	for (int i = 0; i < count; i++) {
		cout << masC[i] << " ";
	}
	cout << endl;

	delete[] masA;
	delete[] masB;
	delete[] masC;
	return 0;
}