#include <iostream>

using namespace std;

struct Number
{
	double info;
	Number* next;
};

void Create(Number** begin, Number** end, double p);
void View(Number* begin);
void SearchMaxElement(Number** begin);

int main()
{
	setlocale(LC_ALL, "RU");
	Number* begin = NULL, * end, * t;
	t = new Number;
	int size;
	double p;
	cout << "Введите размер очереди: ";
	cin >> size;
	cout << "Введите число: ";
	cin >> p;
	t->info = p;
	t->next = NULL;
	begin = end = t;
	for (int i = 1; i < size; i++) {
		cout << "Введите число: ";
		cin >> p;
		Create(&begin, &end, p);
	}
	cout << endl;
	cout << "Элементы очереди: " << endl;;
	if (begin == NULL) {
		cout << "Нет элементов" << endl;
	}
	else {
		View(begin);
	}
	cout << endl;
	SearchMaxElement(&begin);
	cout << "Очередь после перестановки: " << endl;
	if (begin == NULL) {
		cout << "Нет элементов" << endl;
	}
	else {
		View(begin);
	}
	cout << endl;
	return 0;
}

void Create(Number** begin, Number** end, double p)
{
	Number* t = new Number;
	t->next = NULL;
	if (*begin == NULL) {
		*begin = *end = t;
	}
	else {
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}

void View(Number* begin)
{
	Number* t = begin;
	if (t == NULL) {
		cout << "Очередь пуста." << endl;
		return;
	}
	else{
		while (t != NULL) {
			cout << t->info << endl;
			t = t->next;
		}
	}
}

void SearchMaxElement(Number** begin)
{
	if (*begin == nullptr || (*begin)->next == nullptr) {
		return;
	}

	Number* prevmax = nullptr;
	Number* max = *begin;
	Number* current = (*begin)->next;

	while (current != nullptr) {
		if (current->info > max->info) {
			prevmax = max;
			max = current;
		}
		current = current->next;
	}

	if (prevmax != nullptr) {
		prevmax->next = max->next;
	}
	else {
		*begin = max->next;
	}
	max->next = *begin;
	*begin = max;
}
