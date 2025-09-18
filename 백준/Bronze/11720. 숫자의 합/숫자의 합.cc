#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string str;
	cin >> n >> str;

	int sum = 0;
	for (char c : str)
	{
		sum += c;
	}
	cout << sum - '0' * n;

	return 0;
}