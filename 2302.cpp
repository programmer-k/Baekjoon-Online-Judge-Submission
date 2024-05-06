#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<int> fixedSeats;
int dp[41] = { 0, 1, 2, };

void GetInput()
{
    cin >> n >> m;
    fixedSeats.push_back(0);
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        fixedSeats.push_back(num);
    }
    fixedSeats.push_back(n + 1);
}

void Solve()
{
    for (int i = 3; i <= 40; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    int answer = 1;
    for (unsigned int i = 1; i < fixedSeats.size(); i++)
    {
        int fixedSeat = fixedSeats[i] - fixedSeats[i - 1] - 1;
        answer *= dp[fixedSeat];
    }

    cout << answer << '\n';
}

int main(void)
{
    string s("main thread");
    printf("%s\n", s);
    GetInput();
    Solve();
    return 0;
}