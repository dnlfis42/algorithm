#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<int> q;

	int n;
	cin >> n;
	cin.ignore();

	while (n--)
	{
		string cmd;
		getline(cin, cmd);

		if (cmd[0] == 'p') // push, pop
		{
			if (cmd[1] == 'u') // push
			{
				int num = atoi(&cmd[5]);
				q.push(num);
			}
			else // pop
			{
				if (q.empty())
				{
					cout << -1;
				}
				else
				{
					cout << q.front();
					q.pop();
				}
				cout << '\n';
			}
		}
		else if (cmd[0] == 's') // size
		{
			cout << q.size() << '\n';
		}
		else if (cmd[0] == 'e') // empty
		{
			if (q.empty())
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
			cout << '\n';
		}
		else if (cmd[0] == 'f') // front
		{
			if (q.empty())
			{
				cout << -1;
			}
			else
			{
				cout << q.front();
			}
			cout << '\n';
		}
		else // back
		{
			if (q.empty())
			{
				cout << -1;
			}
			else
			{
				cout << q.back();
			}
			cout << '\n';
		}
	}

	return 0;
}