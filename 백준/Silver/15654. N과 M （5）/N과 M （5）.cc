#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int m;

vector<int> v;
int order[8];
bool check[8];

static void recur(int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << order[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			order[level] = v[i];
			recur(level + 1);
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	recur(0);

	return 0;
}