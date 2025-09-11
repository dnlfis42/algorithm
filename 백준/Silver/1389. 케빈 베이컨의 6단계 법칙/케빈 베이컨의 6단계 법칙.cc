#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int users[101][101];
int sum[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	int a;
	int b;
	while (m--)
	{
		cin >> a >> b;
		users[a][b] = 1;
		users[b][a] = 1;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	int hop;
	int sum;
	int mn_sum = 2'000'000'000;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (users[i][j] == 0)
			{
				continue;
			}

			pq.push({ users[i][j],j }); // {hop,user}
		}

		while (!pq.empty())
		{
			auto cur = pq.top();
			hop = cur.first + 1;
			pq.pop();

			for (int j = i + 1; j <= n; ++j)
			{
				if (users[i][j] > 0 || users[cur.second][j] != 1)
				{
					continue;
				}

				users[i][j] = hop;
				users[j][i] = hop;
				pq.push({ hop,j });
			}
		}

		sum = 0;
		for (int j = 1; j <= n; ++j)
		{
			sum += users[i][j];
		}
		if (sum < mn_sum)
		{
			mn_sum = sum;
			ans = i;
		}
	}
	cout << ans;

	return 0;
}