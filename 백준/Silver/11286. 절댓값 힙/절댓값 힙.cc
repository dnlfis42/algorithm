#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto cmp = [](int a, int b)
		{
			if (abs(a) == abs(b))
			{
				return a > b;
			}
			else
			{
				return abs(a) > abs(b);
			}
		};
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}

int main()
{
	return solution();
}