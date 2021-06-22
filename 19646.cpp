#include <iostream>
using namespace std;

int n, w[200001], p[200001];
int seg[200001 * 4];
int out;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++)
		cin >> p[i];
}

int CreateSegmentTree(int startIdx, int endIdx, int currentIdx)
{
	if (startIdx == endIdx)
		return seg[currentIdx] = w[startIdx];
	else
	{
		int mid = (startIdx + endIdx) / 2;

		int temp1 = CreateSegmentTree(startIdx, mid, 2 * currentIdx);
		int temp2 = CreateSegmentTree(mid + 1, endIdx, 2 * currentIdx + 1);
		return seg[currentIdx] = temp1 + temp2;
	}
}

int Solve2(int startIdx, int endIdx, int currentIdx, int pVal)
{
	if (startIdx == endIdx)
		return startIdx;
	
	int mid = (startIdx + endIdx) / 2;

	if (seg[2 * currentIdx] >= pVal)
		return Solve2(startIdx, mid, 2 * currentIdx, pVal);
	else
		return Solve2(mid + 1, endIdx, 2 * currentIdx + 1, pVal - seg[2 * currentIdx]);
}

int Solve3(int startIdx, int endIdx, int currentIdx)
{
	if (out > endIdx || out < startIdx)
		return seg[currentIdx];
	else if (startIdx == endIdx)
		return seg[currentIdx] = 0;
	else
	{
		int mid = (startIdx + endIdx) / 2;

		int temp1 = Solve3(startIdx, mid, 2 * currentIdx);
		int temp2 = Solve3(mid + 1, endIdx, 2 * currentIdx + 1);
		return seg[currentIdx] = temp1 + temp2;
	}
}

void Solve1()
{
	CreateSegmentTree(1, n, 1);

	for (int i = 1; i <= n; i++)
	{
		cout << (out = Solve2(1, n, 1, p[i])) << ' ';
		Solve3(1, n, 1);
	}
}

int main(void)
{
	GetInput();
	Solve1();
	return 0;
}