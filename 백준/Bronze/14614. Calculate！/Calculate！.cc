#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	string c;
	cin >> a >> b >> c;
	if ((c[c.size() - 1] - '0') % 2)
	{
		int x = a ^ b;
		cout << x;
	}
	else
	{
		cout << a;
	}

	return 0;
}

int main()
{
	return solution();
}