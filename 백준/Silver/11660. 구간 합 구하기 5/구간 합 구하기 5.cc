#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= n; ++c)
		{
			cin >> sum[r][c];
			sum[r][c] += sum[r - 1][c] - sum[r - 1][c - 1] + sum[r][c - 1];
		}
	}

	int x1;
	int y1;
	int x2;
	int y2;
	for (int i = 0; i < m; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		--y1;
		cout << sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1] << "\n";
	}

	return 0;
}