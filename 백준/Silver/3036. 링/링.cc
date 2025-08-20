#include <iostream>

using namespace std;

int circle[100];

static int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}

	return gcd(b % a, a);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n >> circle[0];
	int divisor;
	for (int i = 1; i < n; ++i)
	{
		cin >> circle[i];
		divisor = gcd(circle[0], circle[i]);
		cout << circle[0] / divisor << '/' << circle[i] / divisor << '\n';
	}

	return 0;
}