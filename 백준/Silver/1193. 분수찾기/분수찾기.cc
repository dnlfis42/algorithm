#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x;
	cin >> x;

	bool flipped = false;
	for (int i = 1;; ++i)
	{
		if (x <= i)
		{
			if (flipped)
			{
				cout << x << '/' << i + 1 - x;
			}
			else
			{
				cout << i + 1 - x << '/' << x;
			}
			break;
		}
		x -= i;
		flipped = !flipped;
	}

	return 0;
}