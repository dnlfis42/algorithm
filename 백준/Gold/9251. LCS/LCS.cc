#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str1;
	string str2;
	cin >> str1 >> str2;
	int len1 = str1.size();
	int len2 = str2.size();

	int ans = 0;
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[len1][len2];

	return 0;
}