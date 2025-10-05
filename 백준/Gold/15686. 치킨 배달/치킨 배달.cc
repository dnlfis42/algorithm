#include <bits/stdc++.h>

using namespace std;

int n; // 도시의 크기
int m; // 남겨야 할 치킨집의 개수

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> valid;

int ans = 1e9;

int calc()
{
	int sum = 0;
	for (auto [hr, hc] : house)
	{
		int mn = 100;
		for (auto [cr, cc] : valid)
		{
			mn = min(mn, abs(hr - cr) + abs(hc - cc));
		}
		sum += mn;
	}

	return sum;
}

void combination(int idx, int cnt)
{
	if (chicken.size() - idx + cnt < m)
	{
		return;
	}

	if (cnt == m)
	{
		ans = min(ans, calc());
		return;
	}

	valid.push_back(chicken[idx]);
	combination(idx + 1, cnt + 1);
	valid.pop_back();
	combination(idx + 1, cnt);
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

	combination(0, 0);
	cout << ans;

	return 0;
}

int main()
{
	return solution();
}