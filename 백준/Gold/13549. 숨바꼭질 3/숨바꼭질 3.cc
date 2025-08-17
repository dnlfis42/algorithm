#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int line[100'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(line, 200000, sizeof(int) * 100'001);

	int n;
	int k;
	cin >> n >> k;

	queue<int> q;
	line[n] = 0;
	q.push(n);

	while (!q.empty())
	{
		int p = q.front();
		q.pop();

		if (p == k)
		{
			break;
		}

		if (p > 0 && line[p - 1] > line[p] + 1)
		{
			line[p - 1] = line[p] + 1;
			q.push(p - 1);
		}

		if (p < 100'000 && line[p + 1] > line[p] + 1)
		{
			line[p + 1] = line[p] + 1;
			q.push(p + 1);
		}

		if (p <= 50'000 && line[p * 2] > line[p])
		{
			line[p * 2] = line[p];
			q.push(p * 2);
		}
	}

	cout << line[k];

	return 0;
}