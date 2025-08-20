#include <iostream>

using namespace std;

int product[100];
int next_turn[100];
pair<int, int> power_strip[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> product[i];
	}
	for (int i = 0; i < k; ++i)
	{
		int j = i + 1;
		for (; j < k; ++j)
		{
			if (product[i] == product[j])
			{
				break;
			}
		}
		next_turn[i] = j;
	}

	int used = 0;
	int idx = 0;
	for (;;)
	{
		int strip_idx = 0;
		for (; strip_idx < used; ++strip_idx)
		{
			if (power_strip[strip_idx].first == product[idx])
			{
				break;
			}
		}

		if (strip_idx == used)
		{
			if (strip_idx == n)
			{
				break;
			}
			power_strip[strip_idx].first = product[idx];
			++used;
		}
		power_strip[strip_idx].second = next_turn[idx];
		++idx;
	}

	int cnt = 0;
	for (; idx < k; ++idx)
	{
		if (product[idx] == power_strip[0].first)
		{
			power_strip[0].second = next_turn[idx];
			continue;
		}

		int strip_idx = 1;
		int replace_idx = 0;

		for (; strip_idx < n; ++strip_idx)
		{
			if (product[idx] == power_strip[strip_idx].first)
			{
				power_strip[strip_idx].second = next_turn[idx];
				break;
			}
			if (power_strip[strip_idx].second > power_strip[replace_idx].second)
			{
				replace_idx = strip_idx;
			}
		}

		if (strip_idx == n) // 교체해야 함
		{
			power_strip[replace_idx].first = product[idx];
			power_strip[replace_idx].second = next_turn[idx];
			++cnt;
		}
	}
	cout << cnt;

	return 0;
}