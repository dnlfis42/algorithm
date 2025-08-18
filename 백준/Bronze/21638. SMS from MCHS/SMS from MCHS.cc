#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t1;
	int t2;
	int v1;
	int v2;
	cin >> t1 >> v1 >> t2 >> v2;

	if (t2 < 0 && v2 >= 10)
	{
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
	}
	else
	{
		if (t1 > t2)
		{
			cout << "MCHS warns! Low temperature is expected tomorrow.";
		}
		else if (v2 > v1)
		{
			cout << "MCHS warns! Strong wind is expected tomorrow.";
		}
		else
		{
			cout << "No message";
		}
	}

	return 0;
}