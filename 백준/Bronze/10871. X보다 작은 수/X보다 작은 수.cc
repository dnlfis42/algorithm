#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int x;
	cin >> n >> x;
	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		if (num < x)
		{
			cout << num << ' ';
		}
	}

	return 0;
}