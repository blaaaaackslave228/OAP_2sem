#define _CRT_SECURE_NO_DEPRECATE //подключение макросов (без них у меня программа просто сообщала об ошибке)
//подключение библиотек
#include <iostream>
#include <stdio.h>
using namespace std;//чтобы не писать каждый раз std
int main()//объявляем главную функцию
{
	setlocale(LC_ALL, "RU");//подключаем кириллицу
	int a, b, c;//инициализируем переменные чисел файлов A, B, C
	//открываем файлы А, B, C, D и проверяем можно ли их открыть вообще
	FILE* fileA = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/A.txt", "r");
	if (fileA == NULL) {
		printf("Не удалось открыть файл A.txt\n");
	}
	else {
		printf("Файл A.txt успешно открыт\n");
	}
	FILE* fileB = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/B.txt", "r");
	if (fileB == NULL) {
		printf("Не удалось открыть файл B.txt\n");
	}
	else {
		printf("Файл B.txt успешно открыт\n");
	}
	FILE* fileC = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/C.txt", "r");
	if (fileC == NULL) {
		printf("Не удалось открыть файл C.txt\n");
	}
	else {
		printf("Файл C.txt успешно открыт\n");
	}
	FILE* fileD = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/D.txt", "w");
	if (fileD == NULL) {
		printf("Не удалось открыть файл D.txt\n");
	}
	else {
		printf("Файл D.txt успешно открыт\n");
	}
	//с помощью цикла проверяем каждое число файлов A, B, C чтобы затем записываем их так, как требует условие задачи 
	while (true) {
		int readA = fscanf(fileA, "%d", &a);
		int readB = fscanf(fileB, "%d", &b);
		int readC = fscanf(fileC, "%d", &c);
		if (readA == EOF || readB == EOF || readC == EOF) {
			break;
		}
		fprintf(fileD, "%d %d %d ", a, b, c);//выводим числа в указанном порядке в файле D
	}
	//закрываем файлы
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	fclose(fileD);
	printf("Значения в указанном порядке записаны в файл D.txt\n");//выводим сообщение об успешном выполнении задания
	return 0;
}
