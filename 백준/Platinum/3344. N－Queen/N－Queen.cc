#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;	
	int even_half = n / 2;
	int odd_half = (n + 1) / 2;

	if (n % 6 == 2)
	{
		for (int i = 1; i <= even_half; ++i)
		{
			cout << i * 2 << '\n';
		}
		cout << "3\n1\n";
		for (int i = 4; i <= odd_half; ++i)
		{
			cout << i * 2 - 1 << '\n';
		}
		cout << 5;
	}
	else if (n % 6 == 3)
	{
		for (int i = 2; i <= even_half; ++i)
		{
			cout << i * 2 << '\n';
		}
		cout << "2\n";
		for (int i = 3; i <= odd_half; ++i)
		{
			cout << i * 2 - 1 << '\n';
		}
		cout << "1\n3";
	}
	else
	{
		for (int i = 1; i <= even_half; ++i)
		{
			cout << i * 2 << '\n';
		}
		for (int i = 1; i <= odd_half; ++i)
		{
			cout << i * 2 - 1 << '\n';
		}
	}

	return 0;
}