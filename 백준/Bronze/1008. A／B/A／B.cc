#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double a, b;
	cin >> a >> b;
	cout.precision(15);
	cout << fixed << a / b;

	return 0;
}