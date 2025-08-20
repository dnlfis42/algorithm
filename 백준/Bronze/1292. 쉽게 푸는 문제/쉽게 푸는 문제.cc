#include <iostream>

using namespace std;

int total[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a;
	int b;
	cin >> a >> b;

	int adder = 1;
	int cnt = 0;
	for (int i = 1; i <= b; ++i)
	{
		total[i] = total[i - 1] + adder;
		if (++cnt == adder)
		{
			++adder;
			cnt = 0;
		}
	}

	cout << total[b] - total[a - 1];

	return 0;
}