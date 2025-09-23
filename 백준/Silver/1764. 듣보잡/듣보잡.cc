#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	unordered_set<string> hearless;
	vector<string> whoareyou;

	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		hearless.insert(str);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> str;
		if (hearless.find(str) != hearless.end())
		{
			whoareyou.push_back(str);
		}
	}
	sort(whoareyou.begin(), whoareyou.end());
	
	cout << whoareyou.size() << "\n";
	for (auto& s : whoareyou)
	{
		cout << s << "\n";
	}

	return 0;
}