#include <bits/stdc++.h>

using namespace std;

int n; // 도시의 크기
int m; // 남겨야 할 치킨집

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<bool> checked;

int ans = 1e9;

void combination(int idx, int cnt)
{
	if (cnt == m)
	{
		int sum = 0;

		for (auto& p : house)
		{
			int mn = 100;
			for (int i = 0; i < chicken.size(); ++i)
			{
				if (checked[i])
				{
					mn = min(mn, abs(p.first - chicken[i].first) + abs(p.second - chicken[i].second));
				}
			}
			sum += mn;
		}
		ans = min(ans, sum);

		return;
	}

	for (int i = idx; i < chicken.size(); ++i)
	{
		if (checked[i])
		{
			continue;
		}

		checked[i] = true;
		combination(i + 1, cnt + 1);
		checked[i] = false;
	}
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			int v;
			cin >> v;
			if (v == 1)
			{
				house.push_back({ r,c });
			}
			else if (v == 2)
			{
				chicken.push_back({ r,c });
			}
		}
	}

	checked.assign(chicken.size(), false);

	combination(0, 0);

	cout << ans;

	return 0;
}

int main()
{
	return solution();
}