/*
파일 이름 : Round 470 Problem A.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 18일
*/

#include <iostream>
using namespace std;

char map[500][500];

int main(void)
{
	int row, col;

	// 입력
	cin >> row >> col;

	// 맵 입력
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
		}
	}

	// 양 주변에 개 배치하기
	bool protect = true;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == 'S')
			{
				// 인덱스 범위 넘어갔는지도 조사하기
				if (i != 0 && map[i - 1][j] == '.')
					map[i - 1][j] = 'D';
				else if (i != 0 && map[i - 1][j] == 'W')
					protect = false;
				
				if (i != row - 1 && map[i + 1][j] == '.')
					map[i + 1][j] = 'D';
				else if (i != row - 1 && map[i + 1][j] == 'W')
					protect = false;

				if (j != col - 1 && map[i][j + 1] == '.')
					map[i][j + 1] = 'D';
				else if (j != col - 1 && map[i][j + 1] == 'W')
					protect = false;

				if (j != 0 && map[i][j - 1] == '.')
					map[i][j - 1] = 'D';
				else if (j != 0 && map[i][j - 1] == 'W')
					protect = false;
			}
		}
	}

	// 출력
	if (protect)
	{
		cout << "Yes" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}