#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 세로(row)
	int m; // 가로(col)
	int b; // 인벤토리에 들어있는 블록의 개수
	cin >> n >> m >> b;

	int size = n * m;
	vector<int> field(size);
	for (int i = 0; i < size; ++i)
	{
		cin >> field[i];
	}

	int best_time = INT_MAX;
	int best_height = 0;
	for (int h = 0; h <= 256; ++h)
	{
		long long time = 0;
		long long inv = b;
		for (int v : field)
		{
			if (v > h)
			{
				time += static_cast<long long>(v - h) * 2;
				inv += static_cast<long long>(v - h);
			}
			else
			{
				time += static_cast<long long>(h - v);
				inv -= static_cast<long long>(h - v);
			}
		}

		if (inv < 0)
		{
			break;
		}

		if (time <= best_time)
		{
			best_time = time;
			best_height = h;
		}
	}

	cout << best_time << ' ' << best_height;

	return 0;
}

int main()
{
	return solution();
}