/*
파일 이름 : Round 470 Problem C.c
제작자 : 정지운
제작 날짜 : 2018년 3월 16일
*/

/* 결국 시간초과... */

// #include <iostream>
// #include <vector>
// using namespace std;

//int main(void)
//{
//	int numOfDays;
//
//	// 입력
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
//	// 계산
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
//				// meltingSnow[j]가 아니라 [i]인 것은, 각 눈덩이가 얼마만큼 녹았나가 아니라, 하루에 얼마나 눈이 녹았는지를 출력해야 하기 때문
//				meltingSnow[i] += temperature[i];
//
//				// 음수이면 많이 깎은만큼 더 더해야함.
//				if (snowSize[j] <= 0)
//				{
//					flag[j] = true;
//					meltingSnow[i] += snowSize[j];
//				}
//			}
//		}
//	}
//
//	// 출력
//	for (int i = 0; i < meltingSnow.size(); i++)
//		cout << meltingSnow[i] << ' ';
//	return 0;
//}

//int main(void)
//{
//	int numOfDays;
//
//	// 입력
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
//	// 계산
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
//				// meltingSnow[j]가 아니라 [i]인 것은, 각 눈덩이가 얼마만큼 녹았나가 아니라, 하루에 얼마나 눈이 녹았는지를 출력해야 하기 때문
//				meltingSnow[i] += temperature[i];
//
//				// 음수이면 많이 깎은만큼 더 더해야함.
//				if (snowSize[j] <= 0)
//				{
//					flag[j] = true;
//					meltingSnow[i] += snowSize[j];
//				}
//			}
//		}
//	}
//
//	// 출력
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
//	// 입력
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
//	// 계산
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
//				// meltingSnow[j]가 아니라 [i]인 것은, 각 눈덩이가 얼마만큼 녹았나가 아니라, 하루에 얼마나 눈이 녹았는지를 출력해야 하기 때문
//				meltingSnow[i] += temperature[i];
//
//				// 음수이면 많이 깎은만큼 더 더해야함.
//				if (snowSize[j] <= 0)
//				{
//					flag[j] = 1;
//					meltingSnow[i] += snowSize[j];
//				}
//			}
//		}
//	}
//
//	// 출력
//	for (int i = 0; i < numOfDays; i++)
//		printf("%d ", meltingSnow[i]);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numOfDays;

	// 입력
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

	// 계산
	int * flag = (int *)malloc(sizeof(int) * numOfDays);
	// vector<bool> flag(numOfDays, false);
	// vector<int> meltingSnow(numOfDays, 0);
	int * meltingSnow = (int *)malloc(sizeof(int) * numOfDays);

	// i번째 날까지 녹는 눈(온도)의 합을 배열로 생성해서 저장한다.
	int * meltingSnowSum = (int *)malloc(sizeof(int) * numOfDays);

	for (int i = 0; i < numOfDays; i++)
	{
		meltingSnowSum[i] = 0;
		for (int j = 0; j <= i; j++)
		{
			meltingSnowSum[i] += temperature[j];
		}
	}

	// 이진 탐색
	int idx = BinarySearch()

	for (int i = 0; i < numOfDays; i++)
	{
		flag[i] = 0;
		meltingSnow[i] = 0;
	}

	

	// 출력
	for (int i = 0; i < numOfDays; i++)
		printf("%d ", meltingSnow[i]);
	return 0;
}