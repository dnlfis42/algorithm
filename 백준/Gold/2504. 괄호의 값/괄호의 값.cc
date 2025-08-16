#include <iostream>
#include <string>

using namespace std;

int stk[30];
int stk_idx = 0;

static bool push(int n)
{
	if (stk_idx == 0)
	{
		return false;
	}

	int temp = 0;
	while (stk_idx > 0)
	{
		if (stk[--stk_idx] < 2)
		{
			break;
		}
		temp += stk[stk_idx];
	}

	if (stk[stk_idx] != n - 2)
	{
		return false;
	}

	if (temp > 0)
	{
		temp *= n;
	}
	else
	{
		temp = n;
	}

	stk[stk_idx++] = temp;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool is_possible = true;

	string str;
	cin >> str;
	for (auto c : str)
	{
		if (c == '(')
		{
			stk[stk_idx++] = 0;
		}
		else if (c == '[')
		{
			stk[stk_idx++] = 1;
		}
		else if (c == ')')
		{
			if (!push(2))
			{
				is_possible = false;
				break;
			}
		}
		else
		{
			if (!push(3))
			{
				is_possible = false;
				break;
			}
		}
	}

	int answer = 0;
	while (stk_idx > 0)
	{
		if (stk[--stk_idx] < 2)
		{
			is_possible = false;
			break;
		}
		answer += stk[stk_idx];
	}

	if (is_possible)
	{
		cout << answer;
	}
	else
	{
		cout << 0;
	}

	return 0;
}