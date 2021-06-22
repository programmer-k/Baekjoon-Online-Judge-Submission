#include <iostream>
using namespace std;

int n, arr[1000000];
bool ascend[1000000], descend[1000000];
int ascendFalse, descendFalse, ascendFalsePos, descendFalsePos;

void GetInput()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void Calculate()
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] <= arr[i + 1])
			ascend[i] = true;
		else
		{
			ascend[i] = false;
			ascendFalse++;
			ascendFalsePos = i;
		}

		if (arr[i] >= arr[i + 1])
			descend[i] = true;
		else
		{
			descend[i] = false;
			descendFalse++;
			descendFalsePos = i;
		}
	}

	if (ascendFalse >= 2 && descendFalse >= 2)
		cout << -1 << '\n';
	else if (ascendFalse == 0 || descendFalse == 0)
		cout << 0 << '\n';
	else if (ascendFalse == 1 && descendFalse == 1)
	{
		//cout << "123" << endl;
		bool a = false, b = false;
		if (arr[n - 1] <= arr[0])
			a = true;

		if (arr[n - 1] >= arr[0])
			b = true;

		//cout << ascendFalsePos << endl;
		//cout << descendFalsePos << endl;

		if (a && b)
			cout << ((ascendFalsePos + 1 <= descendFalsePos + 1) ? ascendFalsePos + 1 : descendFalsePos + 1) << '\n';
		else if (a)
			cout << ascendFalsePos + 1 << '\n';
		else if (b)
			cout << descendFalsePos + 1 << '\n';
		else
			cout << -1 << '\n';
	}
	else if (ascendFalse == 1)
	{
		//cout << "1234" << endl;
		if (arr[n - 1] <= arr[0])
			cout << ascendFalsePos + 1 << '\n';
		else
			cout << -1 << '\n';
	}
	else
	{
		//cout << "1235" << endl;
		if (arr[n - 1] >= arr[0])
			cout << descendFalsePos + 1 << '\n';
		else
			cout << -1 << '\n';
	}
}

int main(void)
{
	GetInput();
	Calculate();
	return 0;
}