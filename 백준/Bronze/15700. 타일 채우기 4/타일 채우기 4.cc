#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	long long m;
	cin >> n >> m;

	cout << n * m / 2;

	return 0;
}