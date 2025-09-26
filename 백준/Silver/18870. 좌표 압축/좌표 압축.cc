#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> seq(n);
	map<int, int> mp;

	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
		mp[seq[i]];
	}

	int pos = 0;
	for (auto& it : mp)
	{
		it.second = pos++;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << mp.at(seq[i]) << " ";
	}

	return 0;
}