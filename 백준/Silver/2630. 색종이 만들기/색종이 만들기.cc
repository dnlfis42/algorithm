#include <iostream>
#include <vector>

using namespace std;

int ans[2];

void f(const vector<vector<int>>& v, int rs, int cs, int re, int ce)
{
	int is_white = v[rs][cs];
	bool found = true;
	for (int r = rs; r <= re; ++r)
	{
		for (int c = cs; c <= ce; ++c)
		{
			if (v[r][c] != is_white)
			{
				found = false;
				break;
			}
		}
	}

	if (found)
	{
		++ans[is_white];
	}
	else
	{
		int rm = (rs + re) / 2;
		int cm = (cs + ce) / 2;
		f(v, rs, cs, rm, cm);
		f(v, rs, cm + 1, rm, ce);
		f(v, rm + 1, cs, re, cm);
		f(v, rm + 1, cm + 1, re, ce);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}
	f(v, 0, 0, n - 1, n - 1);
	cout << ans[0] << "\n" << ans[1];

	return 0;
}