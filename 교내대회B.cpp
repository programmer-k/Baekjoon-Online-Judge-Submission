#include <iostream>
using namespace std;

int n, heartPosX, heartPosY;
int leftArm, rightArm, waist, leftLeg, rightLeg;
char square[1000][1000];

void GetInput()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> square[i][j];
}

void FindHeartPosition()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (square[i][j] == '*')
			{
				heartPosX = i + 2;
				heartPosY = j + 1;
				return;
			}
		}
	}
}

void CalcBodyLength()
{
	for (int i = heartPosY - 2; i >= 0; i--)
	{
		if (square[heartPosX - 1][i] == '*')
			leftArm++;
	}

	for (int i = heartPosY; i < n; i++)
	{
		if (square[heartPosX - 1][i] == '*')
			rightArm++;
	}

	int endOfWaist = -1;
	for (int i = heartPosX; i < n; i++)
	{
		if (square[i][heartPosY - 1] == '*')
			waist++;
		else
		{
			endOfWaist = i;
			break;
		}
	}

	for (int i = endOfWaist; i < n; i++)
		if (square[i][heartPosY - 2] == '*')
			leftLeg++;

	for (int i = endOfWaist; i < n; i++)
		if (square[i][heartPosY] == '*')
			rightLeg++;
}

void PrintResult()
{
	cout << heartPosX << ' ' << heartPosY << '\n';
	cout << leftArm << ' ' << rightArm << ' ' << waist << ' ' << leftLeg << ' ' << rightLeg << '\n';
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	GetInput();
	FindHeartPosition();
	CalcBodyLength();
	PrintResult();
	return 0;
}