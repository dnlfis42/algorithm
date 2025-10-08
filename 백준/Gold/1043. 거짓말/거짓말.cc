#include <bits/stdc++.h>

using namespace std;

const int TRUTH = 1;
const int LIE = -1;

int n; // 사람의 수
int m; // 파티의 수
int human[51];
vector<int> party[50];

int mx;

void f(int idx, int cnt)
{
	if (idx == m)
	{
		mx = max(mx, cnt);
		return;
	}

	bool has_truth = false;
	bool has_lie = false;

	vector<int> ne;
	for (int x : party[idx])
	{
		if (human[x] == TRUTH)
		{
			has_truth = true;
		}
		else if (human[x] == LIE)
		{
			has_lie = true;
		}
		else
		{
			ne.push_back(x);
		}
	}

	if (has_truth)
	{
		if (has_lie)
		{
			return;
		}
		else
		{
			for (int x : ne)
			{
				human[x] = TRUTH;
			}
			f(idx + 1, cnt);
		}
	}
	else if (has_lie)
	{
		for (int x : ne)
		{
			human[x] = LIE;
		}
		f(idx + 1, cnt + 1);
	}
	else
	{
		for (int x : ne)
		{
			human[x] = TRUTH;
		}
		f(idx + 1, cnt);
		for (int x : ne)
		{
			human[x] = LIE;
		}
		f(idx + 1, cnt + 1);
	}

	for (int x : ne)
	{
		human[x] = 0;
	}
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	int t; // 진실을 아는 사람의 수
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int x;
		cin >> x;
		human[x] = TRUTH;
	}

	for (int i = 0; i < m; ++i)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; ++j)
		{
			int x;
			cin >> x;
			party[i].push_back(x);
		}
	}
	f(0, 0);
	cout << mx;

	return 0;
}

int main()
{
	return solution();
}