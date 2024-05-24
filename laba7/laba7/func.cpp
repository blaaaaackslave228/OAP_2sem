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

void FirstElement(Stack*& myStk, int number)
{
    Stack* current = myStk, * temp = nullptr, * pointer = nullptr;
    while (current != nullptr) {
        if (current->data > number) {
            if (temp != nullptr) {
                temp->next = current->next;
                delete current;
            }
            else {
                pointer = current;
                current = current->next;
                delete pointer;
                myStk = current;
            }
            break;
        }
        temp = current;
        current = current->next;
    }
    cout << "Таких элементов нет в стеке." << endl;
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
    ofstream fileone("D:/Денис/2 сем/оаип/лабы/files/lab7.7.txt");
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
    ifstream filetwo("D:/Денис/2 сем/оаип/лабы/files/lab7.7.txt");

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