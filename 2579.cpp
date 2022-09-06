#include <iostream>
using namespace std;

int n;
int stairs[300];
int dp1[300];
int dp2[300];

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> stairs[i];
    
    dp1[0] = stairs[0];
    dp2[0] = 0;
    dp1[1] = stairs[1];
    dp2[1] = stairs[0] + stairs[1];
    
    for (int i = 2; i < n; i++)
    {
        dp1[i] = max(dp1[i - 2], dp2[i - 2]) + stairs[i];
        dp2[i] = dp1[i - 1] + stairs[i];
    }

    cout << max(dp1[n - 1], dp2[n - 1]) << endl;
    return 0;
}