#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int k;
	cin >> n >> k;

	list<int> circle;
	for (int i = 1; i <= n; ++i)
	{
		circle.push_back(i);
	}
	auto it = circle.begin();

	vector<int> answer(n);
	int answer_idx = 0;

	while (answer_idx < n)
	{
		int rep = k;
		while (--rep)
		{
			++it;
			if (it == circle.end())
			{
				it = circle.begin();
			}
		}
		answer[answer_idx++] = *it;
		it = circle.erase(it);
		if (it == circle.end())
		{
			it = circle.begin();
		}
	}

	cout << "<";
	for (int i = 0; i < n; ++i)
	{
		cout << answer[i];
		if (i != n - 1)
		{
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}