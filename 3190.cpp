#include <iostream>
#include <utility>
#include <deque>
#include <queue>
using namespace std;

bool RemoveAppleIfExist(pair<int, int> head, vector<pair<int, int>>& apple);
bool IsGameOver(deque<pair<int, int>>& snake, int n);
void ChangeDirection(pair<int, int>& direction, char movement);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int n, k, l, time = 0;
	pair<int, int> direction(0, 1);
	deque<pair<int, int>> snake;
	queue<pair<int, char>> movements;
	vector<pair<int, int>> apple;
	
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		apple.push_back(p);
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		pair<int, char> p;
		cin >> p.first >> p.second;
		movements.push(p);
	}

	snake.push_back(make_pair(1, 1));
	pair<int, char> movement = movements.front();
	movements.pop();
	while (true)
	{
		// 이동
		pair<int, int> temp = snake.front();
		snake.push_front(make_pair(temp.first + direction.first, temp.second + direction.second));
		
		time++;

		// 범위 확인
		if (IsGameOver(snake, n))
			break;

		// 사과 지우기, 꼬리 당기기
		if (!RemoveAppleIfExist(snake.front(), apple))
			snake.pop_back();

		// 방향 전환
		if (movement.first == time)
		{
			ChangeDirection(direction, movement.second);

			if (movements.empty())
				movement.first = -1;
			else
			{
				movement = movements.front();
				movements.pop();
			}

		}
	}

	cout << time << endl;

	return 0;
}

bool RemoveAppleIfExist(pair<int, int> head, vector<pair<int, int>>& apple)
{
	int row = head.first;
	int col = head.second;

	for (unsigned int i = 0; i < apple.size(); i++)
	{
		if (apple[i].first == row && apple[i].second == col)
		{
			// 사과 지우기
			apple.erase(apple.begin() + i);
			return true;
		}
	}

	return false;
}

bool IsGameOver(deque<pair<int, int>>& snake, int n)
{
	pair<int, int> head = snake.front();

	// 보드 밖인지 확인
	if (head.first > n || head.second > n || head.first <= 0 || head.second <= 0)
		return true;

	// 자기 자신과 부딪혔는가
	for (unsigned int i = 1; i < snake.size(); i++)
		if (head.first == snake[i].first && head.second == snake[i].second)
			return true;

	return false;
}

void ChangeDirection(pair<int, int>& direction, char movement)
{
	if (direction.first == 1 && direction.second == 0)
	{
		direction.first = 0;
		direction.second = movement == 'L' ? 1 : -1;
	}
	else if (direction.first == 0 && direction.second == -1)
	{
		direction.first = movement == 'L' ? 1 : -1;
		direction.second = 0;
	}
	else if (direction.first == -1 && direction.second == 0)
	{
		direction.first = 0;
		direction.second = movement == 'L' ? -1 : 1;
	}
	else
	{
		direction.first = movement == 'L' ? -1 : 1;
		direction.second = 0;
	}
}