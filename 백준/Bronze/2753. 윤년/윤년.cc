#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int y;
	cin >> y;
	if (y % 4)
	{
		cout << 0;
	}
	else
	{
		if (y % 100)
		{
			cout << 1;
		}
		else if(y%400)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
	}

	return 0;
}