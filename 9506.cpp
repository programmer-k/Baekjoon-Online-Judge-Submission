/*
파일 이름 : 9506.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	while (true)
	{
		int num;

		// 입력
		cin >> num;

		// 입력한 숫자가 -1이면 프로그램 종료
		if (num == -1)
			break;

		// 약수들을 저장할 벡터
		vector<int> arr;

		// 모든 약수를 구해서 벡터에 추가
		for (int i = 1; i < num; i++)
		{
			if (num % i == 0)
				arr.push_back(i);
		}

		// 모든 약수들의 합 구하기
		int sum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr[i];
		}

		// 입력받은 수가 완벽한 수인지 조사하고 그에 따라 출력하기
		if (num == sum)
		{
			cout << num << " = ";

			for (int i = 0; i < arr.size(); i++)
			{
				// 마지막 숫자는 숫자 뒤에 공백과 더하기 기호를 출력하지 않음.
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