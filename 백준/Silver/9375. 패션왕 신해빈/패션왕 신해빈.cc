#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		unordered_map<string, int> umap;
		while (n--)
		{
			string a, b;
			cin >> a >> b;
			++umap[b];
		}

		int ans = 1;
		for (auto& it : umap)
		{
			ans *= it.second + 1;
		}

		cout << ans - 1 << "\n";
	}

	return 0;
}