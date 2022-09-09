#include <iostream>
using namespace std;

int n;
int arr[100][100];
long long possibleRoute[100][100] = { 1, };

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int jump = arr[i][j];
            long long currentPossibleRoute = possibleRoute[i][j];

            if (i == n - 1 && j == n - 1)
                break;

            if (j + jump < n)
                possibleRoute[i][j + jump] += currentPossibleRoute;
            if (i + jump < n)
                possibleRoute[i + jump][j] += currentPossibleRoute;
        }
    }

    cout << possibleRoute[n - 1][n - 1] << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}