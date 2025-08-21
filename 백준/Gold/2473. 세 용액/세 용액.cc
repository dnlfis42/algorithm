#include <iostream>
#include <algorithm>

using namespace std;

long long sol[5001];
long long ans[3] = { 1'111'111'111,1'111'111'111 ,1'111'111'111 };
long long comp;
long long ans_abs;

static int bs(int st, int en)
{
	if (st == en)
	{
		return st;
	}

	int mid = (st + en) / 2;
	if (sol[mid] < comp)
	{
		return bs(mid + 1, en);
	}
	else if (sol[mid] == comp)
	{
		return mid;
	}
	else
	{
		return bs(st, mid);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> sol[i];
	}
	sort(sol, sol + n);

	ans_abs = abs(ans[0] + ans[1] + ans[2]);
	long long temp_abs;
	for (int first = 0; first < n - 2; ++first)
	{
		for (int second = first + 1; second < n - 1; ++second)
		{
			comp = -sol[first] - sol[second];
			int third = bs(second + 1, n);
			if (third >= second + 2)
			{
				temp_abs = abs(sol[third - 1] - comp);
				if (ans_abs > temp_abs)
				{
					ans[0] = sol[first];
					ans[1] = sol[second];
					ans[2] = sol[third - 1];
					ans_abs = temp_abs;
				}
			}

			if (third < n)
			{
				temp_abs = abs(sol[third] - comp);
				if (ans_abs > temp_abs)
				{
					ans[0] = sol[first];
					ans[1] = sol[second];
					ans[2] = sol[third];
					ans_abs = temp_abs;
				}
			}
		}
	}
	sort(ans, ans + 3);
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

	return 0;
}