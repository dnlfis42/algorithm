#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a;
	int b;
	char op[3];
	bool result;

	for (int t = 1;; ++t)
	{
		cin >> a >> op >> b;
		if (op[0] == 'E')
		{
			break;
		}

		if (op[0] == '>')
		{
			if (op[1] == '=')
			{
				if (a >= b)
				{
					result = true;
				}
				else
				{
					result = false;
				}
			}
			else
			{
				if (a > b)
				{
					result = true;
				}
				else
				{
					result = false;
				}
			}
		}
		else if (op[0] == '<')
		{
			if (op[1] == '=')
			{
				if (a <= b)
				{
					result = true;
				}
				else
				{
					result = false;
				}
			}
			else
			{
				if (a < b)
				{
					result = true;
				}
				else
				{
					result = false;
				}
			}
		}
		else if (op[0] == '=')
		{
			if (a == b)
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
		else // !
		{
			if (a != b)
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}

		cout << "Case " << t << ": ";
		if (result)
		{
			cout << "true\n";
		}
		else
		{
			cout << "false\n";
		}
	}

	return 0;
}