#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	while (cin >> str)
	{
		if (str == "0")
		{
			break;
		}

		int len = str.size();
		bool right = true;
		for (int i = 0; i < len / 2; ++i)
		{
			if (str[i] != str[len - 1 - i])
			{
				right = false;
				break;
			}
		}

		if (right)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}

	return 0;
}

int main()
{
	return solution();
}