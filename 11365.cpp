#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	while (true)
	{
		string str;

		getline(cin, str);

		if (str.compare("END") == 0)
			break;
		
		for (int i = str.size() - 1; i >= 0; i--)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}