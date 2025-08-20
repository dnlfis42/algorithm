#include <iostream>
#include <cstring>

using namespace std;

int day[16];
int pay[16];
int min_day[16];
int result[16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(min_day, 20, sizeof(int) * 16);

	int n;
	cin >> n;
	cin >> day[0] >> pay[0];
	min_day[day[0]] = 0;

	for (int i = 1; i < n; ++i)
	{
		cin >> day[i] >> pay[i];
		if ((i + day[i] <= n) && i < min_day[i + day[i]])
		{
			min_day[i + day[i]] = i;
		}

		result[i] = result[i - 1];
		for (int j = min_day[i]; j < i; ++j)
		{
			if (i == j + day[j] && result[i] < result[j] + pay[j])
			{
				result[i] = result[j] + pay[j];
			}
		}
	}

	result[n] = result[n - 1];
	for (int i = min_day[n]; i < n; ++i)
	{
		if (n == i + day[i] && result[n] < result[i] + pay[i])
		{
			result[n] = result[i] + pay[i];
		}
	}
	cout << result[n];

	return 0;
}