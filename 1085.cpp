#include <iostream>
using namespace std;

int main(void)
{
	int x, y;
	int width, height;

	cin >> x >> y >> width >> height;

	
	// 가로 기준 최소 값 구하기
	int ansX = (x <= width - x ? x : width - x);

	// 세로 기준
	int ansY = (y <= height - y ? y : height - y);

	if (ansX <= ansY)
		cout << ansX << endl;
	else
		cout << ansY << endl;
	return 0;
}