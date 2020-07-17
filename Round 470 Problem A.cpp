/*
���� �̸� : Round 470 Problem A.cpp
������ : ������
���� ��¥ : 2018�� 3�� 18��
*/

#include <iostream>
using namespace std;

char map[500][500];

int main(void)
{
	int row, col;

	// �Է�
	cin >> row >> col;

	// �� �Է�
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
		}
	}

	// �� �ֺ��� �� ��ġ�ϱ�
	bool protect = true;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == 'S')
			{
				// �ε��� ���� �Ѿ������ �����ϱ�
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

	// ���
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