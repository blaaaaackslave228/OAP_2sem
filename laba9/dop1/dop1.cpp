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
		cout << "������ ��������� ������" << endl;
	}
	cout << "������� ����� �����: ";
	cin >> temp->number_fligts;
	cout << "������� ����� ��������: ";
	cin >> temp->place;
	cin.ignore();
	cout << "������� ����� ������: ";
	getline(cin, temp->time);
	cout << "������� ��������� ������: ";
	cin >> temp->price_ticket;
	cin.ignore();
	cout << "������� ���� ������: ";
	getline(cin, temp->date);
	cout << "������� ���������� ���������� ����: ";
	cin >> temp->number_sits;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(FLIGHTS** phead, FLIGHTS** plast)
{
	FLIGHTS* t = *phead;
	if (t == NULL) {
		cout << "������ ����" << endl;
	}
	while (t) {
		cout << "���������� � ���������: " << endl;
		cout << "����� �����: " << t->number_fligts << endl;
		cout << "����� ��������: " << t->place << endl;
		cout << "����� ������: " << t->time << endl;
		cout << "���� ������: " << t->date << endl;
		cout << "�������� ������: " << t->price_ticket << endl;
		cout << "���������� ���������� ����: " << t->number_sits << endl;
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
		cout << "������ ����� �������� �� �������" << endl;
	}
	else {
		cout << "���������� � ���������: " << endl;
		cout << "����� �����: " << t->number_fligts << endl;
		cout << "����� ��������: " << t->place << endl;
		cout << "����� ������: " << t->time << endl;
		cout << "���� ������: " << t->date << endl;
		cout << "�������� ������: " << t->price_ticket << endl;
		cout << "���������� ���������� ����: " << t->number_sits << endl;
		cout << endl;
	}
	cout << endl;
}

void countList(FLIGHTS** phead, FLIGHTS** plast)
{
	int count = 0;
	FLIGHTS* temp = *phead;
	if (temp == NULL) {
		cout << "������ ����" << endl;
	}
	else {
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		cout << "���������� ��������� � ������: " << count << endl;
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
	cout << "1. ���� ���������." << endl;
	cout << "2. ����� ���������." << endl;
	cout << "3. ����� ��������." << endl;
	cout << "4. ������� ����� ���������." << endl;
	cout << "5. �������� ������." << endl;
	cout << "6. �����." << endl;
	cout << endl;
	for (;;) {
		cout << "�������� ��������: ";
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
			cout << "������� ����� ��������: ";
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
