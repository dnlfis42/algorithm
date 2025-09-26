#include <bits/stdc++.h>

using namespace std;

// 메모리	
// 시간		
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == 0)
		{
			break;
		}

		bool right = true;
		if (a > b)
		{
			if (a > c)
			{
				right = (a * a == b * b + c * c);
			}
			else // c >= a
			{
				right = (c * c == a * a + b * b);
			}
		}
		else // b >= a
		{
			if (b > c)
			{
				right = (b * b == a * a + c * c);
			}
			else // c >= b
			{
				right = (c * c == a * a + b * b);
			}
		}

		if (right)
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}

	return 0;
}