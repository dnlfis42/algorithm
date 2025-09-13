#include <iostream>

using namespace std;

bool check[42];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	for (int i = 0; i < 10; ++i)
	{
		cin >> n;
		check[n % 42] = true;
	}

	int ans = 0;
	for (int i = 0; i < 42; ++i)
	{
		if (check[i])
		{
			++ans;
		}
	}
	cout << ans;

	return 0;
}