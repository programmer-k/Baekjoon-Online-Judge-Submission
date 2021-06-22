#include <iostream>
using namespace std;

int ground[250000];
int n, m, b;
int minTime = 1234567890, maxHeight;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> b;
	
	for (int i = 0; i < n * m; i++)
		cin >> ground[i];
}

void Solve(int height)
{
	int curTime = 0, blocks = b;

	for (int i = 0; i < n * m; i++)
	{
		if (ground[i] > height)
		{
			int diff = ground[i] - height;
			curTime += diff * 2;
			blocks += diff;
		}
		else if (ground[i] < height)
		{
			int diff = height - ground[i];
			curTime += diff;
			blocks -= diff;
		}
	}

	if (blocks < 0)
		return;

	if (curTime < minTime)
	{
		minTime = curTime;
		maxHeight = height;
	}
	else if (curTime == minTime)
		maxHeight = max(height, maxHeight);
}

int main(void)
{
	GetInput();

	for (int i = 0; i <= 256; i++)
		Solve(i);
	
	cout << minTime << ' ' << maxHeight << '\n';
	return 0;
}