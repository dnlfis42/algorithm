#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int dp_mx[3];
	cin >> dp_mx[0] >> dp_mx[1] >> dp_mx[2];
	int dp_mn[3]{ dp_mx[0],dp_mx[1],dp_mx[2] };

	int b0, b1, b2;
	for (int i = 1; i < n; ++i)
	{
		cin >> b0 >> b1 >> b2;
		int mx_0 = max(dp_mx[0], dp_mx[1]);
		int mx_2 = max(dp_mx[1], dp_mx[2]);
		int mx_1 = max(mx_0, mx_2);
		dp_mx[0] = mx_0 + b0;
		dp_mx[1] = mx_1 + b1;
		dp_mx[2] = mx_2 + b2;

		int mn_0 = min(dp_mn[0], dp_mn[1]);
		int mn_2 = min(dp_mn[1], dp_mn[2]);
		int mn_1 = min(mn_0, mn_2);
		dp_mn[0] = mn_0 + b0;
		dp_mn[1] = mn_1 + b1;
		dp_mn[2] = mn_2 + b2;
	}
	int mx = max(dp_mx[0], dp_mx[1]);
	mx = max(mx, dp_mx[2]);
	int mn = min(dp_mn[0], dp_mn[1]);
	mn = min(mn, dp_mn[2]);
	cout << mx << " " << mn;

	return 0;
}