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
	memset(numbers, 100, sizeof(int) * (n + 1));
	numbers[1] = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i * 3 <= 1000000 && numbers[i * 3] > numbers[i] + 1)
		{
			numbers[i * 3] = numbers[i] + 1;
		}
		if (i * 2 <= 1000000 && numbers[i * 2] > numbers[i] + 1)
		{
			numbers[i * 2] = numbers[i] + 1;
		}
		if (numbers[i + 1] > numbers[i] + 1)
		{
			numbers[i + 1] = numbers[i] + 1;
		}
	}
	cout << numbers[n];

	return 0;
}