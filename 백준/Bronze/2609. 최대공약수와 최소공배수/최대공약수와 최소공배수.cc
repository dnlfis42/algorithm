#include <bits/stdc++.h>

using namespace std;

int get_gcd(int a, int b)
{
	return (a % b) ? get_gcd(b, a % b) : b;
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	int gcd = get_gcd(a, b);
	int lcm = a * b / gcd;
	cout << gcd << "\n" << lcm;

	return 0;
}

int main()
{
	return solution();
}