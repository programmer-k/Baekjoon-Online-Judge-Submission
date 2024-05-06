#include <iostream>
#include <string.h>
using namespace std;

int n;
int openLocker1, openLocker2;
int lockersNumsLen;
int lockersNums[20];
int mem[20][20][20];

// mem[i][j][k]는 i번째 벽장이 열려 있고, j번째 벽장이 열려 있고, lockersNums의 k번째 벽장까지
// 처리했을 때 얻을 수 있는 벽장문의 최소 이동 횟수이다.

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> openLocker1 >> openLocker2;
    openLocker1--;
    openLocker2--;
    cin >> lockersNumsLen;
    for (int i = 0; i < lockersNumsLen; i++)
    {
        cin >> lockersNums[i];
        lockersNums[i]--;
    }
}

int CalcMinMove(int locker1, int locker2, int index)
{
    if (mem[locker1][locker2][index] != -1)
    {
        return mem[locker1][locker2][index];
    }

    if (index == lockersNumsLen)
        return 0;

    return mem[locker1][locker2][index] = min(abs(locker1 - lockersNums[index]) + CalcMinMove(lockersNums[index], locker2, index + 1), abs(locker2 - lockersNums[index]) + CalcMinMove(locker1, lockersNums[index], index + 1));
}

void Solve()
{
    memset(mem, -1, sizeof(mem));
    cout << CalcMinMove(openLocker1, openLocker2, 0) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}