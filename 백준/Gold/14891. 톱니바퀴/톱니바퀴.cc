#include <iostream>

using namespace std;

bool gear[4][8];
int gear_north[4];

static bool east(int gear_idx)
{
	if (gear_north[gear_idx] >= 6)
	{
		return gear[gear_idx][gear_north[gear_idx] - 6];
	}
	else
	{
		return gear[gear_idx][gear_north[gear_idx] + 2];
	}
}

static bool west(int gear_idx)
{
	if (gear_north[gear_idx] < 2)
	{
		return gear[gear_idx][gear_north[gear_idx] + 6];
	}
	else
	{
		return gear[gear_idx][gear_north[gear_idx] - 2];
	}
}

static void spin(int gear_idx, int rotation)
{
	int rotate_result[4]{};
	rotate_result[gear_idx] = rotation;
	int cur_idx = gear_idx;
	while (cur_idx > 0)
	{
		if (east(cur_idx - 1) == west(cur_idx))
		{
			break;
		}

		if (rotate_result[cur_idx] == 1)
		{
			rotate_result[--cur_idx] = -1;
		}
		else
		{
			rotate_result[--cur_idx] = 1;
		}
	}

	cur_idx = gear_idx;
	while (cur_idx < 3)
	{
		if (east(cur_idx) == west(cur_idx + 1))
		{
			break;
		}

		if (rotate_result[cur_idx] == 1)
		{
			rotate_result[++cur_idx] = -1;
		}
		else
		{
			rotate_result[++cur_idx] = 1;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		if (rotate_result[i] == -1)
		{
			++gear_north[i];
			if (gear_north[i] == 8)
			{
				gear_north[i] = 0;
			}
		}
		else if (rotate_result[i] == 1)
		{
			--gear_north[i];
			if (gear_north[i] == -1)
			{
				gear_north[i] = 7;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char str[13];
	for (int i = 0; i < 4; ++i)
	{
		cin >> str;
		for (int j = 0; j < 8; ++j)
		{
			if (str[j] == '1')
			{
				gear[i][j] = true;
			}
			else
			{
				gear[i][j] = false;
			}
		}
	}

	int k;
	cin >> k;
	while (k--)
	{
		int gear_num;
		int rotation;
		cin >> gear_num >> rotation;
		spin(gear_num - 1, rotation);
	}

	int answer = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (gear[i][gear_north[i]])
		{
			answer += (1 << i);
		}
	}
	cout << answer;

	return 0;
}