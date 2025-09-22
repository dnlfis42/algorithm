#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	vector<pair<int, int>> childs; // 노드, 에지
	int edge_1 = 0;
	int edge_2 = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Node> nodes(n + 1);

	int p, c, e;
	for (int i = 1; i < n; ++i)
	{
		cin >> p >> c >> e;
		nodes[p].childs.push_back({ c,e });
	}

	vector<vector<int>> depths(n);
	depths[0].push_back(1);
	int mx_depth = 0;

	queue<pair<int, int>> q; // 노드, 깊이
	q.push({ 1,0 });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int idx = cur.first;
		int depth = cur.second + 1;

		for (auto& i : nodes[cur.first].childs)
		{
			depths[depth].push_back(i.first);
			q.push({ i.first,depth });

			if (mx_depth < depth)
			{
				mx_depth = depth;
			}
		}
	}

	int mx = 0;
	for (int d = mx_depth; d >= 0; --d)
	{
		for (auto i : depths[d])
		{
			Node& node = nodes[i]; // 해당 깊이의 노드
			int edge_1 = 0;
			int edge_2 = 0;

			for (auto& c : node.childs)
			{
				Node& child = nodes[c.first]; // 노드의 자식
				int edge = c.second + max(child.edge_1, child.edge_2);

				if (edge_1)
				{
					if (edge_1 < edge)
					{
						edge_2 = edge_1;
						edge_1 = edge;
					}
					else
					{
						if (edge_2 < edge)
						{
							edge_2 = edge;
						}
					}
				}
				else
				{
					edge_1 = edge;
				}
			}
			node.edge_1 = edge_1;
			node.edge_2 = edge_2;

			if (mx < edge_1 + edge_2)
			{
				mx = edge_1 + edge_2;
			}
		}
	}
	cout << mx;

	return 0;
}