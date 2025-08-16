#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	string p;
	int n;
	string arr;

	bool is_possible;
	bool is_reversed;

	while (t--)
	{
		cin >> p >> n >> arr;

		deque<int> deq;
		is_possible = true;
		is_reversed = false;

		int arr_end = arr.size() - 1;
		arr[arr_end] = ',';

		int num_begin = 1;
		int num_end;
		while (num_begin < arr_end)
		{
			num_end = num_begin;
			while (arr[num_end] != ',')
			{
				++num_end;
			}
			string num = arr.substr(num_begin, num_end - num_begin);
			deq.push_back(stoi(num));
			num_begin = num_end + 1;
		}

		for (auto c : p)
		{
			if (c == 'R')
			{
				is_reversed = !is_reversed;
			}
			else // D
			{
				if (deq.empty())
				{
					is_possible = false;
					break;
				}
				else
				{
					if (is_reversed)
					{
						deq.pop_back();
					}
					else
					{
						deq.pop_front();
					}
				}
			}
		}

		if (is_possible)
		{
			int deq_size = deq.size();
			cout << "[";
			if (is_reversed)
			{
				for (int i = deq_size - 1; i >= 0; --i)
				{
					cout << deq[i];
					if (i > 0)
					{
						cout << ",";
					}
				}
			}
			else
			{
				for (int i = 0; i < deq_size; ++i)
				{
					cout << deq[i];
					if (i < deq_size - 1)
					{
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}
	}

	return 0;
}