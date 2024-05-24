#include <iostream>
#include <fstream>
#include "func.h"
using namespace std;

void Output(Stack*& myStk)
{
    if (myStk == nullptr) {
        cout << "Стек пуст." << endl;
    }
    else {
        cout << "Стек: " << endl;
        Stack* temp = myStk;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

void DeleteNegative(Stack*& myStk)
{
    Stack* current = myStk;
    Stack* previous = nullptr;

    while (current != nullptr) {
        if (current->data < 0) {
            if (previous == nullptr) {
                myStk = current->next;
                delete current;
                return;
            }
            else {
                previous->next = current->next;
                delete current;
                return;
            }
        }
        previous = current;
        current = current->next;
    }
    cout << "Отрицательные элементы отсутствуют в стеке." << endl;
}


void Push(int x, Stack*& myStk)   //Добавление элемента х в стек	
{
    Stack* e = new Stack;    //выделение памяти для нового элемента
    e->data = x;             //запись элемента x в поле data 
    e->next = myStk;         //перенос вершины на следующий элемент 
    myStk = e;               //сдвиг вершины на позицию вперед
}

void ToFile(Stack*& myStk)
{
    ofstream fileone("D:/Денис/2 сем/оаип/лабы/files/lab7.2.txt");
    if (!fileone) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    Stack* temp = myStk;
    while (temp != nullptr) {
        fileone << temp->data << ' ';
        temp = temp->next;
    }

    fileone.close();
    cout << "Стек успешно записан." << endl;
}

void FromFile(Stack*& myStk)
{
    while (myStk) {
        Stack* temp = myStk;
        myStk = myStk->next;
        delete temp;
    }

    char buf[50];
    int number;
    ifstream filetwo("D:/Денис/2 сем/оаип/лабы/files/lab7.2.txt");
    if (!filetwo) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    while (filetwo >> number) {
        Push(number, myStk);
    }

    filetwo.close();
    cout << "Стек успешно прочитан." << endl;
}

void Clear(Stack*& myStk)
{
    while (myStk) {
        Stack* temp = myStk;
        myStk = myStk->next;
        delete temp;
    }
}