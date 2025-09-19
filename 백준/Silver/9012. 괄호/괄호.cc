#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;

		stack<char> st;

		bool right = true;
		for (auto c : str)
		{
			if (c == '(')
			{
				st.push('(');
			}
			else
			{
				if (st.empty())
				{
					right = false;
					break;
				}
				else
				{
					st.pop();
				}
			}
		}

		if (right && st.empty())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}