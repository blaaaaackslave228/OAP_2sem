#define _CRT_SECURE_NO_DEPRECATE //����������� �������� (��� ��� � ���� ��������� ������ �������� �� ������)
//����������� ���������
#include <iostream>
#include <stdio.h>
using namespace std;//����� �� ������ ������ ��� std
int main()//��������� ������� �������
{
	setlocale(LC_ALL, "RU");//���������� ���������
	int a, b, c, max1;//�������������� ���������� ����� ������ A, B, C � ������������ ����� ��� ����� D
	//��������� ����� �, B, C, D � ��������� ����� �� �� ������� ������
	FILE* fileA = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/NameA.txt", "r");
	if (fileA == NULL) {
		printf("�� ������� ������� ���� NameA.txt\n");
	}
	else {
		printf("���� NameA.txt ������� ������\n");
	}
	FILE* fileB = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/NameB.txt", "r");
	if (fileB == NULL) {
		printf("�� ������� ������� ���� NameB.txt\n");
	}
	else {
		printf("���� NameB.txt ������� ������\n");
	}
	FILE* fileC = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/NameC.txt", "r");
	if (fileC == NULL) {
		printf("�� ������� ������� ���� NameC.txt\n");
	}
	else {
		printf("���� NameC.txt ������� ������\n");
	}
	FILE* fileD = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/NameD.txt", "w");
	if (fileD == NULL) {
		printf("�� ������� ������� ���� NameD.txt\n");
	}
	else {
		printf("���� NameD.txt ������� ������\n");
	}
	//� ������� ����� ��������� ������ ����� ������ A, B, C ����� ����� ������������ �������� �������� � ���� D
	while (fscanf(fileA, "%d", &a) != EOF && fscanf(fileB, "%d", &b) != EOF && fscanf(fileC, "%d", &c) != EOF) {
		max1 = max(max(a, b), c);
		fprintf(fileD, "%d ", max1);//������� ������������ �����
	}
	//��������� �����
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	fclose(fileD);
	printf("������������ �������� �������� � ���� NameD.txt\n");//������� ��������� �� �������� ���������� �������
	return 0;
}
