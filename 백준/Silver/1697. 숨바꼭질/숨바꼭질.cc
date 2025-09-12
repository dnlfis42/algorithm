#include <iostream>
#include <queue>

using namespace std;

int line[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 수빈이의 위치
	int k; // 동생의 위치
	cin >> n >> k;

	if (n == k)
	{
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(n);
	while (true)
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
		{
			break;
		}

		if (cur > 0 && cur - 1 != n)
		{
			if (line[cur - 1] == 0)
			{
				line[cur - 1] = line[cur] + 1;
				q.push(cur - 1);
			}
		}

		if (cur < 100000 && cur + 1 != n)
		{
			if (line[cur + 1] == 0)
			{
				line[cur + 1] = line[cur] + 1;
				q.push(cur + 1);
			}
		}

		if (cur <= 50000 && cur * 2 != n)
		{
			if (line[cur * 2] == 0)
			{
				line[cur * 2] = line[cur] + 1;
				q.push(cur * 2);
			}
		}
	}
	cout << line[k];

	return 0;
}