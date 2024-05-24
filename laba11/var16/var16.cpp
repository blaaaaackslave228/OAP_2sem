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

int sum_elements(node* t) {
	if (t == NULL)
		return 0;
	if (t->left == NULL && t->right == NULL)
		return t->data; 
	return sum_elements(t->left) + sum_elements(t->right);
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
	cout << "¬ведите количество элементов: ";
	cin >> number;
	cout << "¬ведите число: ";
	for (int i = 0; i < number; ++i) {
		cin >> temp;
		insert(temp, &tree);
	}
	cout << "ƒерево: " << endl;
	print(tree, 0);
	cout << "—умма значений листьев дерева: " << sum_elements(tree);
	del(&tree);
}