#include <bits/stdc++.h>

using namespace std;

// 메모리	
// 시간		
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int r;
	int c;
	cin >> n >> r >> c;

	int sr = 0; // start row
	int sc = 0; // start col
	int cn = 1 << n; // current n
	int ans = 0; // answer

	for (;;)
	{
		if (r == sr && c == sc) // r,c가 시작인 경우
		{
			break;
		}

		cn >>= 1; // 다음 단계의 한 변의 길이
		int adder = cn * cn;
		if (r < sr + cn) // 위
		{
			if (c >= sc + cn) // 오른쪽
			{
				ans += adder;
				sc += cn;
			}
		}
		else // 아래
		{
			ans += adder * 2;
			sr += cn;
			if (c >= sc + cn) // 오른쪽
			{
				ans += adder;
				sc += cn;
			}
		}
	}
	cout << ans;

	return 0;
}