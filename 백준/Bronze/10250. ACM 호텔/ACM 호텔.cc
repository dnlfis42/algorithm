#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int h, w, n;
		cin >> h >> w >> n;

		--n;
		int number = n / h + 1;
		int floor = n % h + 1;

		cout << floor * 100 + number << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}