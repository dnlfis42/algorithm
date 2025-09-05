#include <iostream>

using namespace std;

int links[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int computer;
	int pair_cnt;
	cin >> computer >> pair_cnt;

	for (int i = 1; i <= computer; ++i)
	{
		links[i] = i;
	}

	int a;
	int b;
	int mn;
	int mx;
	for (int i = 0; i < pair_cnt; ++i)
	{
		cin >> a >> b;
		if (links[a] < links[b])
		{
			mn = links[a];
			mx = links[b];

			for (int j = mx; j <= computer; ++j)
			{
				if (links[j] == mx)
				{
					links[j] = mn;
				}
			}
		}
		else if (links[a] > links[b])
		{
			mn = links[b];
			mx = links[a];

			for (int j = mx; j <= computer; ++j)
			{
				if (links[j] == mx)
				{
					links[j] = mn;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 2; i <= computer; ++i)
	{
		if (links[i] == 1)
		{
			++cnt;
		}
	}
	cout << cnt;

	return 0;
}