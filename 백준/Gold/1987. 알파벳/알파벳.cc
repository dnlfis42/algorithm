#include <iostream>

using namespace std;

constexpr int dr[] = { 0,1,0,-1 };
constexpr int dc[] = { 1,0,-1,0 };

char board[21][21];
bool alpha[26];

int r;
int c;

int mx = 0;

static void f(int ri, int ci, int cnt)
{
	for (int i = 0; i < 4; ++i)
	{
		int tr = ri + dr[i];
		int tc = ci + dc[i];

		if (tr < 0 || tr >= r || tc < 0 || tc >= c)
		{
			continue;
		}

		if (alpha[board[tr][tc] - 'A'])
		{
			continue;
		}

		alpha[board[tr][tc] - 'A'] = true;

		f(tr, tc, cnt + 1);

		alpha[board[tr][tc] - 'A'] = false;
	}

	if (mx < cnt)
	{
		mx = cnt;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		cin >> board[i];
	}

	alpha[board[0][0] - 'A'] = true;
	f(0, 0, 1);

	cout << mx;

	return 0;
}