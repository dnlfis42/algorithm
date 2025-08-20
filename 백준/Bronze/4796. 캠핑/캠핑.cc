#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int l;
	int p;
	int v;
	int rep;
	int cnt = 1;
	while (cin >> l >> p >> v)
	{
		if (l == 0 && p == 0 && v == 0)
		{
			break;
		}
		rep = v / p;
		cout << "Case " << cnt++ << ": " << rep * l + min(l, v - (rep * p)) << '\n';
	}

	return 0;
}