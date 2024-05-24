#include<iostream> 
using namespace std;

struct Number
{
    int info;
    Number* next;
};

void Create(Number** begin, Number** end, int p); 
void View(Number* begin);                         
void SortQueues(Number* begin, Number** positive, Number** negative, Number** zero);
void DeleteFirst(Number** begin);

int main()
{
    setlocale(LC_ALL, "RU");
    Number* begin = NULL, * end, * t;
    Number* positive = nullptr, * negative = nullptr, * zero = nullptr;
    t = new Number;
    int size, p, choice;
    while (true) {
        cout << "�������� �������: " << endl;
        cout << "1 - ���� �����." << endl;
        cout << "2 - ����� �����." << endl;
        cout << "3 - �������� �����." << endl;
        cout << "4 - ������������� �� ��������." << endl;
        cout << "5 - �����." << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������� ������ �������: ";
            cin >> size;

            cout << "������� �����: ";
            cin >> p;

            t->info = p;
            t->next = NULL;
            begin = end = t;

            for (int i = 1; i < size; i++)
            {
                cout << "������� �����: ";
                cin >> p;
                Create(&begin, &end, p);
            }
            cout << endl;
            break;
        case 2:
            cout << "\n�������� �������: \n";
            if (begin == NULL)
                cout << "��� ���������" << endl;
            else
                View(begin);
            cout << endl;
            break;
        case 3:
            DeleteFirst(&begin);
            cout << endl;
            break;
        case 4:
            SortQueues(begin, &positive, &negative, &zero);

            cout << "\n������������� �����: \n";
            View(positive);

            cout << "\n������������� �����: \n";
            View(negative);

            cout << "\n������� �����: \n";
            View(zero);
            cout << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "�������� �����." << endl;
            break;
        }
    }
    return 0;
}

void Create(Number** begin, Number** end, int p)
{
    Number* t = new Number;
    t->info = p;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        (*end)->next = t;
        *end = t;
    }
}

void View(Number* begin)
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "������� �����\n";
        return;
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << endl;
            t = t->next;
        }
    }
}

void SortQueues(Number* begin, Number** positive, Number** negative, Number** zero)
{
    Number* current = begin;
    Number* end_positive = nullptr;
    Number* end_negative = nullptr;
    Number* end_zero = nullptr;
    while (current != nullptr)
    {
        if (current->info > 0)
            Create(positive, &end_positive, current->info);
        else if (current->info < 0)
            Create(negative, &end_negative, current->info);
        else
            Create(zero, &end_zero, current->info);

        current = current->next;
    }
}

void DeleteFirst(Number** begin)
{
    if (*begin == NULL)
    {
        cout << "������� �����\n";
        return;
    }
    else
    {
        Number* temp = *begin;
        *begin = (*begin)->next;
        delete temp;
    }
}

