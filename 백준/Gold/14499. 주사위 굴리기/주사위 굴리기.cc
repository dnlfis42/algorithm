#include <iostream>

using namespace std;

int row; // 세로
int col; // 가로
int y; // 주사위 y 좌표
int x; // 주사위 x 좌표
int k;

int field[21][21];
int dice_top;
int dice_east;
int dice_west;
int dice_north;
int dice_south;
int dice_down;

static void copy_and_print()
{
	if (field[y][x] == 0)
	{
		field[y][x] = dice_down;
	}
	else
	{
		dice_down = field[y][x];
		field[y][x] = 0;
	}

	cout << dice_top << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> row >> col >> y >> x >> k;

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			cin >> field[r][c];
		}
	}

	int temp;
	int dir;
	while (cin >> dir)
	{
		switch (dir)
		{
		case 1: // 동
			if (x < col - 1)
			{
				++x;

				temp = dice_east;
				dice_east = dice_top;
				dice_top = dice_west;
				dice_west = dice_down;
				dice_down = temp;

				copy_and_print();
			}
			break;
		case 2: // 서
			if (x > 0)
			{
				--x;

				temp = dice_west;
				dice_west = dice_top;
				dice_top = dice_east;
				dice_east = dice_down;
				dice_down = temp;

				copy_and_print();
			}
			break;
		case 3: // 북
			if (y > 0)
			{
				--y;

				temp = dice_north;
				dice_north = dice_top;
				dice_top = dice_south;
				dice_south = dice_down;
				dice_down = temp;

				copy_and_print();
			}
			break;
		case 4: // 남
			if (y < row - 1)
			{
				++y;

				temp = dice_south;
				dice_south = dice_top;
				dice_top = dice_north;
				dice_north = dice_down;
				dice_down = temp;

				copy_and_print();
			}
			break;
		}
	}

	return 0;
}