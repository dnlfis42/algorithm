#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char IO[2] = { 'I','O' };

	int n, m;
	string str;
	cin >> n >> m >> str;

	int len = n * 2 + 1;
	vector<int> failure(len);
	for (int i = 2; i < len; ++i)
	{
		failure[i] = i - 1;
	}

	int cnt = 0;
	int j = 0;
	for (int i = 0; i < m; ++i)
	{
		while (j > 0 && str[i] != IO[j % 2])
		{
			j = failure[j - 1]; // 겹쳐진 부분의 접두사, 접미사 최대 길이로 다시 시도 -> 접두사 부분(j)를 이동시킴
		}
		if (str[i] == IO[j % 2])
		{
			if (++j == len) // 찾음
			{
				++cnt;
				j = failure[j - 1];
			}
		}
	}
	cout << cnt;

	return 0;
}