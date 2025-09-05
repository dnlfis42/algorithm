#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	map<int, string> powers;

	string str;
	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> str >> num;

		if (powers.find(num) == powers.end())
		{
			powers[num] = str;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> num;
		auto ans = powers.lower_bound(num);
		cout << ans->second << '\n';
	}

	return 0;
}