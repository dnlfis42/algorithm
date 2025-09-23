#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int blen = 1;
	int bb = b;
	while (bb)
	{
		bb /= 10;
		blen *= 10;
	}

	cout << a + b - c << "\n" << a * blen + b - c;

	return 0;
}