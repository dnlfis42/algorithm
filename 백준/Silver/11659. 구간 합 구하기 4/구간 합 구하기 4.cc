#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	vector<int> v(n, 0);
	cin >> v[0];

	for (int i = 1; i < n; ++i)
	{
		int num;
		cin >> num;

		v[i] = v[i - 1] + num;
	}

	for (int i = 0; i < m; ++i)
	{
		int a;
		int b;
		cin >> a >> b;

		if (a == 1)
		{
			cout << v[b - 1] << "\n";
		}
		else
		{
			cout << v[b - 1] - v[a - 2] << "\n";
		}
	}

	return 0;
}