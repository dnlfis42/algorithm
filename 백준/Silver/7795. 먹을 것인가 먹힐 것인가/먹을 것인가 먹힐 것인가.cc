#include <iostream>
#include <algorithm>

using namespace std;

int a[20001];
int b[20001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	int n;
	int m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + m);

		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (a[i] > b[j])
				{
					++cnt;
				}
				else
				{
					break;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}