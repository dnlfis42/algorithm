#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	string bomb;
	cin >> str >> bomb;

	vector<char> v;
	for (size_t i = 0; i < str.size(); ++i)
	{
		v.push_back(str[i]);

		if (str[i] == bomb[bomb.size() - 1] && v.size() >= bomb.size())
		{
			bool found = true;

			for (size_t j = 0; j < bomb.size(); ++j)
			{
				if (v[v.size() - bomb.size() + j] != bomb[j])
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				for (size_t j = 0; j < bomb.size(); ++j)
				{
					v.pop_back();
				}
			}
		}
	}

	if (v.empty())
	{
		cout << "FRULA";
	}
	else
	{
		string ans(v.begin(), v.end());
		cout << ans;
	}

	return 0;
}