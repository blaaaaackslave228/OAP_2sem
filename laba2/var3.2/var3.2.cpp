#define _CRT_SECURE_NO_DEPRECATE //����������� �������� (��� ��� � ���� ��������� ������ �������� �� ������)
//����������� ���������
#include <iostream>
#include <stdio.h>
using namespace std;//����� �� ������ ������ ��� std
int main()//��������� ������� �������
{
	setlocale(LC_ALL, "RU");//���������� ���������
	int a, b, c;//�������������� ���������� ����� ������ A, B, C
	//��������� ����� �, B, C, D � ��������� ����� �� �� ������� ������
	FILE* fileA = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/A.txt", "r");
	if (fileA == NULL) {
		printf("�� ������� ������� ���� A.txt\n");
	}
	else {
		printf("���� A.txt ������� ������\n");
	}
	FILE* fileB = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/B.txt", "r");
	if (fileB == NULL) {
		printf("�� ������� ������� ���� B.txt\n");
	}
	else {
		printf("���� B.txt ������� ������\n");
	}
	FILE* fileC = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/C.txt", "r");
	if (fileC == NULL) {
		printf("�� ������� ������� ���� C.txt\n");
	}
	else {
		printf("���� C.txt ������� ������\n");
	}
	FILE* fileD = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/D.txt", "w");
	if (fileD == NULL) {
		printf("�� ������� ������� ���� D.txt\n");
	}
	else {
		printf("���� D.txt ������� ������\n");
	}
	//� ������� ����� ��������� ������ ����� ������ A, B, C ����� ����� ���������� �� ���, ��� ������� ������� ������ 
	while (true) {
		int readA = fscanf(fileA, "%d", &a);
		int readB = fscanf(fileB, "%d", &b);
		int readC = fscanf(fileC, "%d", &c);
		if (readA == EOF || readB == EOF || readC == EOF) {
			break;
		}
		fprintf(fileD, "%d %d %d ", a, b, c);//������� ����� � ��������� ������� � ����� D
	}
	//��������� �����
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	fclose(fileD);
	printf("�������� � ��������� ������� �������� � ���� D.txt\n");//������� ��������� �� �������� ���������� �������
	return 0;
}
