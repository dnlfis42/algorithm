#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long x0, y0;
	cin >> x0 >> y0;
	long long px, py;
	px = x0;
	py = y0;

	long long sum = 0;
	for (int i = 1; i < n; ++i)
	{
		long long cx, cy;
		cin >> cx >> cy;
		sum += px * cy - py * cx;
		px = cx;
		py = cy;
	}
	sum += px * y0 - py * x0;
	if (sum < 0)
	{
		sum *= -1;
	}

	cout << fixed << setprecision(1) << static_cast<double>(sum) / 2;

	return 0;
}

int main()
{
	return solution();
}