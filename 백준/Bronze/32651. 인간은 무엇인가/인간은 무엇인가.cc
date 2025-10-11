#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if (n > 100'000 || n%2024)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}

	return 0;
}

int main()
{
	return solution();
}