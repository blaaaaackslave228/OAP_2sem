#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	char str[1000];
	ifstream file_one("D:/�����/2 ���/����/����/files/File1.txt");
	ofstream file_two("D:/�����/2 ���/����/����/files/File2.txt");

	if (!file_one) {
		cout << "������ ������� ���� ��� ������";
	}
	if (!file_two) {
		cout << "������ ������� ������������ ����";
	}

	while (file_one.getline(str, 1000)) {
		if (str[0]!=' ') {
			file_two << str << endl;
		}
	}

	file_one.close();
	file_two.close();

	ifstream file_three("D:/�����/2 ���/����/����/files/File2.txt");

	if (!file_three) {
		cout << "������ ������� ���� ��� ������";
	}

	while (file_three.getline(str, 1000)) {
		int length = 0;
		while (str[length] != '\0') {
			length++;
		}
		if (length == 5) {
			cout << str << endl;
			break;
		}
	}

	file_three.close();

	return 0;
}
