#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool is_mixed = false;
	int num;
	cin >> num;
	if (num == 1)
	{
		for (int i = 2; i <= 8; ++i)
		{
			cin >> num;
			if (num != i)
			{
				is_mixed = true;
				break;
			}
		}

		if (!is_mixed)
		{
			cout << "ascending";
		}
	}
	else if (num == 8)
	{
		for (int i = 7; i >= 1; --i)
		{
			cin >> num;
			if (num != i)
			{
				is_mixed = true;
				break;
			}
		}

		if (!is_mixed)
		{
			cout << "descending";
		}
	}
	else
	{
		is_mixed = true;
	}

	if (is_mixed)
	{
		cout << "mixed";
	}

	return 0;
}