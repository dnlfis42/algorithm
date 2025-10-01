#include <bits/stdc++.h>

using namespace std;

int height[257];

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 세로(row)
	int m; // 가로(col)
	int b; // 인벤토리에 들어있는 블록의 개수
	cin >> n >> m >> b;

	int size = n * m;

	for (int i = 0; i < size; ++i)
	{
		int x;
		cin >> x;
		++height[x];
	}

	int mn_height = 256;
	for (int i = 0; i <= 256; ++i)
	{
		if (height[i])
		{
			mn_height = i;
			break;
		}
	}

	int mx_height = 0;
	for (int i = 256; i >= 0; --i)
	{
		if (height[i])
		{
			mx_height = i;
			break;
		}
	}

	int best_time = INT_MAX;
	int best_height = 0;
	for (int h = mn_height; h <= mx_height; ++h)
	{
		int time = 0;
		int inv = b;

		for (int i = mn_height; i <= mx_height; ++i)
		{
			if (height[i])
			{
				if (h < i) // 파기
				{
					time += (i - h) * 2 * height[i];
					inv += (i - h) * height[i];
				}
				else if (h > i) // 놓기
				{
					time += (h - i) * height[i];
					inv -= (h - i) * height[i];
				}
			}

			if (time > best_time)
			{
				break;
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