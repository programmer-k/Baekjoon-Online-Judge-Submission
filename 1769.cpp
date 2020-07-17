/*
���� �̸� : 1769.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

/* �־����� �Է��� �鸸 ������ �ڿ����� �ƴ϶� �鸸 �ڸ� ������ �ڿ������� long long���ε� Ŀ���� �Ұ�����. */
/* ���̽����ε� �õ��ߴµ� �ð� �ʰ��� ����. */
/* �׷��� �ٽ� C++���� ���ڸ� string ��ü�� �����ϴ� ����� �̿��ؼ� ǰ. */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void)
{
	string numStr;
	int cnt = 0, sum;

	// �Է�
	cin >> numStr;
	
	// �� �ڸ����� ��쿡�� �������� �ʰ� �ٷ� ���
	if (numStr.length() >= 2)
	{
		int num;

		// �� �� ��ȯ�ϸ� ���� ū ��� �鸸 �ڸ��� �����̸鼭 ��� �ڸ����� 9�� �� �̰��� �� ���ϸ� 9�� �鸸 �� ���ϴ� ���̹Ƿ� 9 * �鸸�� �ص�
		// 9�鸸�̹Ƿ� int���� �ȿ� ����� ��. �׷��Ƿ� �� ���� ��ȯ�ϰ��� �״������ʹ� ���� ���� ����� ����ص� ��.
		// ������ �������Ƿ� �׳� ù ��° ����� ��� ����ϰ���.

		while (true)
		{
			sum = 0;
			// ���ڸ��� ���� �� ���ϱ�
			for (int i = 0; i < numStr.length(); i++)
			{
				sum += numStr[i] - '0';
			}

			// �� �� �ݺ������Ƿ� ����
			cnt++;

			// �� �ڸ����� �ݺ� ����
			if (sum < 10)
				break;

			numStr = to_string(sum);
		}
	}
	else
	{
		sum = atoi(numStr.c_str());
	}

	// �ݺ��� �� �� �ߴ��� ���
	cout << cnt << endl;

	// 3�� ������� �˻�
	if (sum % 3 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}