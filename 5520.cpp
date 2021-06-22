#include <iostream>
#include <vector>
using namespace std;

bool answerExist;
int arr[3][3], moveCnt[9];
vector<int> currentAnswer, candidate;

void GetInput()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
}

void MoveClock(int i, int j)
{
	(arr[i][j] == 3) ? arr[i][j] = 0 : arr[i][j]++;
}

void MoveClockBack(int i, int j)
{
	(arr[i][j] == 0) ? arr[i][j] = 3 : arr[i][j]--;
}

bool IsAnswer()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (arr[i][j] != 0)
				return false;
	
	return true;
}

void Solve(int start)
{
	if (IsAnswer())
	{
		if (!answerExist || candidate.size() < currentAnswer.size())
			currentAnswer = candidate;

		answerExist = true;
		return;
	}

	for (int i = start; i < 10; i++)
	{
		if (moveCnt[i - 1] < 3)
		{
			moveCnt[i - 1]++;
			candidate.push_back(i);
			switch (i)
			{
			case 1:
				MoveClock(0, 0);
				MoveClock(0, 1);
				MoveClock(1, 0);
				MoveClock(1, 1);
				break;
			case 2:
				MoveClock(0, 0);
				MoveClock(0, 1);
				MoveClock(0, 2);
				break;
			case 3:
				MoveClock(0, 1);
				MoveClock(0, 2);
				MoveClock(1, 1);
				MoveClock(1, 2);
				break;
			case 4:
				MoveClock(0, 0);
				MoveClock(1, 0);
				MoveClock(2, 0);
				break;
			case 5:
				MoveClock(0, 1);
				MoveClock(1, 0);
				MoveClock(1, 1);
				MoveClock(1, 2);
				MoveClock(2, 1);
				break;
			case 6:
				MoveClock(0, 2);
				MoveClock(1, 2);
				MoveClock(2, 2);
				break;
			case 7:
				MoveClock(1, 0);
				MoveClock(1, 1);
				MoveClock(2, 0);
				MoveClock(2, 1);
				break;
			case 8:
				MoveClock(2, 0);
				MoveClock(2, 1);
				MoveClock(2, 2);
				break;
			case 9:
				MoveClock(1, 1);
				MoveClock(1, 2);
				MoveClock(2, 1);
				MoveClock(2, 2);
				break;
			}
			Solve(i);
			switch (i)
			{
			case 1:
				MoveClockBack(0, 0);
				MoveClockBack(0, 1);
				MoveClockBack(1, 0);
				MoveClockBack(1, 1);
				break;
			case 2:
				MoveClockBack(0, 0);
				MoveClockBack(0, 1);
				MoveClockBack(0, 2);
				break;
			case 3:
				MoveClockBack(0, 1);
				MoveClockBack(0, 2);
				MoveClockBack(1, 1);
				MoveClockBack(1, 2);
				break;
			case 4:
				MoveClockBack(0, 0);
				MoveClockBack(1, 0);
				MoveClockBack(2, 0);
				break;
			case 5:
				MoveClockBack(0, 1);
				MoveClockBack(1, 0);
				MoveClockBack(1, 1);
				MoveClockBack(1, 2);
				MoveClockBack(2, 1);
				break;
			case 6:
				MoveClockBack(0, 2);
				MoveClockBack(1, 2);
				MoveClockBack(2, 2);
				break;
			case 7:
				MoveClockBack(1, 0);
				MoveClockBack(1, 1);
				MoveClockBack(2, 0);
				MoveClockBack(2, 1);
				break;
			case 8:
				MoveClockBack(2, 0);
				MoveClockBack(2, 1);
				MoveClockBack(2, 2);
				break;
			case 9:
				MoveClockBack(1, 1);
				MoveClockBack(1, 2);
				MoveClockBack(2, 1);
				MoveClockBack(2, 2);
				break;
			}
			candidate.pop_back();
			moveCnt[i - 1]--;
		}
	}
}

int main(void)
{
	GetInput();
	Solve(1);

	for (unsigned int i = 0; i < currentAnswer.size(); i++)
		cout << currentAnswer[i] << ' ';
	cout << '\n';
	
	return 0;
}