#include <iostream>

using namespace std;

constexpr int max_idx = 5005;

struct Node
{
	int data;
	int prev;
	int next;
};

Node nodes[max_idx];

int answer[max_idx];
int answer_idx = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		nodes[i].data = i;
		nodes[i].prev = i - 1;
		nodes[i - 1].next = i;
	}
	nodes[1].prev = n;
	nodes[n].next = 1;

	int left = n;
	int rep;
	int node_idx = 1;
	while (left)
	{
		rep = (k - 1) % left;
		while (rep--)
		{
			node_idx = nodes[node_idx].next;
		}

		answer[answer_idx++] = nodes[node_idx].data;
		left--;

		nodes[nodes[node_idx].prev].next = nodes[node_idx].next;
		nodes[nodes[node_idx].next].prev = nodes[node_idx].prev;
		node_idx = nodes[node_idx].next;
	}

	cout << "<";
	for (int i = 0; i < n; ++i)
	{
		cout << answer[i];
		if (i != n - 1)
		{
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}