#define _CRT_SECURE_NO_DEPRECATE //����������� �������� (��� ��� � ���� ��������� ������ �������� �� ������)
//����������� ���������
#include <iostream>
#include <stdio.h>
using namespace std;//����� �� ������ ������ ��� std
int main()//��������� ������� �������
{
	setlocale(LC_ALL, "RU");//���������� ���������
	//��������� ����� � ��������� ����������� �� ��� ������
	FILE* fileA = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/fileA.txt", "r");
	if (fileA == NULL) {
		printf("�� ������� ������� ���� fileA.txt\n");
	}
	else {
		printf("���� fileA.txt ������� ������\n");
	}
	FILE* fileB = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/fileB.txt", "w");
	if (fileB == NULL) {
		printf("�� ������� ������� ���� fileB.txt\n");
	}
	else {
		printf("���� fileB.txt ������� ������\n");
	}
	//�������������� ������ �������, � ������� �������� ���� ��������
	int n;
	//��������� ���� � ��������� ������ ����� ������ ������� �����
	fscanf(fileA, "%d", &n);
	double element;
	int i = 0, j = 0;
	while (i < n) {
		while (j < n) {
			fscanf(fileA, "%lf", &element);
			if (element > 0) {
				fprintf(fileB, "%lf ", element);
			}
			j++;
		}
		fprintf(fileB, "\n");//������� �������� � ����� ����, ������ ������� ������
		j = 0;
		i++;
	}
	//��������� �����
	fclose(fileA);
	fclose(fileB);
	printf("������������� �������� ���������� � ���� fileB.txt\n");//��������� �� �������� ���������� ������
	return 0;//���������� ���������
}
