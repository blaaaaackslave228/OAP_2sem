//����������� ��������, ��������� � ������������ ����
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
using namespace std;
int main()//��������� ������� �������
{
	setlocale(LC_ALL, "RU");//���������� ���������
	//���������, ����� �� ������� �����
	FILE* fileA = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/fileA1.txt", "r");
	if (fileA == NULL) {
		printf("�� ������� ������� ���� fileA1.txt\n");
	}
	else {
		printf("���� fileA1.txt ������� ������\n");
	}
	FILE* fileB = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/fileB1.txt", "r");
	if (fileB == NULL) {
		printf("�� ������� ������� ���� fileB1.txt\n");
	}
	else {
		printf("���� fileB1.txt ������� ������\n");
	}
	FILE* fileC = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/fileC1.txt", "w");
	if (fileC == NULL) {
		printf("�� ������� ������� ���� fileC1.txt\n");
	}
	else {
		printf("���� fileC1.txt ������� ������\n");
	}
	//��������� ���������� ��������� ������ ���� ������ � ���������� ���� ��� ������������ ��������� ������ A � B
	int numA, numB;
	while (fscanf(fileA, "%d", &numA) != EOF && fscanf(fileB, "%d", &numB) != EOF) {
		fprintf(fileC, "%d ", numA + numB);//������� �����
	}
	//��������� �����
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	printf("����� ��������� ������ fileA1 � fileB1 �������� � ���� fileC1.txt\n");//����� ������� �� �������� ���������� ���������
	return 0;//��������� ���������
}
