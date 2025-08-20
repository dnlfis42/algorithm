#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	long long k;
	cin >> n >> k;

	long long digit = 1;
	long long digit_cnt = 9;
	long long start_num = 1;
	long long num_idx;
	long long num_place;
	for (;;)
	{
		if (k <= digit_cnt * digit)
		{
			num_idx = (k - 1) / digit;
			start_num += num_idx;
			if (start_num > n)
			{
				cout << -1;
				break;
			}
			num_place = digit - (k - 1) % digit;
			while (--num_place)
			{
				start_num /= 10;
			}
			cout << start_num % 10;
			break;
		}
		k -= digit_cnt * digit;
		digit_cnt *= 10;
		++digit;
		start_num *= 10;
	}

	return 0;
}