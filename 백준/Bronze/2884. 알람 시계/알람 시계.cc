#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, m;
	cin >> h >> m;

	if (m < 45)
	{
		m += 15;
		if (h > 0)
		{
			--h;
		}
		else
		{
			h = 23;
		}
	}
	else
	{
		m -= 45;
	}
	cout << h << " " << m;

	return 0;
}

int main()
{
	return solution();
}