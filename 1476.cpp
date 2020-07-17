#include <iostream>
using namespace std;

int main(void)
{
	int earth, sun, moon;
	int e = 1, s = 1, m = 1;

	cin >> earth >> sun >> moon;

	int year = 1;

	// °è»ê
	while (true)
	{
		if (earth == e && sun == s && moon == m)
			break;

		e++, s++, m++;
		year++;

		if (e == 16)
			e = 1;
		if (s == 29)
			s = 1;
		if (m == 20)
			m = 1;
	}

	cout << year << endl;
	return 0;
}