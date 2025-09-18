#include <algorithm>
#include <iostream>
#include <vector>

#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "0";
		return 0;
	}

	int trim = round(n * 0.15);

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = trim; i < n - trim; ++i)
	{
		sum += v[i];
	}

	cout << round(static_cast<double>(sum) / (n - trim * 2));

	return 0;
}