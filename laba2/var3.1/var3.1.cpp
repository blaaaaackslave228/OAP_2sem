#define _CRT_SECURE_NO_DEPRECATE //подключение макросов (без них у меня программа просто сообщала об ошибке)
//подключение библиотек
#include <iostream>
#include <stdio.h>
using namespace std;//чтобы не писать каждый раз std
int main()//объявляем главную функцию
{
	setlocale(LC_ALL, "RU");//подключаем кириллицу
	//открываем файлы и проверяем можно ли их открыть вообще
	FILE* fileA = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/A1.txt", "r");
	if (fileA == NULL) {
		printf("Не удалось открыть файл A1.txt\n");
		return 1;
	}
	else {
		printf("Файл A1.txt успешно открыт\n");
	}
	FILE* fileB = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/B1.txt", "w");
	if (fileB == NULL) {
		printf("Не удалось открыть файл B1.txt\n");
		return 1;
	}
	else {
		printf("Файл B1.txt успешно открыт\n");
	}
	//считываем размер матрицы и файла
	int n;
	fscanf(fileA, "%d", &n);
	//создание динамического массива
	double** matrix = new double* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new double[n];
	}
	//читаем элементы матрицы из файла
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fscanf(fileA, "%lf", &matrix[i][j]);
		}
	}
	//записываем транспонированную матрицу в новый файл
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fprintf(fileB, "%lf ", matrix[j][i]);
		}
		fprintf(fileB, "\n");
	}
	//удаляем динамический массив из памяти
	for (int i = 0; i < n; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	//закрываем файлы
	fclose(fileA);
	fclose(fileB);
	printf("Транспонированная матрица записана в файл B1.txt\n");//выводим сообщение об успешном выполнении задания
	return 0;
}
