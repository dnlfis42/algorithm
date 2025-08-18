#include <iostream>
#include <algorithm>

using namespace std;

long long numbers[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + n);
	long long answer = numbers[0];
	int answer_cnt = 0;

	long long temp_number = numbers[0];
	int temp_cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		if (temp_number == numbers[i])
		{
			++temp_cnt;
		}
		else
		{
			if (temp_cnt > answer_cnt)
			{
				answer = temp_number;
				answer_cnt = temp_cnt;
			}
			temp_number = numbers[i];
			temp_cnt = 1;
		}
	}
	if (temp_cnt > answer_cnt)
	{
		cout << temp_number;
	}
	else
	{
		cout << answer;
	}

	return 0;
}