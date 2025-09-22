#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 참가자 수
	cin >> n;
	int t_cnts[6]; // 티셔츠 사이즈 별 신청자 수
	for (int i = 0; i < 6; ++i)
	{
		cin >> t_cnts[i];
	}
	int t; // 티셔츠 묶음 수
	int p; // 펜 묶음 수
	cin >> t >> p;

	int tb_cnt = 0;
	for (int i = 0; i < 6; ++i)
	{
		tb_cnt += (t_cnts[i] / t) + (t_cnts[i] % t > 0);
	}
	cout << tb_cnt << "\n" << n / p << " " << n % p;

	return 0;
}