#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, v;
	cin >> a >> b >> v;

	int left = v - a;
	int climb = a - b;

	int day = 1+ left / climb;
	if (left % climb)
	{
		++day;
	}

	cout << day;

	return 0;
}

int main()
{
	return solution();
}