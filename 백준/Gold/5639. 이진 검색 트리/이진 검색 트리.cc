#include <iostream>

using namespace std;

struct Node
{
	Node* parent;
	Node* left;
	Node* right;
	int key;
};

Node head;
Node nodes[10000];
int node_idx = 0;

static void push(int n)
{
	Node* prev = &head;
	Node* node = head.left;
	bool is_left = true;
	while (node)
	{
		prev = node;
		if (node->key < n)
		{
			node = prev->right;
			is_left = false;
		}
		else
		{
			node = prev->left;
			is_left = true;
		}
	}

	if (is_left)
	{
		prev->left = &nodes[node_idx];
	}
	else
	{
		prev->right = &nodes[node_idx];
	}

	nodes[node_idx].parent = prev;
	nodes[node_idx].key = n;
	++node_idx;
}

static void print(Node* node)
{
	if (node)
	{
		print(node->left);
		print(node->right);
		cout << node->key << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	while (cin >> num)
	{
		push(num);
	}
	print(&nodes[0]);

	return 0;
}