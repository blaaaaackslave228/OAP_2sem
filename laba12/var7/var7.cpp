#include "heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
void Union(heap::Heap& h1, heap::Heap& h2)
{
    while (h2.size) {
        void* element = h2.extractI(1);
        h1.insert(element);
        h1.heapify(1);
    }
    h2.deleteHeap();
    cout << "Объединение завершено" << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод двух куч на экран" << endl;
		cout << "2 - добавить элемент для первой кучи" << endl;
		cout << "3 - добавить элемент для второй кучи" << endl;
		cout << "4 - удалить максимальный элемент" << endl;
		cout << "5 - удалить i-ый элемент" << endl;
		cout << "6 - удалить минимальный элемент" << endl;
		cout << "7 - объединение двух куч в одну" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            cout << "Первая куча: " << endl;
            h1.scan(0);
            cout << endl;
            cout << "Вторая куча: " << endl;
            h2.scan(0);
            break;
        case 2:
        {
            AAA* a = new AAA;
            cout << "Введите ключ: " << endl;  cin >> k;
            a->x = k;
            h1.insert(a);
            break;
        }
        case 3:
        {
            AAA* a = new AAA;
            cout << "Введите ключ: " << endl;  cin >> k;
            a->x = k;
            h2.insert(a);
            break;
        }
        case 4:
            h1.extractMax();
            h2.extractMax();
            break;
        case 5:
            int i;
            cout << "Введите номер удаляемого элемента: ";
            cin >> i;
            if (h1.extractI(i) && h2.extractI(i)) {
                cout << "Удаление успешно завершено" << endl;
            }
            break;
        case 6:
            h1.extractMin();
            h2.extractMin();
            break;
        case 7:
            Union(h1, h2);
            break;
        default:
            cout << endl << "Введена неверная команда!" << endl;
        }
	} return 0;
}
