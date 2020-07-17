/*
파일 이름 : 1003.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 23일
프로그램 용도 : n번째 피보나치 수열을 재귀 형태로 계산할 때, 0번째와 1번째 피보나치 수열이 몇 번 반환되는지 출력한다.
*/

//#include <iostream>
//using namespace std;
//
//int zero;
//int one;
//
///* n번째 피보나치 수열의 수를 계산할 때 0과 1이 몇 번 반환되는지 계산하는 함수이다. */
//void fibonacci(int num)
//{
//	if (num == 0)
//		zero += 1;
//	else if (num == 1)
//		one += 1;
//	else
//	{
//		fibonacci(num - 1);
//		fibonacci(num - 2);
//	}
//}
//
//int main(void)
//{
//	int tc;
//
//	// 입력
//	cin >> tc;
//
//	// testcase의 수만큼 반복
//	for (int i = 0; i < tc; i++)
//	{
//		int num;
//
//		// 입력
//		cin >> num;
//
//		// 전역변수 초기화 및 계산
//		zero = one = 0;
//		fibonacci(num);
//
//		// 출력
//		cout << zero << ' ' << one << endl;
//	}
//
//	return 0;
//}

/*
제작 날짜 : 2018년 3월 17일
*/

#include <iostream>
using namespace std;

typedef struct ZeroOne
{
	int zero;
	int one;
};

ZeroOne fibonacci(int n);

// 피보나치 값을 저장하는 전역 변수
ZeroOne arr[41];

// 0과 1을 카운트하는 변수
int zero, one;

int main(void)
{
	int tc;

	// 입력
	cin >> tc;

	// 피보나치 기본 설정
	arr[0] = { 1, 0 };
	arr[1] = { 0, 1 };

	for (int i = 0; i < tc; i++)
	{
		// 매번 돌릴 때마다 전역 변수 초기화하기
		zero = one = 0;

		int num;

		// 입력
		cin >> num;

		// 답 구하기
		ZeroOne ans = fibonacci(num);

		// 출력
		cout << ans.zero << ' ' << ans.one << endl;
	}
}

ZeroOne fibonacci(int n) {
	if (n == 0) {
		return arr[0];
	}
	else if (n == 1) {
		return arr[1];
	}
	else {
		
		if (arr[n].zero == 0 && arr[n].one == 0)
		{
			ZeroOne temp1 = fibonacci(n - 1);
			ZeroOne temp2 = fibonacci(n - 2);

			arr[n].zero = temp1.zero + temp2.zero;
			arr[n].one = temp1.one + temp2.one;

			return arr[n];
		}
		else
			return arr[n];
	}
}