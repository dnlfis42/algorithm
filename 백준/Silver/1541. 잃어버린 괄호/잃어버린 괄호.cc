#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	int len = str.size();

	char num[6];
	int num_idx = 0;
	bool is_plus = true;
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num[num_idx++] = str[i];
		}
		else
		{
			num[num_idx] = '\0';
			num_idx = 0;
			if (is_plus)
			{
				sum += atoi(num);
				is_plus = (str[i] == '+');
			}
			else
			{
				sum -= atoi(num);
			}
		}
	}

	num[num_idx] = '\0';
	if (is_plus)
	{
		sum += atoi(num);
	}
	else
	{
		sum -= atoi(num);
	}
	cout << sum;

	return 0;
}