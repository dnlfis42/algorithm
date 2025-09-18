#include <deque>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	string str;
	string bomb;
	cin >> str >> bomb;

	size_t str_len = str.size();
	size_t bomb_len = bomb.size();

	stack<size_t> st;
	deque<char> dq;

	for (size_t i = 0; i < str_len; ++i)
	{
		dq.push_back(str[i]);
		size_t dq_size = dq.size();

		if (str[i] == bomb[0])
		{
			st.push(dq_size - 1);
		}
		if (!st.empty() && str[i] == bomb[bomb_len - 1] && dq.size() >= bomb_len)
		{
			size_t start_idx = st.top();
			st.pop();

			if (start_idx + bomb_len == dq_size) // 폭발 가능
			{
				size_t j = dq.size() - bomb_len;
				bool found = true;

				for (size_t bomb_idx = 0; bomb_idx < bomb_len;)
				{
					if (bomb[bomb_idx++] != dq[j++])
					{
						found = false;
						break;
					}
				}

				if (found)
				{
					for (size_t j = 0; j < bomb_len; ++j)
					{
						dq.pop_back();
					}
				}
				else
				{
					while (!st.empty())
					{
						st.pop();
					}
				}
			}
			else
			{
				while (!st.empty())
				{
					st.pop();
				}
			}
		}
	}

	if (dq.empty())
	{
		cout << "FRULA";
	}
	else
	{
		for (auto a : dq)
		{
			cout << a;
		}
	}

	return 0;
}