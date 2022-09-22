#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int dp[1000][1000];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> str1 >> str2;
}

void Solve()
{
    if(str1[0] == str2[0])
        dp[0][0] = 1;

    for (unsigned int j = 1; j < str2.length(); j++)
        if (str1[0] == str2[j] || dp[0][j - 1])
            dp[0][j] = 1;

    for (unsigned int i = 1; i < str1.length(); i++)
    {
        if (str1[i] == str2[0] || dp[i - 1][0])
            dp[i][0] = 1;

        for (unsigned int j = 1; j < str2.length(); j++)
        {
            if (str1[i] == str2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[str1.length() - 1][str2.length() - 1] << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}