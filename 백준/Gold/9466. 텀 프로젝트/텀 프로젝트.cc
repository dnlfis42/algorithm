#include <iostream>
#include <cstring>

using namespace std;

int point[100'005];
char result[100'005];
int loop[100'005];
int loop_idx;

void find_loop(int i)
{
	if (result[i] == 0) // 루프 후보
	{
		if (point[i] == i)
		{
			result[i] = 'T';
		}
		else
		{
			result[i] = 'L';
			loop[loop_idx++] = i;
			find_loop(point[i]);
		}
	}
	else if (result[i] == 'L') // 루프 완성
	{
		result[i] = 'T';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> point[i];
		}
		memset(result, 0, sizeof(char)* (n + 1));

		for (int i = 1; i <= n; ++i)
		{
			if (result[i] == 0)
			{
				loop_idx = 0;
				find_loop(i);
				char input = 'F';
				for (int i = 0; i < loop_idx; ++i)
				{
					if (result[loop[i]] == 'T')
					{
						input = 'T';
					}
					result[loop[i]] = input;
				}
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (result[i] == 'F')
			{
				++cnt;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}