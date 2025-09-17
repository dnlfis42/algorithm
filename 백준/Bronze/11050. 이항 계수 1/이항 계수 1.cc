#include <iostream>

using namespace std;

static int pac(int n)
{
	int ret = 1;
	for (int i = 2; i <= n; ++i)
	{
		ret *= i;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int k;
	cin >> n >> k;
	cout << pac(n) / pac(k) / pac(n - k);

	return 0;
}