//подключение макросов, библиотек и пространства имен
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
using namespace std;
int main()//объявляем главную функцию
{
	setlocale(LC_ALL, "RU");//подключаем кириллицу
	//проверяем, можно ли открыть файлы
	FILE* fileA = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/fileA1.txt", "r");
	if (fileA == NULL) {
		printf("Не удалось открыть файл fileA1.txt\n");
	}
	else {
		printf("Файл fileA1.txt успешно открыт\n");
	}
	FILE* fileB = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/fileB1.txt", "r");
	if (fileB == NULL) {
		printf("Не удалось открыть файл fileB1.txt\n");
	}
	else {
		printf("Файл fileB1.txt успешно открыт\n");
	}
	FILE* fileC = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/fileC1.txt", "w");
	if (fileC == NULL) {
		printf("Не удалось открыть файл fileC1.txt\n");
	}
	else {
		printf("Файл fileC1.txt успешно открыт\n");
	}
	//объявляем переменные элементов первых двух файлов и используем цикл для суммирования элементов файлов A и B
	int numA, numB;
	while (fscanf(fileA, "%d", &numA) != EOF && fscanf(fileB, "%d", &numB) != EOF) {
		fprintf(fileC, "%d ", numA + numB);//выводим сумму
	}
	//закрываем файлы
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	printf("Сумма элементов файлов fileA1 и fileB1 записана в файл fileC1.txt\n");//вывод надписи об успешном выполнении программы
	return 0;//завершаем программу
}
