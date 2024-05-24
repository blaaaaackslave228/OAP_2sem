#define _CRT_SECURE_NO_DEPRECATE //подключение макросов (без них у меня программа просто сообщала об ошибке)
//подключение библиотек
#include <iostream>
#include <stdio.h>
using namespace std;//чтобы не писать каждый раз std
int main()//объявляем главную функцию
{
	setlocale(LC_ALL, "RU");//подключаем кириллицу
	int a, b, c, max1;//инициализируем переменные чисел файлов A, B, C и максимальных чисел для файла D
	//открываем файлы А, B, C, D и проверяем можно ли их открыть вообще
	FILE* fileA = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/NameA.txt", "r");
	if (fileA == NULL) {
		printf("Не удалось открыть файл NameA.txt\n");
	}
	else {
		printf("Файл NameA.txt успешно открыт\n");
	}
	FILE* fileB = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/NameB.txt", "r");
	if (fileB == NULL) {
		printf("Не удалось открыть файл NameB.txt\n");
	}
	else {
		printf("Файл NameB.txt успешно открыт\n");
	}
	FILE* fileC = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/NameC.txt", "r");
	if (fileC == NULL) {
		printf("Не удалось открыть файл NameC.txt\n");
	}
	else {
		printf("Файл NameC.txt успешно открыт\n");
	}
	FILE* fileD = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/NameD.txt", "w");
	if (fileD == NULL) {
		printf("Не удалось открыть файл NameD.txt\n");
	}
	else {
		printf("Файл NameD.txt успешно открыт\n");
	}
	//с помощью цикла проверяем каждое число файлов A, B, C чтобы затем максимальные значения записать в файл D
	while (fscanf(fileA, "%d", &a) != EOF && fscanf(fileB, "%d", &b) != EOF && fscanf(fileC, "%d", &c) != EOF) {
		max1 = max(max(a, b), c);
		fprintf(fileD, "%d ", max1);//выводим максимальные числа
	}
	//закрываем файлы
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	fclose(fileD);
	printf("Максимальные значения записаны в файл NameD.txt\n");//выводим сообщение об успешном выполнении задания
	return 0;
}
