#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	stack<int> st;
	int num;
	while (k--)
	{
		cin >> num;
		if (num)
		{
			st.push(num);
		}
		else
		{
			st.pop();
		}
	}

	int sum = 0;
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;

	return 0;
}