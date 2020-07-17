/*
파일 이름 : 1157.cpp
제작자 : 정지운
제작 날짜 : 2017년 5월 20일
제작 목표 : 문자열을 처리한다.
*/

#include <iostream>
using namespace std;

int main(void)
{
	char str[1000001];
	cin >> str;

	int alphabet[26] = { 0 };
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a' || str[i] == 'A')
			alphabet[0]++;
		else if (str[i] == 'b' || str[i] == 'B')
			alphabet[1]++;
		else if (str[i] == 'c' || str[i] == 'C')
			alphabet[2]++;
		else if (str[i] == 'd' || str[i] == 'D')
			alphabet[3]++;
		else if (str[i] == 'e' || str[i] == 'E')
			alphabet[4]++;
		else if (str[i] == 'f' || str[i] == 'F')
			alphabet[5]++;
		else if (str[i] == 'g' || str[i] == 'G')
			alphabet[6]++;
		else if (str[i] == 'h' || str[i] == 'H')
			alphabet[7]++;
		else if (str[i] == 'i' || str[i] == 'I')
			alphabet[8]++;
		else if (str[i] == 'j' || str[i] == 'J')
			alphabet[9]++;
		else if (str[i] == 'k' || str[i] == 'K')
			alphabet[10]++;
		else if (str[i] == 'l' || str[i] == 'L')
			alphabet[11]++;
		else if (str[i] == 'm' || str[i] == 'M')
			alphabet[12]++;
		else if (str[i] == 'n' || str[i] == 'N')
			alphabet[13]++;
		else if (str[i] == 'o' || str[i] == 'O')
			alphabet[14]++;
		else if (str[i] == 'p' || str[i] == 'P')
			alphabet[15]++;
		else if (str[i] == 'q' || str[i] == 'Q')
			alphabet[16]++;
		else if (str[i] == 'r' || str[i] == 'R')
			alphabet[17]++;
		else if (str[i] == 's' || str[i] == 'S')
			alphabet[18]++;
		else if (str[i] == 't' || str[i] == 'T')
			alphabet[19]++;
		else if (str[i] == 'u' || str[i] == 'U')
			alphabet[20]++;
		else if (str[i] == 'v' || str[i] == 'V')
			alphabet[21]++;
		else if (str[i] == 'w' || str[i] == 'W')
			alphabet[22]++;
		else if (str[i] == 'x' || str[i] == 'X')
			alphabet[23]++;
		else if (str[i] == 'y' || str[i] == 'Y')
			alphabet[24]++;
		else if (str[i] == 'z' || str[i] == 'Z')
			alphabet[25]++;
	}

	int largest = 0;
	for (int i = 0; i < 26; i++)
		if (alphabet[i] >= largest)
			largest = alphabet[i];

	int sameNum = 0;
	for (int i = 0; i < 26; i++)
		if (alphabet[i] == largest)
			sameNum++;

	if (sameNum == 1)
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] == largest)
			{
				cout << (char)(i + 'A') << endl;
				break;
			}
		}
	else
		cout << '?' << endl;
	return 0;

}