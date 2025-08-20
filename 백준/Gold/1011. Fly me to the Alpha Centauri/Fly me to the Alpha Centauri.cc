#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x;
	int y;
	int delta;

	int t;
	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		delta = y - x;

		int ans = 0;
		for (int i = 1;; ++i)
		{
			++ans;
			if (delta <= i)
			{
				break;
			}
			++ans;
			if (delta <= i * 2)
			{
				break;
			}
			delta -= i * 2;
		}
		cout << ans << '\n';
	}

	return 0;
}