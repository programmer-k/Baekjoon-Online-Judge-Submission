#include <iostream>
using namespace std;

int n, m;
int matrix1[100][100], matrix2[100][100];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix1[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix2[i][j];
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix1[i][j] + matrix2[i][j] << ' ';
        cout << '\n';
    }
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}