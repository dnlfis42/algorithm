#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;

	queue<pair<long long, long long>> q;
	q.push({ a,1 });

	int ans = -1;
	while (!q.empty())
	{
		auto [cur, cnt] = q.front();
		q.pop();

		if (cur == b)
		{
			ans = cnt;
			break;
		}
		else
		{
			if (cur * 2 <= b)
			{
				q.push({ cur * 2,cnt + 1 });
			}
			if (cur * 10 + 1 <= b)
			{
				q.push({ cur * 10 + 1,cnt + 1 });
			}
		}
	}
	cout << ans;

	return 0;
}

int main()
{
	return solution();
}