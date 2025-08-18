#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 0;
	bool can_eat = true;
	for (int i = 0; i < 10; ++i)
	{
		int temp;
		cin >> temp;
		if (can_eat)
		{
			if ((answer + temp <= 100) || (answer + temp - 100 <= 100 - answer))
			{
				answer += temp;
			}
			else
			{
				can_eat = false;
			}
		}
	}
	cout << answer;

	return 0;
}