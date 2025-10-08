#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1'000'000'007;

long long mod_pow(long long a, long long e)
{
	long long ret = 1;

	while (e)
	{
		if (e & 1)
		{
			ret = ret * a % MOD;
		}
		a = (a * a) % MOD;
		e >>= 1;
	}
	return ret;
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long m; // 주사위의 수
	cin >> m;

	long long ans = 0;
	for (int i = 0; i < m; ++i)
	{
		long long n; // 주사위 면의 개수
		long long s; // 모든 면에 적힌 숫자를 더한 값
		cin >> n >> s;

		// n^-1 * n = 1 (mod MODULER)
		// n^-1 = n^(MODULER - 2) (mod MODULER)
		// Q = s * n^-1 = s * n^(MODULER -2) % MODULER

		long long q = s * mod_pow(n, MOD - 2) % MOD; // O(logMOD) = 30
		ans += q;
		if (ans >= MOD)
		{
			ans -= MOD;
		}
	}
	cout << ans;

	return 0;
}

int main()
{
	return solution();
}