#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> numbers, operators, results;

void GetInput()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	for (int i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		operators.push_back(num);
	}
}

void CalculateResult(vector<char>& opArrange)
{
	int result = numbers[0];
	for (unsigned int i = 0; i < opArrange.size(); i++)
	{
		switch (opArrange[i])
		{
		case '+':
			result += numbers[i + 1];
			break;
		case '-':
			result -= numbers[i + 1];
			break;
		case '*':
			result *= numbers[i + 1];
			break;
		case '/':
			result /= numbers[i + 1];
			break;
		}
	}

	results.push_back(result);
}

void Calculate(vector<char>& opArrange)
{
	if (opArrange.size() == n - 1)
	{
		CalculateResult(opArrange);
		return;
	}

	for (unsigned int i = 0; i < operators.size(); i++)
	{
		if (operators[i] > 0)
		{
			switch (i)
			{
			case 0:
				opArrange.push_back('+');
				break;
			case 1:
				opArrange.push_back('-');
				break;
			case 2:
				opArrange.push_back('*');
				break;
			case 3:
				opArrange.push_back('/');
				break;
			}

			operators[i]--;
			Calculate(opArrange);
			operators[i]++;
			opArrange.pop_back();
		}
	}
}

void Output()
{
	int min, max;
	min = max = results[0];

	for (unsigned int i = 1; i < results.size(); i++)
	{
		if (min > results[i])
			min = results[i];
		else if (max < results[i])
			max = results[i];
	}

	cout << max << '\n' << min << '\n';
}

int main(void)
{
	GetInput();

	vector<char> opArrange;
	Calculate(opArrange);
	Output();
	return 0;
}