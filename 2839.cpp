/*
���� �̸� : 2839.cpp
������ : ������
���� ��¥ : 2017�� 4�� 2��
���α׷� �뵵 : ����̰� ���� ������ �� �� �������� �ϴ��� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n, rem;
	int sugar3 = 0;
	int sugar5;

	cin >> n;
	
	// sugar--;�� while���� �ι�°�� �� ������ ������ ���� ����� ������ �ȳ��� while�� body�� ������ ����.
	sugar5 = n / 5;
	rem = n - (sugar5 * 5);
	sugar3 = rem / 3;

	// 5kg ���븦 �ִ�� �������, �ϳ��� ���̸鼭 ��Ȯ�� �Űܾ� �Ǵ� kg�� ã�Ƴ���.
	while ((sugar5 * 5 + sugar3 * 3) != n)
	{
		sugar5--;
		
		// sugar5�� ���� -1�� �Ǹ�, ���� ���� �� ���ٴ� ���̹Ƿ� -1�� ����ϰ� ���α׷��� �����Ѵ�.
		if (sugar5 == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		rem = n - (sugar5 * 5);
		sugar3 = rem / 3;
		
	}

	cout << sugar5 + sugar3 << endl;
	return 0;
}