#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> seq[i];
	}

	vector<int> comp = seq;
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	for (int x : seq)
	{
		cout << lower_bound(comp.begin(), comp.end(), x) - comp.begin() << " ";
	}

	return 0;
}