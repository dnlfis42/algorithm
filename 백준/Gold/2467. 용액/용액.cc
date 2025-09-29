#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int mn = INT_MAX;
	int a1 = 0, a2 = 0;
	bool found = false;
	for (int i = 0; i < n - 1; ++i)
	{
		int val = v[i] * -1;
		int st = i + 1;
		int en = n - 1;
		int mid;
		while (true)
		{
			if (st > en)
			{
				break;
			}

			mid = (st + en) / 2;
			int vmid = v[mid];

			if (val < vmid)
			{
				if (mn > vmid - val)
				{
					mn = vmid - val;
					a1 = val * -1;
					a2 = vmid;
				}
				en = mid - 1;
			}
			else if (val > vmid)
			{
				if (mn > (vmid - val) * -1)
				{
					mn = (vmid - val) * -1;
					a1 = val * -1;
					a2 = vmid;
				}
				st = mid + 1;
			}
			else
			{
				a1 = val * -1;
				a2 = vmid;
				found = true;
				break;
			}
		}

		if (found)
		{
			break;
		}
	}
	cout << a1 << " " << a2;

	return 0;
}

int main()
{
	return solution();
}