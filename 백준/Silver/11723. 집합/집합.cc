#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool arr[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int num;

	int m;
	cin >> m;
	cin.ignore();
	while (m--)
	{
		getline(cin, str);

		switch (str[0])
		{
		case 'a':
			if (str[1] == 'd')
			{
				num = atoi(&str[4]);
				if (!arr[num])
				{
					arr[num] = true;
				}
			}
			else // all
			{
				memset(arr, 1, 21);
			}
			break;
		case 'c': // check
			num = atoi(&str[6]);
			if (arr[num])
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
			break;
		case 'e':
			memset(arr, 0, 21);
			break;
		case 'r':
			num = atoi(&str[7]);
			if (arr[num])
			{
				arr[num] = false;
			}
			break;
		case 't':
			num = atoi(&str[7]);
			if (arr[num])
			{
				arr[num] = false;
			}
			else
			{
				arr[num] = true;
			}
			break;
		}
	}

	return 0;
}