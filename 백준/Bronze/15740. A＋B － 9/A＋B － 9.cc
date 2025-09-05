#include <iostream>
#include <string>

using namespace std;

string ans;

static void plus_proc(const string& a, const string& b, bool is_positive)
{
	int a_idx = a.size() - 1;
	int b_idx = b.size() - 1;
	int ae = is_positive ? 0 : 1;
	int be = is_positive ? 0 : 1;
	int adr = 0;
	int sum;
	bool need_break;

	for (;;)
	{
		sum = adr;
		need_break = true;
		if (a_idx >= ae)
		{
			sum += a[a_idx--] - '0';
			need_break = false;
		}
		if (b_idx >= be)
		{
			sum += b[b_idx--] - '0';
			need_break = false;
		}

		if (need_break)
		{
			break;
		}

		if (sum < 10)
		{
			adr = 0;
			ans.push_back('0' + sum);
		}
		else
		{
			adr = 1;
			ans.push_back('0' + sum - 10);
		}
	}

	if (adr > 0)
	{
		ans.push_back(adr + '0');
	}

	if (!is_positive)
	{
		ans.push_back('-');
	}
}

static void minus_proc(const string& a, const string& b) // a - b
{
	int a_idx = a.size() - 1;
	int b_idx = b.size() - 1;
	int sum;
	int adr = 0;
	bool need_break;

	for (;;)
	{
		sum = adr;
		need_break = true;
		if (a_idx >= 0)
		{
			need_break = false;
			sum += a[a_idx--] - '0';
		}
		if (b_idx >= 1)
		{
			need_break = false;
			sum -= b[b_idx--] - '0';
		}

		if (need_break)
		{
			break;
		}

		if (sum < 0)
		{
			adr = -1;
			ans.push_back('0' + sum + 10);
		}
		else
		{
			adr = 0;
			ans.push_back('0' + sum);
		}
	}

	if (adr < 0) // 음수
	{
		adr = 0;
		int en = ans.size() - 1;
		for (int i = 0; i <= en; ++i)
		{
			sum = adr - ans[i] + '0';
			if (sum < 0)
			{
				adr = -1;
				ans[i] = sum + 10 + '0';
			}
			else
			{
				adr = 0;
				ans[i] = sum + '0';
			}
		}

		if (ans[en] == '0')
		{
			ans[en] = '-';
		}
		else
		{
			ans.push_back('-');
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a;
	string b;
	cin >> a >> b;

	if (a[0] == '-')
	{
		if (b[0] == '-')
		{
			plus_proc(a, b, false);
		}
		else
		{
			minus_proc(b, a);
		}
	}
	else
	{
		if (b[0] == '-')
		{
			minus_proc(a, b);
		}
		else
		{
			plus_proc(a, b, true);
		}
	}

	bool is_zero = true;
	for (int i = ans.size() - 1; i >= 0; --i)
	{
		if (is_zero && i > 0 && ans[i] == '0')
		{
			continue;
		}
		else
		{
			is_zero = false;
		}

		cout << ans[i];
	}

	return 0;
}