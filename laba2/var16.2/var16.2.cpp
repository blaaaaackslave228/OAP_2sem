//����������� ���������, ��������, ������������ ����
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
using namespace std;
int main()//��������� ������� �������
{
	setlocale(LC_ALL, "RU");//���������� ���������
	//���������, ����� �� ������� �����
	FILE* file1 = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/file1.txt", "r");
	if (file1 == NULL) {
		printf("�� ������� ������� ���� file1.txt\n");
		return 1;
	}
	else {
		printf("���� file1.txt ������� ������\n");
	}
	FILE* file2 = fopen("/�����/2 ���/����/����/laba2/����� ��� 18��/file2.txt", "w");
	if (file2 == NULL) {
		printf("�� ������� ������� ���� file2.txt\n");
		return 1;
	}
	else {
		printf("���� file2.txt ������� ������\n");
	}
	//�������������� ���������� ��������, ��������� ������
	int num;
	int count = 0;
	bool positive = true;//���������� ���� ��� ����������� ������������� � ������������� ��������� �����
	//� ������� ����� ������������ ��������, � ����� ���������� ������ ����� ���, ��� ������� ������� ������
	while (fscanf(file1, "%d", &num) != EOF) {
		if ((count % 10 == 0) && (count != 0)) {
			positive = !positive;
		}
		if ((positive && num > 0) || (positive && num < 0)) {
			fprintf(file2, "%d ", num);
			count++;
		}
	}
	//��������� �����
	fclose(file1);
	fclose(file2);
	printf("����� �� ����� file1.txt ���������� � ���� file2.txt\n");//����� ������� �� �������� ���������� ���������
	return 0;//��������� ���������
}
