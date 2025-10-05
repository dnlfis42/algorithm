#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 과일의 개수
	cin >> n;

	vector<int> fruit(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> fruit[i];
	}

	int f1 = fruit[0];
	int c1 = 1;

	int f2 = 0;
	int c2 = 0;

	int l = 0;
	int r = 1;

	while (r < n)
	{
		if (fruit[r] == f1)
		{
			++c1;
			++r;
		}
		else
		{
			f2 = fruit[r];
			++c2;
			++r;

			break;
		}
	}

	// l = 0, r = 다음 과일로 세팅된 상태

	int mx = c1 + c2;

	for (; r < n; ++r)
	{
		if (fruit[r] == f1)
		{
			++c1;
			mx = max(mx, c1 + c2);
		}
		else if (fruit[r] == f2)
		{
			++c2;
			mx = max(mx, c1 + c2);
		}
		else
		{
			while (c1 > 0 && c2 > 0)
			{
				if (fruit[l] == f1)
				{
					--c1;
				}
				else if (fruit[l] == f2)
				{
					--c2;
				}
				++l;
			}

			if (c1 == 0)
			{
				f1 = fruit[r];
				c1 = 1;
			}
			else // if (c2 == 0)
			{
				f2 = fruit[r];
				c2 = 1;
			}
		}
		/*
		cout <<
			"l: " << l << " r: " << r <<
			" f1: " << f1 << " f2: " << f2 <<
			" c1: " << c1 << " c2: " << c2 << "\n";
		*/
	}
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}