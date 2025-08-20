#include <iostream>

using namespace std;

int n;
int m;
int k;

static int cnt(int num)
{
	int ret = 0;
	int temp = n;
	while (temp)
	{
		ret += temp / num;
		temp /= num;
	}
	temp = m;
	while (temp)
	{
		ret -= temp / num;
		temp /= num;
	}
	temp = k;
	while (temp)
	{
		ret -= temp / num;
		temp /= num;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	k = n - m;
	cout << min(cnt(2), cnt(5));

	return 0;
}