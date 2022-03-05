#include <iostream>
using namespace std;

int t, n;
int arrow[100001];
int isDone[100001];

void GetInput1()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
}

void GetInput2()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arrow[i];
        isDone[i] = 0;
    }
}

int CountCycle(int start)
{
    int cnt = 0, current = start;

    do
    {
        cnt++;
        current = arrow[current];
    } while (start != current);

    return cnt;
}

int Traverse(int start)
{
    if (isDone[start] == 1)
        return CountCycle(start);
    else if (isDone[start] == 2)
        return 0;

    isDone[start] = 1;
    int cycleCount = Traverse(arrow[start]);
    isDone[start] = 2;
    return cycleCount;
}

void Solve()
{
    int successCount = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!isDone[i])
            successCount += Traverse(i);
    }

    cout << n - successCount << '\n';
}

int main(void)
{
    GetInput1();
    for (int i = 0; i < t; i++)
    {
        GetInput2();
        Solve();
    }
    return 0;
}