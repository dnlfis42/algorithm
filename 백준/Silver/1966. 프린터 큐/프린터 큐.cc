#include <iostream>

using namespace std;

struct Node
{
	int priority;
	Node* next;
};

Node nodes[101];
Node head;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n; // 문서 개수
		int m; // 확인해야 할 문서 위치
		cin >> n >> m;

		Node* prev = &head; // 마지막 이전 문서
		Node* last = &nodes[0]; // 마지막 문서
		Node* node = &nodes[m]; // 출력할 문서

		int p_counter[10]{};
		int priority; // 중요도
		int cnt = 0; // 출력 순번

		for (int i = 0; i < n; ++i)
		{
			cin >> priority;
			++p_counter[priority];

			prev->next = last;
			prev = last++;
			prev->priority = priority;
			prev->next = &head;
		}

		last = prev; // 마지막 문서 위치 조정(끝 다음이 아닌 끝으로)

		bool found = false;
		Node* cur;
		for (int i = 9; i > 0; --i)
		{
			while (p_counter[i])
			{
				cur = head.next;
				if (cur->priority == i)
				{
					head.next = cur->next;
					--p_counter[i];
					++cnt;
					if (cur == node)
					{
						found = true;
						break;
					}
				}
				else
				{
					head.next = cur->next;
					last->next = cur;
					cur->next = &head;

					last = cur;
				}
			}

			if (found)
			{
				break;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}