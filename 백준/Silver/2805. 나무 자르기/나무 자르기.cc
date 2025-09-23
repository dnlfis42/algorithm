#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 나무의 수
	int m; // 나무의 길이
	cin >> n >> m;

	map<int, int> trees;
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		++trees[x];
		sum += x;
	}

	int tree_cnt = n; // 나무 개수
	int h = 0;
	for (auto it = trees.begin();; it = trees.erase(it))
	{
		int height = it->first;
		int count = it->second;
		long long mx_cut = static_cast<long long>(height - h) * tree_cnt;
		if (sum - mx_cut > m)
		{
			tree_cnt -= count;
			sum -= mx_cut;
			h = height;
		}
		else if (sum - mx_cut == m)
		{
			h = height;
			break;
		}
		else
		{
			while (sum >= m)
			{
				sum -= tree_cnt;
				++h;
			}
			--h;
			break;
		}
	}
	cout << h;

	return 0;
}