#include <iostream>

using namespace std;

int matrix[40][5][5];	// 각 단계(2^m)에 해당하는 거듭제곱 행렬
bool pos[40];			// 지수 b의 이진수 표현 (각 비트가 1인지 여부)
int ans[5][5];
int temp[5][5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long b;
	cin >> n >> b;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> matrix[0][i][j];
		}

		ans[i][i] = 1;
	}

	// b를 2진수로 분해해 pos 배열에 저장
	int idx = 0;
	while (b)
	{
		pos[idx++] = (b % 2);
		b >>= 1;
	}

	// 2^m 에 맞는 행렬 계산
	for (int m = 1; m < idx; ++m)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					matrix[m][i][j] += matrix[m - 1][i][k] * matrix[m - 1][k][j];
				}
				matrix[m][i][j] %= 1000;
			}
		}
	}

	for (int p = 0; p < idx; ++p)
	{
		if (pos[p])
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					temp[i][j] = 0;
					for (int k = 0; k < n; ++k)
					{
						temp[i][j] += ans[i][k] * matrix[p][k][j];
					}
					temp[i][j] %= 1000;
				}
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					ans[i][j] = temp[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}