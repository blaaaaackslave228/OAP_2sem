#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left, * right;
};

node* tree = NULL;

void insert(int a, node** t) {
	if ((*t) == NULL) {
		(*t) = new node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}

	if (a > (*t)->data)
		insert(a, &(*t)->right);
	else
		insert(a, &(*t)->left);
}

void print(node* t, int u) {
	if (t == NULL) return;
	else
	{
		print(t->right, ++u);
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->data << endl;
		u--;
	}
	print(t->left, ++u);
}

int count_leaves(node* t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) {
		return 1;
	}
	return count_leaves(t->left) + count_leaves(t->right);
}

void del(node** t)
{
	if (t != nullptr)
	{
		if ((*t)->left)del(&(*t)->left);
		if ((*t)->right)del(&(*t)->right);
		delete* t;
		*t = nullptr;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	int number, temp;
	cout << "Введите количество элементов: ";
	cin >> number;
	cout << "Введите число: ";
	for (int i = 0; i < number; ++i) {
		cin >> temp;
		insert(temp, &tree);
	}
	cout << "Дерево: " << endl;
	print(tree, 0);
	cout << "Количество листьев: " << count_leaves(tree);
	del(&tree);
} 