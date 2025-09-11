#include <iostream>

using namespace std;

struct Node
{
	char c;
	Node* left;
	Node* right;
};

Node nodes[26];

void f1(Node* node)
{
	cout << node->c;
	if (node->left)
	{
		f1(node->left);
	}
	if (node->right)
	{
		f1(node->right);
	}
}

void f2(Node* node)
{
	if (node->left)
	{
		f2(node->left);
	}
	cout << node->c;
	if (node->right)
	{
		f2(node->right);
	}
}

void f3(Node* node)
{
	if (node->left)
	{
		f3(node->left);
	}
	if (node->right)
	{
		f3(node->right);
	}
	cout << node->c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	char c1;
	char c2;
	char c3;

	Node* node;
	Node* left;
	Node* right;
	for (int i = 0; i < n; ++i)
	{
		cin >> c1 >> c2 >> c3;

		node = &nodes[c1 - 'A'];
		node->c = c1;

		if (c2 != '.')
		{
			left = &nodes[c2 - 'A'];
			node->left = left;
		}
		else
		{
			node->left = nullptr;
		}

		if (c3 != '.')
		{
			right = &nodes[c3 - 'A'];
			node->right = right;
		}
		else
		{
			node->right = nullptr;
		}
	}

	f1(&nodes[0]);
	cout << '\n';
	f2(&nodes[0]);
	cout << '\n';
	f3(&nodes[0]);

	return 0;
}