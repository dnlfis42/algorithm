#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<int, int> um;

	int n; // 숫자 카드의 개수
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		++um[x];
	}

	int m;
	cin >> m;
	while (m--)
	{
		int x;
		cin >> x;

		auto it = um.find(x);
		if (it != um.end())
		{
			cout << it->second << " ";
		}
		else
		{
			cout << "0 ";
		}
	}

	return 0;
}