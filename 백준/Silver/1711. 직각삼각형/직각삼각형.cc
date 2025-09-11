#include <iostream>
#include <vector>

using namespace std;

bool is_triangle(const pair<long long, long long>& a, const pair<long long, long long>& b, const pair<long long, long long>& c)
{
	if ((b.first - a.first) * (c.second - a.second) == (b.second - a.second) * (c.first - a.first))
	{
		return false;
	}

	long long ab = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
	long long bc = (b.first - c.first) * (b.first - c.first) + (b.second - c.second) * (b.second - c.second);
	long long ca = (c.first - a.first) * (c.first - a.first) + (c.second - a.second) * (c.second - a.second);

	return (ab + bc == ca || ab + ca == bc || bc + ca == ab);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	int ans = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (is_triangle(v[i], v[j], v[k]))
				{
					++ans;
				}
			}
		}
	}
	cout << ans;

	return 0;
}