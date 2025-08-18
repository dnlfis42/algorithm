#include <iostream>

using namespace std;

int roads[1100]; // 0 ~ w: 다리 w + 1 ~ w + n: 대기 중인 트럭


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 트럭의 수
	int length; // 다리의 길이
	int max_weight; // 최대하중
	cin >> n >> length >> max_weight;
	for (int i = 0; i < n; ++i)
	{
		cin >> roads[length + i];
	}

	int time = 0;
	int last_truck = length + n - 1;
	int cur_weight = 0;
	int update_idx = length - 1;

	for (;; ++time)
	{
		if (cur_weight - roads[0] + roads[length] > max_weight) // 대기해야함
		{
			if (roads[0])
			{
				cur_weight -= roads[0];
			}

			for (int i = 0; i < length - 1; ++i)
			{
				roads[i] = roads[i + 1];
			}
			roads[length - 1] = 0;
		}
		else // 지나갈 수 있음
		{
			if (roads[0])
			{
				cur_weight -= roads[0];
			}
			cur_weight += roads[length];

			for (int i = 0; i < last_truck; ++i)
			{
				roads[i] = roads[i + 1];
			}
			roads[last_truck--] = 0;
		}

		if (last_truck < 0)
		{
			break;
		}
	}
	cout << time + 1;

	return 0;
}