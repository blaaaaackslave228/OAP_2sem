#include <iostream>
using namespace std;
#define MAX 100

int matrix[MAX][MAX];
int color[MAX];
bool found = true;
int n, m;

void sort_matrix(int node, int c) {
    color[node] = c;
    for (int i = 0; i < m; i++) {
        if (matrix[node][i]) {
            if (color[i] == -1) {
                sort_matrix(i, 1 - c);
            }
            else if (color[i] == color[node]) {
                found = false;
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    cout << "Введите матрицу смежности: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }         
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    sort_matrix(0, 0);
    if (found) {
        cout << "Можно разделить на две группы.\n";
    }
    else {
        cout << "Нельзя разделить на две группы.\n";
    }
    return 0;
}
