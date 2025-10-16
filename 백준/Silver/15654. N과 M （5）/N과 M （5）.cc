#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v;
vector<bool> selected;
vector<int> sequence;

void recur(int cnt)
{
	if (cnt == m)
	{
		for (int x : sequence)
		{
			cout << x << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (selected[i])
		{
			continue;
		}

		selected[i] = true;
		sequence[cnt] = v[i];
		recur(cnt + 1);
		selected[i] = false;
	}
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	v.reserve(n);
	selected.assign(n, false);
	sequence.resize(m);

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	recur(0);

	return 0;
}

int main()
{
	return solution();
}