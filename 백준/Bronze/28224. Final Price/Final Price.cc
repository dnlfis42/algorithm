#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long answer = 0;
	long long input;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		answer += input;
	}
	cout << answer;

	return 0;
}