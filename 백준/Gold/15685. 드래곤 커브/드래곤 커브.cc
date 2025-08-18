#include <iostream>

using namespace std;

bool result[101][101];
pair<int, int> points[1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int x;
	int y;
	int d;
	int g;
	while (n--)
	{
		cin >> x >> y >> d >> g;

		points[0].first = x;
		points[0].second = y;
		switch (d)
		{
		case 0:
			points[1].first = x + 1;
			points[1].second = y;
			break;
		case 1:
			points[1].first = x;
			points[1].second = y - 1;
			break;
		case 2:
			points[1].first = x - 1;
			points[1].second = y;
			break;
		case 3:
			points[1].first = x;
			points[1].second = y + 1;
			break;
		}

		int last_idx = 1;
		while (g--)
		{
			int mid_x = points[last_idx].first;
			int mid_y = points[last_idx].second;
			for (int i = 0; i < last_idx; ++i)
			{
				int cur_x = points[i].first;
				int cur_y = points[i].second;

				points[last_idx * 2 - i] = { mid_x - (cur_y - mid_y),mid_y - (mid_x - cur_x) };
			}
			last_idx = last_idx * 2;
		}

		for (int i = 0; i <= last_idx; ++i)
		{
			result[points[i].second][points[i].first] = true;
		}
	}

	int count = 0;
	for (int r = 0; r < 100; ++r)
	{
		for (int c = 0; c < 100; ++c)
		{
			if (result[r][c])
			{
				if (result[r + 1][c] && result[r][c + 1] && result[r + 1][c + 1])
				{
					++count;
				}
			}
		}
	}
	cout << count;

	return 0;
}