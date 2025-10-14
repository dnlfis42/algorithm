#include <bits/stdc++.h>

using namespace std;

int n, m;

int order[8];

void recur(int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; ++i)
		{
			cout << order[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = num; i <= n - m + cnt + 1; ++i)
	{
		order[cnt] = i;
		recur(i + 1, cnt + 1);
	}
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	recur(1, 0);

	return 0;
}

int main()
{
	return solution();
}