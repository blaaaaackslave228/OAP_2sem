#include <iostream>
#include <fstream>
#include "func.h"
using namespace std;

void Output(Stack*& myStk)
{
    if (myStk == nullptr) {
        cout << "���� ����." << endl;
    }
    else {
        cout << "����: " << endl;
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
    cout << "����� ��������� ��� � �����." << endl;
}

void Push(int x, Stack*& myStk)   //���������� �������� � � ����	
{
    Stack* e = new Stack;    //��������� ������ ��� ������ ��������
    e->data = x;             //������ �������� x � ���� data 
    e->next = myStk;         //������� ������� �� ��������� ������� 
    myStk = e;               //����� ������� �� ������� ������
}

void ToFile(Stack*& myStk)
{
    ofstream fileone("D:/�����/2 ���/����/����/files/lab7.7.txt");
    if (!fileone) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    Stack* temp = myStk;
    while (temp != nullptr) {
        fileone << temp->data << ' ';
        temp = temp->next;
    }

    fileone.close();
    cout << "���� ������� �������." << endl;
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
    ifstream filetwo("D:/�����/2 ���/����/����/files/lab7.7.txt");

    if (!filetwo) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    while (filetwo >> number) {
        Push(number, myStk);
    }

    filetwo.close();
    cout << "���� ������� ��������." << endl;
}

void Clear(Stack*& myStk)
{
    while (myStk) {
        Stack* temp = myStk;
        myStk = myStk->next;
        delete temp;
    }
}