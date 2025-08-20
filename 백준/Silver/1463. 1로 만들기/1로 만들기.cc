#include <iostream>
#include <cstring>

using namespace std;

int numbers[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	numbers[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		numbers[i] = numbers[i - 1];
		if (i % 2 == 0)
		{
			if (numbers[i] > numbers[i / 2])
			{
				numbers[i] = numbers[i / 2];
			}
		}
		if (i % 3 == 0)
		{
			if (numbers[i] > numbers[i / 3])
			{
				numbers[i] = numbers[i / 3];
			}
		}
		++numbers[i];
	}
	cout << numbers[n];

	return 0;
}