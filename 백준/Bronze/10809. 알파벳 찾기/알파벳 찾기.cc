#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int check[26];
	for (int i = 0; i < 26; ++i)
	{
		check[i] = -1;
	}

	string str;
	cin >> str;

	int len1 = str.size();
	int pos;
	for (int i = 0; i < len1; ++i)
	{
		pos = str[i] - 'a';
		if (check[pos] == -1)
		{
			check[pos] = i;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << check[i] << ' ';
	}

	return 0;
}