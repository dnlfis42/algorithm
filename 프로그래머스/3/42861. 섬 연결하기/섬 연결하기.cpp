#include <algorithm>
#include <vector>

using namespace std;

int parents[100];

int find(int x)
{
	if (parents[x] == x)
	{
		return x;
	}
	return parents[x] = find(parents[x]);
}

int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		parents[i] = i;
	}

	sort(costs.begin(), costs.end(),
		[](const vector<int>& a, const vector<int>& b) {return a[2] < b[2]; });

	int selected = 0;
	for (const vector<int>& cost : costs)
	{
		if (find(cost[0]) != find(cost[1]))
		{
			if (parents[cost[0]] < parents[cost[1]])
			{
				parents[parents[cost[1]]] = parents[cost[0]];
			}
			else
			{
				parents[parents[cost[0]]] = parents[cost[1]];
			}

			answer += cost[2];
			if (++selected == n - 1)
			{
				break;
			}
		}
	}

	return answer;
}