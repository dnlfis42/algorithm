#include <iostream>
#include <array>

using namespace std;

using Matrix = array<array<long long, 2>, 2>;

constexpr long long MOD = 1'000'000'007;
constexpr Matrix base{ {{1,1},{1,0}} };

Matrix mul(const Matrix& a, const Matrix& b)
{
	return Matrix{ {
		{(a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD,
		(a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD},
		{(a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD,
		(a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD}
		} };
}

Matrix f(long long n)
{
	if (n == 1)
	{
		return base;
	}

	Matrix m = f(n / 2);
	m = mul(m, m);
	if (n % 2)
	{
		m = mul(m, base);
	}
	return m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;
	Matrix matrix = f(n);
	cout << matrix[1][0];

	return 0;
}