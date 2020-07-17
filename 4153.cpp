/*
파일 이름 : 4153.cpp
제작자 : 정지운
제작 날짜 : 2017년 7월 25일
프로그램 용도 : 직각 삼각형인지 판단한다.
*/

#include <iostream>
using namespace std;

/* 가장 큰 수를 찾아서 ptr1이 가리키는 변수와 값을 교환하는 함수이다. */
void FindLargest(int * ptr1, int * ptr2, int * ptr3)
{
	if (*ptr1 >= *ptr2 && *ptr1 >= *ptr3)
		return;
	else if (*ptr2 >= *ptr1 && *ptr2 >= *ptr3)
	{
		int temp = *ptr2;
		*ptr2 = *ptr1;
		*ptr1 = temp;
	}
	else
	{
		int temp = *ptr3;
		*ptr3 = *ptr1;
		*ptr1 = temp;
	}

}

int main(void)
{
	while (true)
	{
		int side1, side2, side3;

		// 입력
		cin >> side1 >> side2 >> side3;

		// 입력이 0, 0, 0이면 프로그램 종료
		if (side1 == 0 && side2 == 0 && side3 == 0)
			break;

		// 제일 큰 수를 side1에 저장하기
		FindLargest(&side1, &side2, &side3);

		// 직각 삼각형인지 조사하기
		if (side1 * side1 == side2 * side2 + side3 * side3)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}