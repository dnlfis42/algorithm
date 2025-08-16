#include <iostream>

using namespace std;

struct Tower
{
	int height;
	int idx;
};

Tower stk[500'005];
int stk_idx = 0;

string answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int height;
	cin >> height;

	stk[stk_idx].height = height;
	stk[stk_idx].idx = 1;
	++stk_idx;

	cout << 0;

	for (int i = 2; i <= n; ++i)
	{
		cin >> height;

		while (stk_idx > 0 && stk[stk_idx - 1].height < height)
		{
			--stk_idx;
		}

		cout << " ";
		if (stk_idx > 0)
		{
			cout << stk[stk_idx - 1].idx;
		}
		else
		{
			cout << 0;
		}

		stk[stk_idx].height = height;
		stk[stk_idx].idx = i;
		++stk_idx;
	}

	return 0;
}