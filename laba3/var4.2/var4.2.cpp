#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	string str;
	cout << "Введите строку: ";
	getline(cin, str);

	ofstream file_one("D:/Денис/2 сем/оаип/лабы/files/FileC.txt");
	if (!file_one) {
		cout << "нельзя открыть файл для записи" << endl;
	}
    
	file_one << str;
	file_one.close();

	ifstream file_two("D:/Денис/2 сем/оаип/лабы/files/FileC.txt");
	if (!file_two) {
		cout << "нельзя открыть файл для чтения" << endl;
	}

	string word;
	string long_word;
	int max = 0;
	while (file_two >> word) {
		int length = word.length();
		if (length > max) {
			max = length;
			long_word = word;
		}
	}
	file_two.close();
	cout << long_word << endl;

	return 0;

}