#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int ans = 0;
	while (n--)
	{
		string str;
		cin >> str;
		stack<char> st;
		for (char c : str)
		{
			if (st.empty())
			{
				st.push(c);
			}
			else
			{
				if (c == st.top())
				{
					st.pop();
				}
				else
				{
					st.push(c);
				}
			}
		}

		if (st.empty())
		{
			++ans;
		}
	}
	cout << ans;

	return 0;
}

int main()
{
	return solution();
}