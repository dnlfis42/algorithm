#include <bits/stdc++.h>

using namespace std;

vector<bool> vert;
vector<bool> diag;
vector<bool> anti_diag;

int solve(int r, int n)
{
	if (r == n)
	{
		return 1;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int di = n - 1 - r + i;
		int adi = r + i;
		if (vert[i] || diag[di] || anti_diag[adi])
		{
			continue;
		}

		vert[i] = diag[di] = anti_diag[adi] = true;
		cnt += solve(r + 1, n);
		vert[i] = diag[di] = anti_diag[adi] = false;
	}
	return cnt;
}

int solution2()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vert.resize(n, false);
	diag.resize(n * 2 - 1, false);
	anti_diag.resize(n * 2 - 1, false);
	cout << solve(0, n);

	return 0;
}

int main()
{
	return solution2();
}