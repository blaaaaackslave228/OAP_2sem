#include "list.h"

void insert(FLIGHTS* e, FLIGHTS** phead, FLIGHTS** plast)
{
	FLIGHTS* p = *plast;
	if (*plast == NULL) {
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else {
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

FLIGHTS* setElement()
{
	FLIGHTS* temp = new FLIGHTS();
	if (!temp) {
		cout << "Ошибка выделения памяти" << endl;
	}
	cout << "Введите номер рейса: ";
	cin >> temp->number_fligts;
	cout << "Введите место прибытия: ";
	cin >> temp->place;
	cin.ignore();
	cout << "Введите время вылета: ";
	getline(cin, temp->time);
	cout << "Введите стоимость билета: ";
	cin >> temp->price_ticket;
	cin.ignore();
	cout << "Введите дату вылета: ";
	getline(cin, temp->date);
	cout << "Введите количество посадочных мест: ";
	cin >> temp->number_sits;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(FLIGHTS** phead, FLIGHTS** plast)
{
	FLIGHTS* t = *phead;
	if (t == NULL) {
		cout << "Список пуст" << endl;
	}
	while (t) {
		cout << "Информация о авиарейсе: " << endl;
		cout << "Номер рейса: " << t->number_fligts << endl;
		cout << "Место прибытия: " << t->place << endl;
		cout << "Время вылета: " << t->time << endl;
		cout << "Дата вылета: " << t->date << endl;
		cout << "Стоиость билета: " << t->price_ticket << endl;
		cout << "Количество посадочных мест: " << t->number_sits << endl;
		cout << endl;
		t = t->next;
	}
}

void find(FLIGHTS** phead, char place[NAME_SIZE])
{
	FLIGHTS* t = *phead;
	while (t) {
		if (!strcmp(place, t->place))
			break;
		t = t->next;
	}
	if (!t) {
		cout << "Такого места прибытия не найдено" << endl;
	}
	else {
		cout << "Информация о авиарейсе: " << endl;
		cout << "Номер рейса: " << t->number_fligts << endl;
		cout << "Место прибытия: " << t->place << endl;
		cout << "Время вылета: " << t->time << endl;
		cout << "Дата вылета: " << t->date << endl;
		cout << "Стоиость билета: " << t->price_ticket << endl;
		cout << "Количество посадочных мест: " << t->number_sits << endl;
		cout << endl;
	}
	cout << endl;
}

void countList(FLIGHTS** phead, FLIGHTS** plast)
{
	int count = 0;
	FLIGHTS* temp = *phead;
	if (temp == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		cout << "Количество элементов в списке: " << count << endl;
	}
}

void deleteList(FLIGHTS** phead, FLIGHTS** plast)
{
	FLIGHTS* temp = *phead;
	FLIGHTS* current;
	while (temp != NULL) {
		current = temp->next;
		delete temp;
		temp = current;
	}
	*phead = NULL;
	*phead = NULL;
}

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	FLIGHTS* head = NULL;
	FLIGHTS* last = NULL;
	int choice;
	cout << "1. Ввод элементов." << endl;
	cout << "2. Вывод элементов." << endl;
	cout << "3. Поиск элемента." << endl;
	cout << "4. Подсчет числа элементов." << endl;
	cout << "5. Удаление списка." << endl;
	cout << "6. Выход." << endl;
	cout << endl;
	for (;;) {
		cout << "Выберите действие: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			insert(setElement(), &head, &last);
			cout << endl;
			break;
		case 2:
			outputList(&head, &last);
			cout << endl;
			break;
		case 3: {
			char fname[NAME_SIZE];
			cout << "Введите место прибытия: ";
			cin.ignore();
			cin.getline(fname, NAME_SIZE - 1, '\n');
			find(&head, fname); 
			cout << endl;
			break;
		}
		case 4:
			countList(&head, &last);
			cout << endl;
			break;
		case 5:
			deleteList(&head, &last);
			cout << endl;
			break;
		case 6:
			return 0;
		default:
			return 1;
		}
	}
}
