#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int e;
	int s;
	int m;
	cin >> e >> s >> m;
	--e;
	--s;
	--m;

	int y = s;
	for (;; y += 28)
	{
		if (y % 15 == e && y % 19 == m)
		{
			break;
		}
	}
	cout << y + 1;

	return 0;
}