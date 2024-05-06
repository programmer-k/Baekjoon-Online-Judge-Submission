#include <iostream>
#include <vector>
using namespace std;

int t;
unsigned int n;
vector<int> answers;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void Solve()
{
    answers.push_back(2);
    answers.push_back(3);

    for (int i = 4; i <= 1000000000; i++)
    {
        int length = answers.size();
        int a1 = answers[length - 2];
        int a2 = answers[length - 1];

        if (3 * i % (a1 + a2) != 0)
            answers.push_back(i);
        
        if (answers.size() == 200000)
            break;
    }
}

int main(void)
{
    Solve();
    GetInput();
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (unsigned int i = 0; i < n; i++)
            cout << answers[i] << ' ';
        cout << '\n';
    }
    return 0;
}