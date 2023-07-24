#include <iostream>
#include <cstring>
using namespace std;

int n;
int w[16][16];
int mem[16][1 << 16];

// mem[i][j]는 i번째 도시에서, j라는 방문 상태를 가지고 있을 때, 비용의 최솟값

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
}

int DP(int currentCity, const int visitStatus)
{
    if (visitStatus == (1 << n) - 1)
    {
        if (w[currentCity][0] == 0)
            return 1234567890;
        else
            return w[currentCity][0];
    }

    if (mem[currentCity][visitStatus] != -1)
        return mem[currentCity][visitStatus];

    int value = 1234567890;

    // Visit all other cities if possible.
    for (int i = 0; i < n; i++)
    {
        // Visit whenever there is a non-visited path.
        if (w[currentCity][i] && !(visitStatus & (1 << i)))
        {
            int newVisitStatus = visitStatus | (1 << i);
            value = min(value, DP(i, newVisitStatus) + w[currentCity][i]);
        }
    }

    mem[currentCity][visitStatus] = value;
    return mem[currentCity][visitStatus];
}

void Solve()
{
    memset(mem, -1, sizeof(mem));
    cout << DP(0, 1) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}