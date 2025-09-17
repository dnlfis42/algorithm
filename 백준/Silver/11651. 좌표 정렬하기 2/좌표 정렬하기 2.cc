#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		int y;
		cin >> x >> y;
		pq.push({ y,x });
	}

	for (int i = 0; i < n; ++i)
	{
		auto t = pq.top();
		pq.pop();
		cout << t.second << " " << t.first << "\n";
	}

	return 0;
}