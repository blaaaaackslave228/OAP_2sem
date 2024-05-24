#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    char input1[500];
    char input2[500];

    cout << "¬ведите первую строку: ";
    cin.getline(input1, 500);

    cout << "¬ведите вторую строку: ";
    cin.getline(input2, 500);

    ofstream file_two("D:/ƒенис/2 сем/оаип/лабы/files/FileK.txt");
    if (!file_two) {
        cout << "нельх€ открыть файл дл€ записи";
    }
    file_two << input1 << endl << input2;
    file_two.close();

    ifstream file_one("D:/ƒенис/2 сем/оаип/лабы/files/FileK.txt");
    if (!file_one) {
        cout << "нельз€ открыть файл дл€ чтени€";
    }

    file_one.getline(input1, 500);
    int min_length1 = 500;
    char min_word1[50] = { 0 };
    char* ptr1 = input1;
    char* min_word_ptr1 = min_word1;

    while (*ptr1 != '\0') {
        char word1[50] = { 0 };
        int word_length1 = 0;
        while (*ptr1 != ' ' && *ptr1 != '\0') {
            word1[word_length1++] = *ptr1;
            ptr1++;
        }
        if (word_length1 > 0) {
            if (word_length1 < min_length1) {
                min_length1 = word_length1;
                for (int i = 0; i < word_length1; i++) {
                    *(min_word_ptr1++) = word1[i];
                }
                *min_word_ptr1 = '\0';
                min_word_ptr1 = min_word1;
            }
        }
        while (*ptr1 == ' ') {
            ptr1++;
        }
    }

    file_one.getline(input2, 500);
    int max_length2 = 0;
    char max_word2[50] = { 0 };
    char* ptr2 = input2;
    char* max_word_ptr2 = max_word2;

    while (*ptr2 != '\0') {
        char word2[50] = { 0 };
        int word_length2 = 0;
        while (*ptr2 != ' ' && *ptr2 != '\0') {
            word2[word_length2++] = *ptr2;
            ptr2++;
        }
        if (word_length2 > 0) {
            if (word_length2 > max_length2) {
                max_length2 = word_length2;
                for (int i = 0; i < word_length2; i++) {
                    *(max_word_ptr2++) = word2[i];
                }
                *max_word_ptr2 = '\0';
                max_word_ptr2 = max_word2;
            }
        }
        while (*ptr2 == ' ') {
            ptr2++;
        }
    }

    cout << "—амое короткое слово в первой строке: " << min_word1 << endl;
    cout << "—амое длинное слово во второй строке: " << max_word2 << endl;

    file_one.close();

    return 0;
}
