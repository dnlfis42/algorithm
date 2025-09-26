#include <bits/stdc++.h>

using namespace std;

vector<bool> v;
vector<bool> d;
vector<bool> ad;
int cnt;

void f1(int n, int row)
{
	if (row == n)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int di = n - 1 - row + i;
		int adi = row + i;
		if (v[i] || d[di] || ad[adi])
		{
			continue;
		}

		v[i] = true;
		d[di] = true;
		ad[adi] = true;
		f1(n,row + 1);
		v[i] = false;
		d[di] = false;
		ad[adi] = false;
	}
}

// 메모리	KB
// 시간		ms
int solution1()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	v.resize(n, false);
	d.resize(n * 2 - 1, false);
	ad.resize(n * 2 - 1, false);

	f1(n, 0);
	cout << cnt;

	return 0;
}

int main()
{
	return solution1();
}