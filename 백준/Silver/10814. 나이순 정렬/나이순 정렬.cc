#include <bits/stdc++.h>

using namespace std;

struct User
{
	string name;
	User* next;
};

User head[201];
User* tail[201];

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 200; ++i)
	{
		tail[i] = &head[i];
	}

	int n; // 회원의 수
	cin >> n;

	while (n--)
	{
		int age;
		string name;
		cin >> age >> name;
		User* user = new User{ name,nullptr };
		tail[age]->next = user;
		tail[age] = user;
	}

	for (int i = 1; i <= 200; ++i)
	{
		User* user = head[i].next;
		while (user)
		{
			cout << i << " " << user->name << "\n";
			user = user->next;
		}
	}

	return 0;
}

int main()
{
	return solution();
}