#include <iostream>
using namespace std;

int main(void)
{
	int x, y;
	int width, height;

	cin >> x >> y >> width >> height;

	
	// ���� ���� �ּ� �� ���ϱ�
	int ansX = (x <= width - x ? x : width - x);

	// ���� ����
	int ansY = (y <= height - y ? y : height - y);

	if (ansX <= ansY)
		cout << ansX << endl;
	else
		cout << ansY << endl;
	return 0;
}