#pragma once
struct Stack
{
	int data;     //информационный элемент
	Stack* next;	 //указатель на следующий элемент
};

void Output(Stack*& myStk);
int Pop(Stack*& myStk);
void Push(int x, Stack*& myStk);
void ToFile(Stack*& myStk);
void FromFile(Stack*& myStk);
void Clear(Stack*& myStk);
void Deletes(Stack * &myStk);
