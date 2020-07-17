/*
파일 이름 : 2839.cpp
제작자 : 정지운
제작 날짜 : 2017년 4월 2일
프로그램 용도 : 상근이가 설탕 봉지를 몇 개 가져가야 하는지 출력한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n, rem;
	int sugar3 = 0;
	int sugar5;

	cin >> n;
	
	// sugar--;를 while문을 두번째로 돌 때부터 돌리는 좋은 방법이 생각이 안나서 while문 body를 밖으로 꺼냄.
	sugar5 = n / 5;
	rem = n - (sugar5 * 5);
	sugar3 = rem / 3;

	// 5kg 포대를 최대로 맞춰놓고, 하나씩 줄이면서 정확히 옮겨야 되는 kg을 찾아낸다.
	while ((sugar5 * 5 + sugar3 * 3) != n)
	{
		sugar5--;
		
		// sugar5의 값이 -1이 되면, 답을 구할 수 없다는 뜻이므로 -1을 출력하고 프로그램을 종료한다.
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