#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}

	cout << "<";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < k - 1; ++j)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (i != n)
		{
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}