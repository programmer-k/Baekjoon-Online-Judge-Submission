/*
���� �̸� : Round 470 Problem C.c
������ : ������
���� ��¥ : 2018�� 3�� 16��
*/

/* �ᱹ �ð��ʰ�... */

// #include <iostream>
// #include <vector>
// using namespace std;

//int main(void)
//{
//	int numOfDays;
//
//	// �Է�
//	cin >> numOfDays;
//
//	vector<int> snowSize;
//	for (int i = 0; i < numOfDays; i++)
//	{
//		int num;
//		cin >> num;
//		snowSize.push_back(num);
//	}
//
//	vector<int> temperature;
//	for (int i = 0; i < numOfDays; i++)
//	{
//		int temp;
//		cin >> temp;
//		temperature.push_back(temp);
//	}
//
//	// ���
//	vector<bool> flag(numOfDays, false);
//	vector<int> meltingSnow(numOfDays, 0);
//
//	for (int i = 0; i < numOfDays; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (!flag[j])
//			{
//				snowSize[j] -= temperature[i];
//				// meltingSnow[j]�� �ƴ϶� [i]�� ����, �� �����̰� �󸶸�ŭ ��ҳ��� �ƴ϶�, �Ϸ翡 �󸶳� ���� ��Ҵ����� ����ؾ� �ϱ� ����
//				meltingSnow[i] += temperature[i];
//
//				// �����̸� ���� ������ŭ �� ���ؾ���.
//				if (snowSize[j] <= 0)
//				{
//					flag[j] = true;
//					meltingSnow[i] += snowSize[j];
//				}
//			}
//		}
//	}
//
//	// ���
//	for (int i = 0; i < meltingSnow.size(); i++)
//		cout << meltingSnow[i] << ' ';
//	return 0;
//}

//int main(void)
//{
//	int numOfDays;
//
//	// �Է�
//	cin >> numOfDays;
//
//	// vector<int> snowSize;
//	int * snowSize = new int[numOfDays];
//	for (int i = 0; i < numOfDays; i++)
//	{
//		int num;
//		cin >> num;
//		snowSize[i] = num;
//	}
//
//	// vector<int> temperature;
//	int * temperature = new int[numOfDays];
//	for (int i = 0; i < numOfDays; i++)
//	{
//		int temp;
//		cin >> temp;
//		temperature[i] = temp;
//	}
//
//	// ���
//	bool * flag = new bool[numOfDays];
//	// vector<bool> flag(numOfDays, false);
//	// vector<int> meltingSnow(numOfDays, 0);
//	int * meltingSnow = new int[numOfDays];
//
//	for (int i = 0; i < numOfDays; i++)
//	{
//		flag[i] = false;
//		meltingSnow[i] = 0;
//	}
//
//	for (int i = 0; i < numOfDays; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (!flag[j])
//			{
//				snowSize[j] -= temperature[i];
//				// meltingSnow[j]�� �ƴ϶� [i]�� ����, �� �����̰� �󸶸�ŭ ��ҳ��� �ƴ϶�, �Ϸ翡 �󸶳� ���� ��Ҵ����� ����ؾ� �ϱ� ����
//				meltingSnow[i] += temperature[i];
//
//				// �����̸� ���� ������ŭ �� ���ؾ���.
//				if (snowSize[j] <= 0)
//				{
//					flag[j] = true;
//					meltingSnow[i] += snowSize[j];
//				}
//			}
//		}
//	}
//
//	// ���
//	for (int i = 0; i < numOfDays; i++)
//		cout << meltingSnow[i] << ' ';
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	int numOfDays;
//
//	// �Է�
//	scanf("%d", &numOfDays);
//
//	// vector<int> snowSize;
//	int * snowSize = (int *) malloc(sizeof(int) * numOfDays);
//	for (int i = 0; i < numOfDays; i++)
//	{
//		scanf("%d", &snowSize[i]);
//	}
//
//	// vector<int> temperature;
//	int * temperature = (int *)malloc(sizeof(int) * numOfDays);
//	for (int i = 0; i < numOfDays; i++)
//	{
//		scanf("%d", &temperature[i]);
//	}
//
//	// ���
//	int * flag = (int *)malloc(sizeof(int) * numOfDays);
//	// vector<bool> flag(numOfDays, false);
//	// vector<int> meltingSnow(numOfDays, 0);
//	int * meltingSnow = (int *)malloc(sizeof(int) * numOfDays);
//
//	for (int i = 0; i < numOfDays; i++)
//	{
//		flag[i] = 0;
//		meltingSnow[i] = 0;
//	}
//
//	for (int i = 0; i < numOfDays; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (!flag[j])
//			{
//				snowSize[j] -= temperature[i];
//				// meltingSnow[j]�� �ƴ϶� [i]�� ����, �� �����̰� �󸶸�ŭ ��ҳ��� �ƴ϶�, �Ϸ翡 �󸶳� ���� ��Ҵ����� ����ؾ� �ϱ� ����
//				meltingSnow[i] += temperature[i];
//
//				// �����̸� ���� ������ŭ �� ���ؾ���.
//				if (snowSize[j] <= 0)
//				{
//					flag[j] = 1;
//					meltingSnow[i] += snowSize[j];
//				}
//			}
//		}
//	}
//
//	// ���
//	for (int i = 0; i < numOfDays; i++)
//		printf("%d ", meltingSnow[i]);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numOfDays;

	// �Է�
	scanf("%d", &numOfDays);

	// vector<int> snowSize;
	int * snowSize = (int *)malloc(sizeof(int) * numOfDays);
	for (int i = 0; i < numOfDays; i++)
	{
		scanf("%d", &snowSize[i]);
	}

	// vector<int> temperature;
	int * temperature = (int *)malloc(sizeof(int) * numOfDays);
	for (int i = 0; i < numOfDays; i++)
	{
		scanf("%d", &temperature[i]);
	}

	// ���
	int * flag = (int *)malloc(sizeof(int) * numOfDays);
	// vector<bool> flag(numOfDays, false);
	// vector<int> meltingSnow(numOfDays, 0);
	int * meltingSnow = (int *)malloc(sizeof(int) * numOfDays);

	// i��° ������ ��� ��(�µ�)�� ���� �迭�� �����ؼ� �����Ѵ�.
	int * meltingSnowSum = (int *)malloc(sizeof(int) * numOfDays);

	for (int i = 0; i < numOfDays; i++)
	{
		meltingSnowSum[i] = 0;
		for (int j = 0; j <= i; j++)
		{
			meltingSnowSum[i] += temperature[j];
		}
	}

	// ���� Ž��
	int idx = BinarySearch()

	for (int i = 0; i < numOfDays; i++)
	{
		flag[i] = 0;
		meltingSnow[i] = 0;
	}

	

	// ���
	for (int i = 0; i < numOfDays; i++)
		printf("%d ", meltingSnow[i]);
	return 0;
}