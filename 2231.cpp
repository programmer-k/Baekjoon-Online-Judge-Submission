#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cin >> num;

	for (int i = 1; i < num; i++)
	{
		int n = i;

		// �� �ڸ� �� ��� ���ϱ�
		for (int temp = i; temp != 0; temp /= 10)
			n += temp % 10;

		if (n == num)
		{
			cout << i << endl;
			return 0;
		}
	}

	// �����ڰ� ���� ��쿡�� 0�� ����Ѵ�.
	cout << 0 << endl;

	return 0;
}