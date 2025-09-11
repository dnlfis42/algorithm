#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int di[4]{ 1,0,-1,0 };
int dj[4]{ 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int mp[26][26];
	int counter[350];

	int n;
	cin >> n;

	char str[30];
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			mp[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	int zone_num = 0;
	int house_cnt;
	pair<int, int> cur_p;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mp[i][j] == 1)
			{
				q.push({ i,j });
				mp[i][j] += ++zone_num;
				house_cnt = 1;

				while (!q.empty())
				{
					cur_p = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k)
					{
						int ti = cur_p.first + di[k];
						int tj = cur_p.second + dj[k];

						if (ti < 0 || ti >= n || tj < 0 || tj >= n)
						{
							continue;
						}

						if (mp[ti][tj] != 1)
						{
							continue;
						}

						q.push({ ti,tj });
						mp[ti][tj] += zone_num;
						++house_cnt;
					}
				}

				counter[zone_num - 1] = house_cnt;
			}
		}
	}

	sort(&counter[0], &counter[zone_num]);

	cout << zone_num << '\n';
	for (int i = 0; i < zone_num; ++i)
	{
		cout << counter[i] << '\n';
	}

	return 0;
}