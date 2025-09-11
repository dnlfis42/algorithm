#include <iostream>
#include <string>

using namespace std;

int q[10001];
int head;
int tail;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();

	string str;
	while (n--)
	{
		getline(cin, str);
		switch (str[0])
		{
		case 'b':
			if (tail - head)
			{
				cout << q[tail - 1] << '\n';
			}
			else
			{
				cout << "-1\n";
			}
			break;
		case 'e':
			cout << (tail - head == 0) << '\n';
			break;
		case 'f':
			if (tail - head)
			{
				cout << q[head] << '\n';
			}
			else
			{
				cout << "-1\n";
			}
			break;
		case 'p':
			if (str[1] == 'u') // push
			{
				q[tail++] = atoi(&str[5]);
			}
			else // pop
			{
				if (tail - head)
				{
					cout << q[head++] << '\n';
				}
				else
				{
					cout << "-1\n";
				}
			}
			break;
		case 's':
			cout << tail - head << '\n';
			break;
		}
	}

	return 0;
}