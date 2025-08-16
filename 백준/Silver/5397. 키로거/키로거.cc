#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		string input;
		cin >> input;

		list<char> password{};
		auto cursor = password.begin();

		for (auto word : input)
		{
			if (word == '-')
			{
				if (cursor != password.begin())
				{
					cursor = password.erase(--cursor);
				}
			}
			else if (word == '<')
			{
				if (cursor != password.begin())
				{
					--cursor;
				}
			}
			else if (word == '>')
			{
				if (cursor != password.end())
				{
					++cursor;
				}
			}
			else
			{
				password.insert(cursor, word);
			}
		}

		for (auto word : password)
		{
			cout << word;
		}
		cout << '\n';
	}

	return 0;
}