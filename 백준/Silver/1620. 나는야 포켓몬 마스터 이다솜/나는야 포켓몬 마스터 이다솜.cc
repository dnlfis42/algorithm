#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	unordered_map<int, string> umap_int;
	unordered_map<string, int> umap_str;
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		umap_int[i] = str;
		umap_str[str] = i;
	}
	while (m--)
	{
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9')
		{
			cout << umap_int.find(stoi(str))->second << "\n";
		}
		else
		{
			cout << umap_str.find(str)->second << "\n";
		}
	}

	return 0;
}

int main()
{
	return solution();
}