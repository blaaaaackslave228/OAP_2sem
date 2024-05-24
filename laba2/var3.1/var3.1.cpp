#define _CRT_SECURE_NO_DEPRECATE //����������� �������� (��� ��� � ���� ��������� ������ �������� �� ������)
//����������� ���������
#include <iostream>
#include <stdio.h>
using namespace std;//����� �� ������ ������ ��� std
int main()//��������� ������� �������
{
	setlocale(LC_ALL, "RU");//���������� ���������
	//��������� ����� � ��������� ����� �� �� ������� ������
	FILE* fileA = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/A1.txt", "r");
	if (fileA == NULL) {
		printf("�� ������� ������� ���� A1.txt\n");
		return 1;
	}
	else {
		printf("���� A1.txt ������� ������\n");
	}
	FILE* fileB = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/B1.txt", "w");
	if (fileB == NULL) {
		printf("�� ������� ������� ���� B1.txt\n");
		return 1;
	}
	else {
		printf("���� B1.txt ������� ������\n");
	}
	//��������� ������ ������� � �����
	int n;
	fscanf(fileA, "%d", &n);
	//�������� ������������� �������
	double** matrix = new double* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n];
	}
	//������ �������� ������� �� �����
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fscanf(fileA, "%lf", &matrix[i][j]);
		}
	}
	//���������� ����������������� ������� � ����� ����
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fprintf(fileB, "%lf ", matrix[j][i]);
		}
		fprintf(fileB, "\n");
	}
	//������� ������������ ������ �� ������
	for (int i = 0; i < n; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	//��������� �����
	fclose(fileA);
	fclose(fileB);
	printf("����������������� ������� �������� � ���� B1.txt\n");//������� ��������� �� �������� ���������� �������
	return 0;
}
