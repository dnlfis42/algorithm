#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int total[3]{};
	int left;
	int mid;
	int right;

	int n;
	int t = 0;
	while (++t)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}

		cin >> total[0] >> total[1] >> total[2];
		total[0] = total[1] + 1;
		total[2] += total[1];

		for (int i = 1; i < n; ++i)
		{
			cin >> left >> mid >> right;
			total[0] = min(total[0], total[1]);
			total[2] = min(total[1], total[2]);
			total[1] = min(total[0], total[2]);

			total[0] += left;
			total[1] = min(total[0], total[1]) + mid;
			total[2] = min(total[1], total[2]) + right;
		}

		cout << t << ". " << total[1] << '\n';
	}

	return 0;
}