#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (;;)
	{
		string str;
		getline(cin, str);
		if (str == "#")
		{
			break;
		}

		int sum = 0;
		int i = 0;
		for (char c : str)
		{
			++i;
			if (c == ' ')
			{
				continue;
			}
			sum += i * (c - 'A' + 1);
		}
		cout << sum << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}