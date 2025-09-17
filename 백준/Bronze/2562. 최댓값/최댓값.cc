#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int mx = 0;
	int wh = 0;
	for (int i = 1; i <= 9; ++i)
	{
		int num;
		cin >> num;
		if (mx < num)
		{
			mx = num;
			wh = i;
		}
	}
	cout << mx << "\n" << wh;

	return 0;
}