//подключение библиотек, макросов, пространства имен
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
using namespace std;
int main()//объявляем главную функцию
{
	setlocale(LC_ALL, "RU");//подключаем кириллицу
	//проверяем, можем ли открыть файлы
	FILE* file1 = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/file1.txt", "r");
	if (file1 == NULL) {
		printf("Не удалось открыть файл file1.txt\n");
		return 1;
	}
	else {
		printf("Файл file1.txt успешно открыт\n");
	}
	FILE* file2 = fopen("/Денис/2 сем/оаип/лабы/laba2/Файлы для 18лр/file2.txt", "w");
	if (file2 == NULL) {
		printf("Не удалось открыть файл file2.txt\n");
		return 1;
	}
	else {
		printf("Файл file2.txt успешно открыт\n");
	}
	//инициализируем переменные счетчика, элементов файлов
	int num;
	int count = 0;
	bool positive = true;//используем флаг для определения положительных и отрицательных элементов файла
	//с помощью цикла осуществляем проверку, а затем заполнение нового файла так, как требует условие задачи
	while (fscanf(file1, "%d", &num) != EOF) {
		if ((count % 10 == 0) && (count != 0)) {
			positive = !positive;
		}
		if ((positive && num > 0) || (positive && num < 0)) {
			fprintf(file2, "%d ", num);
			count++;
		}
	}
	//закрываем файлы
	fclose(file1);
	fclose(file2);
	printf("Числа из файла file1.txt переписаны в файл file2.txt\n");//вывод надписи об успешном выполнении программы
	return 0;//завершаем программу
}
