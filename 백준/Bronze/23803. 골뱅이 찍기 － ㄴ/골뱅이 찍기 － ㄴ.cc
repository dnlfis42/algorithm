#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string str;
	str.resize(n, '@');

	for (int i = 0; i < n * 4; ++i)
	{
		cout << str << "\n";
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << str;
		}
		cout << "\n";
	}


	return 0;
}

int main()
{
	return solution();
}