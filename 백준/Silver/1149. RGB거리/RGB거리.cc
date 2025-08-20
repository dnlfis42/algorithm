#include <iostream>
#include <cstring>

using namespace std;

int total[3];
int temp[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin >> total[0] >> total[1] >> total[2];

	int r;
	int g;
	int b;
	for (int i = 1; i < n; ++i)
	{
		cin >> r >> g >> b;
		temp[0] = min(total[1], total[2]) + r;
		temp[1] = min(total[0], total[2]) + g;
		temp[2] = min(total[0], total[1]) + b;

		memcpy(total, temp, sizeof(int) * 3);
	}
	cout << min(total[0], min(total[1], total[2]));

	return 0;
}