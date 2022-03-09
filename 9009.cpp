#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int t, num;
vector<int> fibonacci;

void GetInput1()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void GetInput2()
{
    cin >> num;
}

void Solve()
{
    stack<int> ans;
    for (unsigned int i = fibonacci.size() - 1; i > 0; i--)
    {
        if (fibonacci[i] <= num)
        {
            num -= fibonacci[i];
            ans.push(fibonacci[i]);
        }
    }

    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';
}

void PreCalc()
{
    fibonacci.push_back(0);
    fibonacci.push_back(1);

    do
    {
        int newFibonacci = fibonacci[fibonacci.size() - 2] + fibonacci[fibonacci.size() - 1];
        fibonacci.push_back(newFibonacci);
    } while (fibonacci[fibonacci.size() - 1] <= 1000000000);
}

int main(void)
{
    PreCalc();
    GetInput1();
    for (int i = 0; i < t; i++)
    {
        GetInput2();
        Solve();
    }
    return 0;
}