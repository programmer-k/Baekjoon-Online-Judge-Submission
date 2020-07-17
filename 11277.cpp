#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool ans;
int n, m;
vector<pair<int, int>> clauses;
vector<bool> variables;

void GetInput()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		clauses.push_back(make_pair(num1, num2));
	}
}

void Calculate()
{
	if (variables.size() == n)
	{
		for (unsigned int i = 0; i < clauses.size(); i++)
		{
			bool leftOperand = variables[abs(clauses[i].first) - 1];
			bool rightOperand = variables[abs(clauses[i].second) - 1];

			if (clauses[i].first < 0)
				leftOperand = !leftOperand;

			if (clauses[i].second < 0)
				rightOperand = !rightOperand;

			if (!leftOperand && !rightOperand)
				return;
		}

		ans = true;
		return;
	}

	variables.push_back(true);
	Calculate();
	variables.pop_back();

	variables.push_back(false);
	Calculate();
	variables.pop_back();
}

int main(void)
{
	GetInput();
	Calculate();
	cout << ans << '\n';
	return 0;
}