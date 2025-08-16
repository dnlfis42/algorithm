#include <iostream>

using namespace std;

int input[100000];
int idx = 0;

int stk[100000];
int stk_idx = 0;
int next_num = 1;

bool answer[200000];
int answer_idx = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}

	bool is_possible = true;
	for (; idx < n; ++idx)
	{
		if (input[idx] >= next_num)
		{
			for (; next_num < input[idx]; ++next_num)
			{
				stk[stk_idx++] = next_num;
				answer[answer_idx++] = true;
			}
			++next_num;
			answer[answer_idx++] = true;
			answer[answer_idx++] = false;
		}
		else
		{
			if (stk_idx <= 0 || stk[--stk_idx] != input[idx])
			{
				is_possible = false;
				break;
			}

			answer[answer_idx++] = false;
		}
	}

	if (is_possible)
	{
		for (int i = 0; i < answer_idx; ++i)
		{
			if (answer[i])
			{
				cout << "+\n";
			}
			else
			{
				cout << "-\n";

			}
		}
	}
	else
	{
		cout << "NO";
	}

	return 0;
}