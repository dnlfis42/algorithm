#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 20;
const int dr[4]{ -1,0,0,1 };
const int dc[4]{ 0,-1,1,0 };

int ocean[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 공간의 크기
	cin >> n;

	queue<pair<int, int>> q; // row, col

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x;
			cin >> x;

			if (x == 9)
			{
				visited[i][j] = true;
				q.push({ i,j });
			}
			else
			{
				ocean[i][j] = x;
			}
		}
	}

	int shark_size = 2;
	int cur_eat = 0;
	int total_dist = 0;

	int cur_dist = 1;
	while (!q.empty())
	{
		int level_size = q.size();
		vector<pair<int, int>> candidates;

		for (int i = 0; i < level_size; ++i)
		{
			auto [cr, cc] = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int tr = cr + dr[i];
				int tc = cc + dc[i];

				if (tr < 0 || tr >= n || tc < 0 || tc >= n)
				{
					continue;
				}

				if (visited[tr][tc] || ocean[tr][tc] > shark_size)
				{
					continue;
				}

				if (ocean[tr][tc] == 0 || ocean[tr][tc] == shark_size)
				{
					visited[tr][tc] = true;
					q.push({ tr,tc });
				}
				else // ocean[tr][tc] < shark_size -> 먹을 수 있음
				{
					visited[tr][tc] = true;
					candidates.push_back({ tr,tc });
				}
			}
		}

		if (candidates.empty()) // 다음 레벨로 진입
		{
			++cur_dist;
		}
		else
		{
			// 모든 먹이 후보 중에서 가장 먼저 먹어야 할 먹이 후보를 선택
			sort(candidates.begin(), candidates.end());
			auto [r, c] = candidates[0];

			// 총 이동 거리 갱신 및 상어 크기 검사
			total_dist += cur_dist;
			if (shark_size == ++cur_eat)
			{
				++shark_size;
				cur_eat = 0;
			}

			// visit 배열 초기화, q 초기화
			memset(&visited[0][0], 0, MAX_N * MAX_N * sizeof(bool));
			while (!q.empty())
			{
				q.pop();
			}

			ocean[r][c] = 0;
			visited[r][c] = 0;
			q.push({ r,c });
			cur_dist = 1;
		}
	}
	cout << total_dist;

	return 0;
}

int main()
{
	return solution();
}