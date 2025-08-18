#include <iostream>

using namespace std;

struct Egg
{
	int hp;
	int atk;
};

Egg eggs[8];
int n;
int answer;

static void recur(int idx)
{
	if (idx == n)
	{
		int temp = 0;
		for (int i = 0; i < n; ++i)
		{
			if (eggs[i].hp <= 0)
			{
				++temp;
			}
		}
		if (answer < temp)
		{
			answer = temp;
		}
		return;
	}

	bool can_hit = false;
	if (eggs[idx].hp > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i == idx || eggs[i].hp <= 0)
			{
				continue;
			}
			can_hit = true;

			eggs[idx].hp -= eggs[i].atk;
			eggs[i].hp -= eggs[idx].atk;
			recur(idx + 1);
			eggs[idx].hp += eggs[i].atk;
			eggs[i].hp += eggs[idx].atk;
		}
	}

	if (!can_hit)
	{
		recur(idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> eggs[i].hp >> eggs[i].atk;
	}
	recur(0);

	cout << answer;

	return 0;
}