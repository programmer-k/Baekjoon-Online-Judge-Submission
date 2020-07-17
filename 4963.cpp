/*
���� �̸� : 4963.cpp
������ : ������
���� ��¥ : 2018�� 3�� 7��
*/

/*
��ǻ�� ���α׷��� �������� ���� ���� �ùķ��̼� ����ó�� �� ���� �������� �ֺ��� �ִ� ��� ������ �˻��ϰ� �Ѿ�� ����� ���.
���� �ε��� ������ ����� �͵� ����ؼ� �ڵ带 �ۼ��ؾ� ��.
DFS ����ϰ� �ۼ��� �ߴµ� ������ ��������� �ʾ���.
�˻�� ���Ϳ� �� ���� ����� �Ǿ� ������ �̹� �߰��� ���̹Ƿ� �ǳʶٰ�,
�׷��� �ʴٸ� ����� �� ������ �ֺ��� ���� �ִ��� ã��, ���� �ִٸ� �� ���� �������� �� �ֺ��� ���� �ִ����� �˻��Ѵ�.

���, ������ó�� �ڵ��� �ؾ߰ڴٰ� �����ϰ� ������ �ߴµ�, �־��� tc�� �������� ����ؼ� ������ ���ͼ� �ᱹ�� �� ���� �� Ǯ��
��ĥ �Ŀ� �ٽ� Ǯ����.
������ tc��
2 2
0 1
1 0
�̷� ������ �־��� ��, 1�� �ƴ϶� 2�� ��µǾ��µ�,
������� �ϴٺ���, ������ ���� �ִ� 1���� ���� �Ʒ��� �ִ� 1�� ã�Ҵµ�, �˻縦 ��ģ �Ŀ� ���� ������ 1�� �ø��� ���� ���Ϳ� ��ϵ� ������
����غ��� ���� �Ʒ� ���� �߰��� ���� �ʾ� �־���.
�׷��� ���� �Ʒ��� 1�� �������� �ٽ� ���� �߰��� �Ǿ� ���� ���̾���.

Ʋ�� �κ��� Search �Լ����� �ֺ��� ���� �߰��� �Ŀ� �� ���� �������� �ֺ��� ���� �ִ��� �˻縦 �ؾ��ϹǷ�, �������� ���ο� ������ �� ���Ҿ�� �ߴµ�,
�� ���� �������� �ʰ� �״�� ������� ������ ���ܹ��� ���̾���.

�׸��� ����� VS���� �ּ� ó���� Ctrl + K + C�� ������ �ȴ�.
*/

#include <iostream>
#include <vector>
using namespace std;

// ����(��) �ϳ��� �����͸� ǥ���ϴ� Point ����ü
struct Point
{
	int xPos;
	int yPos;
};

bool Search(int map[50][50], int width, int height, vector<Point>& vec, int i, int j);

int main(void)
{
	while (true)
	{
		int width, height;

		// ���� �ʺ�� ���� �Է�
		cin >> width >> height;

		// �Է��� 0, 0�̸� ���α׷� ����
		if (width == 0 && height == 0)
			break;

		// ���� ������ 2���� �迭
		int map[50][50];		// �ϴ� �ִ� ũ��� ��Ƴ��� �ʿ��� ��ŭ�� ����.

		// �迭 �ʱ�ȭ
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
				map[i][j] = -1;
		}

		// �� ���� �Է�
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cin >> map[i][j];
		}

		// �� ���� ���
		// ��������� ���� ����.
		/*for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << map[i][j] << ' ';
			cout << endl;
		}*/

		// �̹� �˻��� ����(��)�� ���ؼ��� �� ���Ϳ� �߰��ؼ� �ߺ����� ������� ���ϰ� �Ѵ�.
		vector<Point> vec;

		int cnt = 0;
		

		// ��� ���� ���ؼ� �˻��ϱ�
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				// �����̸� �˻� ����
				if (map[i][j] == 1)
				{
					if (Search(map, width, height, vec, i, j))
					{
						/*cout << "cnt�� ������ų �� i, j�� ��" << endl;
						cout << "i: " << i << " j: " << j << endl;*/

						// ���� ��ü ������ ���
						/*cout << "���� ��ü ������ ���" << endl;
						for (int a = 0; a < vec.size(); a++)
							cout << "xPos: " << vec[a].xPos << " yPos: " << vec[a].yPos << endl;*/
						
						cnt++;
					}
				}
				// �ٴ��̸� �˻��� �ʿ� ���� �������� �Ѿ��.
				else if (map[i][j] == 0)
					continue;
			}
		}

		// ���� ���� ���
		cout << /*"���� ����: " <<*/ cnt << endl;

		//cout << "���Ϳ� ��ϵǾ� �ִ� i, j" << endl;
		/*for (int i = 0; i < vec.size(); i++)
			cout << vec[i].xPos << ' ' << vec[i].yPos << endl;*/
		vec.clear();
	}
	return 0;
}

bool Search(int map[50][50], int width, int height, vector<Point>& vec, int i, int j)
{
	// ������ ���� ���ؼ� ���Ϳ� ����� �Ǿ� �ִ��� Ȯ���ϱ�
	for (int k = 0; k < vec.size(); k++)
	{
		// ��� �Ǿ� ������ �˻� ����
		if (i == vec[k].yPos && j == vec[k].xPos)
		{
			return false;
		}
	}

	// ��� ���� �ʾ����� �߰�
	Point point = { j, i };
	vec.push_back(point);

	// 12�ú��� �ð�������� �˻� ����!
	// �ε��� ������ ��������� Ȯ���� ��!
	if (map[i - 1][j] == 1 && i != 0)
	{
		Search(map, width, height, vec, i - 1, j);
	}
	if (map[i - 1][j + 1] == 1 && i != 0 && j != width - 1)
	{
		Search(map, width, height, vec, i - 1, j + 1);
	}
	if (map[i][j + 1] == 1 && j != width - 1)
	{
		Search(map, width, height, vec, i, j + 1);
	}
	if (map[i + 1][j + 1] == 1 && i != height - 1 && j != width - 1)
	{
		Search(map, width, height, vec, i + 1, j + 1);
	}
	if (map[i + 1][j] == 1 && i != height - 1)
	{
		Search(map, width, height, vec, i + 1, j);
	}
	if (map[i + 1][j - 1] == 1 && i != height - 1 && j != 0)
	{
		/*cout << "���� �Ʒ� ã��!" << endl;*/
		Search(map, width, height, vec, i + 1, j - 1);
	}
	if (map[i][j - 1] == 1 && j != 0)
	{
		Search(map, width, height, vec, i, j - 1);
	}
	if (map[i - 1][j - 1] == 1 && i != 0 && j != 0)
	{
		Search(map, width, height, vec, i - 1, j - 1);
	}

	return true;
}
