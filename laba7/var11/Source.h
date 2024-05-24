#pragma once
struct Stack
{
	int data;     //�������������� �������
	Stack* next;	 //��������� �� ��������� �������
};

void Output(Stack*& myStk);
int Pop(Stack*& myStk);
void Push(int x, Stack*& myStk);
void ToFile(Stack*& myStk);
void FromFile(Stack*& myStk);
void Clear(Stack*& myStk);
void Deletes(Stack * &myStk);
