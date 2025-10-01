#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	set<string> words;
	while (n--)
	{
		string s;
		cin >> s;
		words.insert(s);
	}
	vector<string> v(words.begin(), words.end());
	sort(v.begin(), v.end(),
		[](const string& a, const string& b)
		{
			if (a.size() == b.size())
			{
				return a < b;
			}
			return a.size() < b.size();
		});

	for (auto& s : v)
	{
		cout << s << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}