#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	int stick = 0;
	int answer = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			++stick;
		}
		else
		{
			--stick;
			if (str[i - 1] == '(') // 레이저
			{
				answer += stick;
			}
			else
			{
				++answer;
			}
		}
	}

	cout << answer;

	return 0;
}