#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int a;
	int b;
	cin >> n >> a >> b;
	for (int i = 1;; ++i)
	{
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;

		if (a == b)
		{
			cout << i;
			break;
		}
	}

	return 0;
}