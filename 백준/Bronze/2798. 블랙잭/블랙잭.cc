#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> cards(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());

	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		int n1 = cards[i];
		if (n1 >= m)
		{
			break;
		}

		for (int j = i + 1; j < n; ++j)
		{
			int n2 = n1 + cards[j];
			if (n2 >= m)
			{
				break;
			}

			for (int k = j + 1; k < n; ++k)
			{
				int n3 = n2 + cards[k];
				if (n3 > m)
				{
					break;
				}

				if (mx < n3)
				{
					mx = n3;
				}
			}
		}
	}
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}