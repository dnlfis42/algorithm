#include <iostream>

using namespace std;

int seq[1001];
int increase[1001];
int decrease[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
		int mx = 0;
		for (int j = 0; j <= i; ++j)
		{
			if (seq[j] < seq[i])
			{
				if (mx < increase[j])
				{
					mx = increase[j];
				}
			}
		}

		if (mx)
		{
			increase[i] = mx + 1;
		}
		else
		{
			increase[i] = 1;
		}
	}

	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		int mx = 0;
		for (int j = n - 1; j >= i; --j)
		{
			if (seq[j] < seq[i])
			{
				if (mx < decrease[j])
				{
					mx = decrease[j];
				}
			}
		}

		if (mx)
		{
			decrease[i] = mx + 1;
		}
		else
		{
			decrease[i] = 1;
		}

		if (ans < increase[i] + decrease[i])
		{
			ans = increase[i] + decrease[i];
		}
	}
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << increase[i] << ' ';
	//}
	//cout << "\n";

	//for (int i = 0; i < n; ++i)
	//{
	//	cout << decrease[i] << ' ';
	//}
	//cout << "\n";
	cout << ans - 1;

	return 0;
}