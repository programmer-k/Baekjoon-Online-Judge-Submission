/*
파일 이름 : 4963.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 7일
*/

/*
컴퓨터 프로그래밍 수업에서 세포 관련 시뮬레이션 과제처럼 한 점을 기준으로 주변에 있는 모든 점들을 검사하고 넘어가는 방식을 사용.
물론 인덱스 범위를 벗어나는 것도 고려해서 코드를 작성해야 함.
DFS 비슷하게 작성을 했는데 스택을 사용하지는 않았음.
검사는 벡터에 그 점이 등록이 되어 있으면 이미 추가한 땅이므로 건너뛰고,
그렇지 않다면 등록을 한 다음에 주변에 땅이 있는지 찾고, 땅이 있다면 그 땅을 기준으로 또 주변에 땅이 있는지를 검사한다.

사실, 위에서처럼 코딩을 해야겠다고 생각하고 시작을 했는데, 주어진 tc를 돌려보면 계속해서 오답이 나와서 결국은 그 날에 못 풀고
며칠 후에 다시 풀었다.
문제가 tc가
2 2
0 1
1 0
이런 식으로 주어질 때, 1이 아니라 2가 출력되었는데,
디버깅을 하다보니, 오른쪽 위에 있는 1에서 왼쪽 아래에 있는 1을 찾았는데, 검사를 마친 후에 섬의 개수를 1개 올리기 전에 벡터에 등록된 점들을
출력해보니 왼쪽 아래 것이 추가가 되지 않아 있었다.
그래서 왼쪽 아래의 1을 기준으로 다시 섬이 추가가 되어 버린 것이었다.

틀린 부분은 Search 함수에서 주변에 땅을 발견한 후에 그 땅을 기준으로 주변에 땅이 있는지 검사를 해야하므로, 기준점을 새로운 섬으로 해 놓았어야 했는데,
그 값을 변경하지 않고 그대로 줘버려서 문제가 생겨버린 것이었다.

그리고 참고로 VS에서 주석 처리는 Ctrl + K + C를 누르면 된다.
*/

#include <iostream>
#include <vector>
using namespace std;

// 공간(점) 하나의 데이터를 표현하는 Point 구조체
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

		// 맵의 너비와 높이 입력
		cin >> width >> height;

		// 입력이 0, 0이면 프로그램 종료
		if (width == 0 && height == 0)
			break;

		// 맵을 저장할 2차원 배열
		int map[50][50];		// 일단 최대 크기로 잡아놓고 필요한 만큼만 쓴다.

		// 배열 초기화
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
				map[i][j] = -1;
		}

		// 맵 상태 입력
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cin >> map[i][j];
		}

		// 맵 상태 출력
		// 여기까지는 문제 없음.
		/*for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << map[i][j] << ' ';
			cout << endl;
		}*/

		// 이미 검사한 공간(점)에 대해서는 이 벡터에 추가해서 중복으로 등록하지 못하게 한다.
		vector<Point> vec;

		int cnt = 0;
		

		// 모든 점에 대해서 검사하기
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				// 육지이면 검사 시작
				if (map[i][j] == 1)
				{
					if (Search(map, width, height, vec, i, j))
					{
						/*cout << "cnt를 증가시킬 때 i, j의 값" << endl;
						cout << "i: " << i << " j: " << j << endl;*/

						// 벡터 전체 데이터 출력
						/*cout << "벡터 전체 데이터 출력" << endl;
						for (int a = 0; a < vec.size(); a++)
							cout << "xPos: " << vec[a].xPos << " yPos: " << vec[a].yPos << endl;*/
						
						cnt++;
					}
				}
				// 바다이면 검사할 필요 없이 다음으로 넘어간다.
				else if (map[i][j] == 0)
					continue;
			}
		}

		// 섬의 개수 출력
		cout << /*"섬의 개수: " <<*/ cnt << endl;

		//cout << "벡터에 등록되어 있는 i, j" << endl;
		/*for (int i = 0; i < vec.size(); i++)
			cout << vec[i].xPos << ' ' << vec[i].yPos << endl;*/
		vec.clear();
	}
	return 0;
}

bool Search(int map[50][50], int width, int height, vector<Point>& vec, int i, int j)
{
	// 현재의 점에 대해서 벡터에 등록이 되어 있는지 확인하기
	for (int k = 0; k < vec.size(); k++)
	{
		// 등록 되어 있으면 검색 종료
		if (i == vec[k].yPos && j == vec[k].xPos)
		{
			return false;
		}
	}

	// 등록 되지 않았으면 추가
	Point point = { j, i };
	vec.push_back(point);

	// 12시부터 시계방향으로 검사 시작!
	// 인덱스 범위를 벗어나는지도 확인할 것!
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
		/*cout << "왼쪽 아래 찾음!" << endl;*/
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
