#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

long long f1(long long n)
{
	if (n == 1)
	{
		return a % c;
	}

	long long mul = f1(n / 2);
	mul *= mul;
	mul %= c;

	if (n % 2)
	{
		mul *= a;
		mul %= c;
	}

	return mul;
}

int solution1()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b >> c;
	cout << f1(b);

	return 0;
}

int main()
{
	return solution1();
}