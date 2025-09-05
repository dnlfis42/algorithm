#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int remain;
	bool found = false;
	for (int i = n / 5; i >= 0; --i)
	{
		remain = n - (5 * i);
		if (remain % 3 == 0)
		{
			cout << i + (remain / 3);
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << -1;
	}

	return 0;
}