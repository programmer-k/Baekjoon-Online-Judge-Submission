/*
���� �̸� : 9506.cpp
������ : ������
���� ��¥ : 2018�� 3�� 4��
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	while (true)
	{
		int num;

		// �Է�
		cin >> num;

		// �Է��� ���ڰ� -1�̸� ���α׷� ����
		if (num == -1)
			break;

		// ������� ������ ����
		vector<int> arr;

		// ��� ����� ���ؼ� ���Ϳ� �߰�
		for (int i = 1; i < num; i++)
		{
			if (num % i == 0)
				arr.push_back(i);
		}

		// ��� ������� �� ���ϱ�
		int sum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr[i];
		}

		// �Է¹��� ���� �Ϻ��� ������ �����ϰ� �׿� ���� ����ϱ�
		if (num == sum)
		{
			cout << num << " = ";

			for (int i = 0; i < arr.size(); i++)
			{
				// ������ ���ڴ� ���� �ڿ� ����� ���ϱ� ��ȣ�� ������� ����.
				if (i == arr.size() - 1)
					cout << arr[i] << endl;
				else
				{
					cout << arr[i] << " + ";
				}
			}
		}
		else
		{
			cout << num << " is NOT perfect." << endl;
		}
	}
	return 0;
}