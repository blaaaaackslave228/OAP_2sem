#define _CRT_SECURE_NO_DEPRECATE //подключение макросов (без них у меня программа просто сообщала об ошибке)
//подключение библиотек
#include <iostream>
#include <stdio.h>
using namespace std;//чтобы не писать каждый раз std
int main()//объявляем главную функцию
{
	setlocale(LC_ALL, "RU");//подключаем кириллицу
	//открываем файлы и проверяем открываются ли они вообще
	FILE* fileA = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/fileA.txt", "r");
	if (fileA == NULL) {
		printf("Не удалось открыть файл fileA.txt\n");
	}
	else {
		printf("Файл fileA.txt успешно открыт\n");
	}
	FILE* fileB = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/fileB.txt", "w");
	if (fileB == NULL) {
		printf("Не удалось открыть файл fileB.txt\n");
	}
	else {
		printf("Файл fileB.txt успешно открыт\n");
	}
	//инициализируем размер массива, в котором хранятся наши элементы
	int n;
	//открываем файл и проверяем каждое число нашего первого файла
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
		fprintf(fileB, "\n");//выводим элементы в новый файл, следуя условию задачи
		j = 0;
		i++;
	}
	//закрываем файлы
	fclose(fileA);
	fclose(fileB);
	printf("Положительные элементы переписаны в файл fileB.txt\n");//сообщение об успешном выполнении задачи
	return 0;//завершение программы
}
