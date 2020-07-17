/*
파일 이름 : 4673.cpp
제작자 : 정지운
제작 날짜 : 2018년 3월 4일
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vec(10000, 0);

	// 1부터 10000까지를 n에 대입해서 d(n)이 무엇인지 구하고 d(n)이 있으면 벡터에 1을 저장한다.
	for (int i = 1; i <= 10000; i++)
	{
		// d(n) 구하기
		int dn = i;
		int tempNum = i;

		// 각 자리 수 구해서 더하기
		do
		{
			dn += tempNum % 10;
			tempNum /= 10;
		} while (tempNum != 0);

		// d(n) 구하기 완료!

		// d(n)이라는 숫자는 생성자가 있으므로 벡터에 1을 저장
		// d(n)이 10000보다 크면 저장할 이유가 없으므로 건너뛴다.
		if (dn <= 10000)
		{
			vec[dn - 1] = 1;
		}
	}

	// 출력
	for (int i = 0; i < 10000; i++)
	{
		if (vec[i] == 0)
			cout << i + 1 << endl;
	}	
	return 0;
}