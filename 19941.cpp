#include <iostream>
using namespace std;

int n, k, ans;
char str[20001];

void GetInput()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    cin >> str;
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'H')
        {
            for (int j = i - k; j <= i + k; j++)
            {
                if (j >= 0 && j < n && str[j] == 'P')
                {
                    str[j] = '0';
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}