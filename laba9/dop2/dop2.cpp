#include "List1.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

Address* setElement()
{
	Address* temp = new Address();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� �������: ";
	cin >> temp->surname;
	cout << "������� ���: ";
	cin >> temp->name;
	cout << "������� ��������: ";
	cin >> temp->parentname;
	cout << "������� ���� ��������: " << endl;
	cout << "������� ����: ";
	cin >> temp->day;
	cout << "������� �����: ";
	cin >> temp->month; 
	cout << "������� ���: ";
	cin >> temp->year;
	cout << "������� ����� �����: ";
	cin >> temp->course;
	cout << "������� ����� ������: ";
	cin >> temp->group;
	cout << "������� ������ �� ���������: " << endl;
	cout << "����������: ";
	cin >> temp->math;
	cout << "����: ";
	cin >> temp->OAIP;
	cout << "���������� ����: ";
	cin >> temp->English;
	cout << "���: ";
	cin >> temp->Kpo;
	cout << "����: ";
	cin >> temp->Aisd;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		cout << "--------------------------------------------------" << endl;
		cout << "�������: " << t->surname << endl;
		cout << "���: " << t->name << endl;
		cout << "��������: " << t->parentname << endl;
		cout << "���� ��������: " << t->day << "." << t->month << "." << t->year << endl;
		cout << "����: " << t->course << endl;
		cout << "������: " << t->group << endl;
		cout << "������: " << endl;
		cout << "����������: " << t->math << endl;
		cout << "����: " << t->OAIP << endl;
		cout << "���������� ����: " << t->English << endl;
		cout << "���: " << t->Kpo << endl;
		cout << "����: " << t->Aisd << endl;
		t = t->next;
	}
}

void outputFirstCourse(Address** phead, Address** plast)
{
	int i = 0;
	bool found = false;
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	cout << "---------------------�������� 1 �����-------------------" << endl;
	if (strcmp(t->surname, (t->next)->surname) > 0)
	{
		t = t->next;
		t->next = t->prev;
		t->prev = t;
	}
	while (i != 2)
	{
		if (t->course == 1)
		{
			found = true;
			cout << "--------------------------------------------------" << endl;
			cout << "�������: " << t->surname << endl;
			cout << "���: " << t->name << endl;
			cout << "��������: " << t->parentname << endl;
			cout << "���� ��������: " << t->day << "." << t->month << "." << t->year << endl;
			cout << "����: " << t->course << endl;
			cout << "������: " << t->group << endl;
			cout << "������: " << endl;
			cout << "����������: " << t->math << endl;
			cout << "����: " << t->OAIP << endl;
			cout << "���������� ����: " << t->English << endl;
			cout << "���: " << t->Kpo << endl;
			cout << "����: " << t->Aisd << endl;
			t = t->next;
		}
		else
		{
			t = t->next;
		}
		i++;
	}
	if (!found) {
		cout << "�������� ������� ����� �� �������." << endl;
	}
}

void outputSecondCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
		return;
	}

	bool swapped;
	Address* temp;
	do
	{
		swapped = false;
		t = *phead;
		while (t->next != NULL)
		{
			if (strcmp(t->surname, t->next->surname) > 0)
			{
				temp = t->next;
				if (t->prev != NULL)
					t->prev->next = temp;
				if (temp->next != NULL)
					temp->next->prev = t;
				
				t->next = temp->next;
				temp->prev = t->prev;
				t->prev = temp;
				temp->next = t;

				if (*phead == t)
					*phead = temp;
				if (*plast == temp)
					*plast = t;

				swapped = true;
			}
			else
				t = t->next;
		}
	} while (swapped);

	t = *phead;
	bool found = false; 
	while (t)
	{
		if (t->course == 2)
		{
			found = true; 
			cout << "--------------------------------------------------" << endl;
			cout << "�������: " << t->surname << endl;
			cout << "���: " << t->name << endl;
			cout << "��������: " << t->parentname << endl;
			cout << "���� ��������: " << t->day << "." << t->month << "." << t->year << endl;
			cout << "����: " << t->course << endl;
			cout << "������: " << t->group << endl;
			cout << "������: " << endl;
			cout << "����������: " << t->math << endl;
			cout << "����: " << t->OAIP << endl;
			cout << "���������� ����: " << t->English << endl;
			cout << "���: " << t->Kpo << endl;
			cout << "����: " << t->Aisd << endl;
		}
		t = t->next;
	}
	if (!found) {
		cout << "�������� ������� ����� �� �������." << endl;
	}
}

void outputThirdCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
		return;
	}

	bool swapped;
	Address* temp;
	do
	{
		swapped = false;
		t = *phead;
		while (t->next != NULL)
		{
			if (strcmp(t->surname, t->next->surname) > 0)
			{
				temp = t->next;
				if (t->prev != NULL)
					t->prev->next = temp;
				if (temp->next != NULL)
					temp->next->prev = t;

				t->next = temp->next;
				temp->prev = t->prev;
				t->prev = temp;
				temp->next = t;

				if (*phead == t)
					*phead = temp;
				if (*plast == temp)
					*plast = t;

				swapped = true;
			}
			else
				t = t->next;
		}
	} while (swapped);

	t = *phead;
	bool found = false;
	while (t)
	{
		if (t->course == 3)
		{
			found = true;
			cout << "--------------------------------------------------" << endl;
			cout << "�������: " << t->surname << endl;
			cout << "���: " << t->name << endl;
			cout << "��������: " << t->parentname << endl;
			cout << "���� ��������: " << t->day << "." << t->month << "." << t->year << endl;
			cout << "����: " << t->course << endl;
			cout << "������: " << t->group << endl;
			cout << "������: " << endl;
			cout << "����������: " << t->math << endl;
			cout << "����: " << t->OAIP << endl;
			cout << "���������� ����: " << t->English << endl;
			cout << "���: " << t->Kpo << endl;
			cout << "����: " << t->Aisd << endl;
		}
		t = t->next;
	}
	if (!found) {
		cout << "�������� �������� ����� �� �������." << endl;
	}
}

void outputFourthCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
		return;
	}

	bool swapped;
	Address* temp;
	do
	{
		swapped = false;
		t = *phead;
		while (t->next != NULL)
		{
			if (strcmp(t->surname, t->next->surname) > 0)
			{
				temp = t->next;
				if (t->prev != NULL)
					t->prev->next = temp;
				if (temp->next != NULL)
					temp->next->prev = t;

				t->next = temp->next;
				temp->prev = t->prev;
				t->prev = temp;
				temp->next = t;

				if (*phead == t)
					*phead = temp;
				if (*plast == temp)
					*plast = t;

				swapped = true;
			}
			else
				t = t->next;
		}
	} while (swapped);

	t = *phead;
	bool found = false;
	while (t)
	{
		if (t->course == 4)
		{
			found = true;
			cout << "--------------------------------------------------" << endl;
			cout << "�������: " << t->surname << endl;
			cout << "���: " << t->name << endl;
			cout << "��������: " << t->parentname << endl;
			cout << "���� ��������: " << t->day << "." << t->month << "." << t->year << endl;
			cout << "����: " << t->course << endl;
			cout << "������: " << t->group << endl;
			cout << "������: " << endl;
			cout << "����������: " << t->math << endl;
			cout << "����: " << t->OAIP << endl;
			cout << "���������� ����: " << t->English << endl;
			cout << "���: " << t->Kpo << endl;
			cout << "����: " << t->Aisd << endl;
		}
		t = t->next;
	}
	if (!found) {
		cout << "�������� ���������� ����� �� �������." << endl;
	}
}

void studentOld(Address** phead, Address** plast)
{
	int old = 0;
	Address* tmp = *phead;
	old = tmp->year;
	while (tmp)
	{

		if (tmp->year < old)
		{
			old = tmp->year;
		}
		tmp = tmp->next;

	}
	Address* t = *phead;
	while (t)
	{
		if (t->year == old)
		{
			cout << "������� �������: " << t->surname << endl;
		}
		t = t->next;
	}

}

void studentYoung(Address** phead, Address** plast)
{
	int young = 0;
	Address* tmp = *phead;
	young = tmp->year;
	while (tmp)
	{

		if (tmp->year > young)
		{
			young = tmp->year;
		}
		tmp = tmp->next;

	}
	Address* t = *phead;
	while (t)
	{
		if (t->year == young)
		{
			cout << "������� �������: " << t->surname << endl;
		}
		t = t->next;
	}
}

void average(Address** phead, Address** plast)
{
	float average1 = 0, average2 = 0, average3 = 0;
	Address* t = *phead;
	while (t)
	{
		average1 = (t->English + t->math + t->Aisd + t->Kpo + t->OAIP) / 5;
		cout << "�������: " << t->surname << " " << " ������� ����: " << average1 << endl;
		t = t->next;
		average2 = (t->English + t->math + t->Aisd + t->Kpo + t->OAIP) / 5;
		cout << "�������: " << t->surname << " " << " ������� ����: " << average2 << endl;
		t = t->next;

	}
	Address* emp = *phead;
	while (emp)
	{
		if (average1 >= average2 && average1 >= average3)
		{
			cout << "������ �������: " << emp->surname << endl;
		}
		emp = emp->next;
		if (average2 >= average1 && average2 >= average3)
		{
			cout << "������ �������: " << emp->surname << endl;
		}
		emp = emp->next;


	}
}

int main()
{
	Address* head = NULL;
	Address* last = NULL;
	SetConsoleCP(1251);
	setlocale(LC_CTYPE, "Rus");
	int choice;
	cout << endl;
	cout << "1. ���� ��������" << endl;
	cout << "2. ������� �������" << endl;
	cout << "3. ������� �������" << endl;
	cout << "4. ������ ������" << endl;
	cout << "5. ����� ������" << endl;
	cout << "6. 1 ����" << endl;
	cout << "7. 2 ����" << endl;
	cout << "8. 3 ����" << endl;
	cout << "9. 4 ����" << endl;
	cout << "10. �����" << endl;
	cout << endl;
	for (;;)
	{
		cout << "��� �����: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert(setElement(), &head, &last);
			break;
		case 2: studentOld(&head, &last);
			break;
		case 3: studentYoung(&head, &last);
			break;
		case 4: average(&head, &last);
			break;
		case 5: outputList(&head, &last);
			break;
		case 6: outputFirstCourse(&head, &last);
			break;
		case 7:
			outputSecondCourse(&head, &last);
			break;
		case 8:
			outputThirdCourse(&head, &last);
			break;
		case 9:
			outputFourthCourse(&head, &last);
			break;
		case 10: exit(0);
		default: exit(1);
		}
	}
	return 0;
}