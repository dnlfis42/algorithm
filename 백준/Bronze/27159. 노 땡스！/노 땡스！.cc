#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 0;
	int before = 0;
	int temp;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp != before + 1)
		{
			answer += temp;
		}
		before = temp;
	}
	cout << answer;

	return 0;
}