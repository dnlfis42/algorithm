#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

constexpr int BIG = 5000;
constexpr int SMALL = -5000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> counter(8001, 0);
	long long sum = 0;
	int mn = BIG;
	int mx = SMALL;

	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		++counter[x + 4000];
		sum += x;
		mn = min(mn, x);
		mx = max(mx, x);
	}
	int mean = static_cast<int>(round(static_cast<double>(sum) / n));

	int median;
	int accumulation = 0;
	bool found_mid = false;

	int mode[2];
	mode[1] = BIG;
	int mx_cnt = -1;
	for (int i = 0; i <= 8000; ++i)
	{
		if (counter[i] > 0)
		{
			if (!found_mid)
			{
				accumulation += counter[i];
				if (accumulation > (n / 2))
				{
					median = i - 4000;
					found_mid = true;
				}
			}

			if (counter[i] > mx_cnt)
			{
				mx_cnt = counter[i];
				mode[0] = i - 4000;
				mode[1] = BIG;
			}
			else if (counter[i] == mx_cnt)
			{
				if (mode[1] == BIG)
				{
					mode[1] = i - 4000;
				}
			}
		}
	}

	cout << mean << '\n' << median << '\n';
	if (mode[1] != BIG)
	{
		cout << mode[1];
	}
	else
	{
		cout << mode[0];
	}
	cout << '\n' << mx - mn;

	return 0;
}