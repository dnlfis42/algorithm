#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> umap;
	while (n--)
	{
		string addr, pwd;
		cin >> addr >> pwd;
		umap[addr] = pwd;
	}
	while (m--)
	{
		string addr;
		cin >> addr;
		cout << umap[addr] << "\n";
	}

	return 0;
}

int main()
{
	return solution();
}