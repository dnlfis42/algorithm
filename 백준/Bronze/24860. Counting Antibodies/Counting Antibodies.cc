#include <bits/stdc++.h>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long vk, jk;
	long long vl, jl;
	long long vh, dh, jh;
	cin >> vk >> jk >> vl >> jl >> vh >> dh >> jh;

	cout << vh * dh * jh * (vk * jk + vl * jl);

	return 0;
}

int main()
{
	return solution();
}