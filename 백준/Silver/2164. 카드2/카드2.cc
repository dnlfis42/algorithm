#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}

	int answer = q.front();
	while (true)
	{
		q.pop();
		if (q.empty())
		{
			break;
		}
		answer = q.front();
		q.pop();
		q.push(answer);
	}

	cout << answer;

	return 0;
}