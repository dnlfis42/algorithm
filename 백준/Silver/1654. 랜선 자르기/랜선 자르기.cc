#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	int n;
	cin >> k >> n;

	vector<int> v(k);

	long long st = 1;
	long long en = 0;
	for (int i = 0; i < k; ++i)
	{
		cin >> v[i];
		if (en < v[i])
		{
			en = v[i];
		}
	}

	long long ans = 0;
	while (st <= en)
	{
		long long mid = (st + en) / 2;
		long long sum = 0;

		for (int i = 0; i < k; ++i)
		{
			sum += v[i] / mid;
		}

		if (sum < n)
		{
			en = mid - 1;
		}
		else
		{
			ans = mid;
			st = mid + 1;
		}
	}
	cout << ans;

	return 0;
}