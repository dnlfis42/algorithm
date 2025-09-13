#include <cstdlib>

#include <iostream>

using namespace std;

int st[10001];
int pos = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		char input[16];
		cin.getline(input, 15);

		switch (input[0])
		{
		case 'e':					// empty
			if (pos)
			{
				cout << "0\n";
			}
			else
			{
				cout << "1\n";
			}
			break;
		case 'p':
			if (input[1] == 'o')	// pop
			{
				if (pos)
				{
					cout << st[--pos] << "\n";
				}
				else
				{
					cout << "-1\n";
				}
			}
			else					// push
			{
				st[pos++] = atoi(&input[5]);
			}
			break;
		case 's':					//size
			cout << pos << "\n";
			break;
		case 't':					//top
			if (pos)
			{
				cout << st[pos - 1] << "\n";
			}
			else
			{
				cout << "-1\n";
			}
			break;
		}
	}

	return 0;
}