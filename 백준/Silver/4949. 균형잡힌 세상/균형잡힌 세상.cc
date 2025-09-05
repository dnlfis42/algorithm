#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> st;
	string str;
	bool is_right;
	for (;;)
	{
		getline(cin, str);
		if (str.size() == 1 && str[0] == '.')
		{
			break;
		}

		is_right = true;
		for (auto c : str)
		{
			switch (c)
			{
			case'(':
				st.push('(');
				break;
			case')':
				if (st.empty())
				{
					is_right = false;
				}
				else
				{
					if (st.top() == '(')
					{
						st.pop();
					}
					else
					{
						is_right = false;
					}
				}
				break;
			case'[':
				st.push('[');
				break;
			case']':
				if (st.empty())
				{
					is_right = false;
				}
				else
				{
					if (st.top() == '[')
					{
						st.pop();
					}
					else
					{
						is_right = false;
					}
				}
				break;
			default:
				break;
			}

			if (!is_right)
			{
				break;
			}
		}

		if (!st.empty())
		{
			is_right = false;
		}

		if (is_right)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}

		while (!st.empty())
		{
			st.pop();
		}
	}

	return 0;
}