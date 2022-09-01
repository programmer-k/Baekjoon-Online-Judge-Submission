#include <iostream>
#include <cmath>
using namespace std;

int a, k;
int arr[1000001];

// arr[i] = min(arr[i - 1], arr[i / 2])
// arr[i] = arr[i - 1]
// 정수 A를 정수 i로 만들기 위해 필요한 최소 연산 횟수
// base: arr[A] = 0

int Solve(int i)
{
    if (arr[i] != 0)
        return arr[i];

    if (i == a)
        return arr[i] = 0;
    else if (i <= a)
        return 123456789;

    if (i % 2 == 0)
    {
        return arr[i] = min(Solve(i - 1), Solve(i / 2)) + 1;
    }
    else
    {
        return arr[i] = Solve(i - 1) + 1;
    }
}


int main(void)
{
    cin >> a >> k;
    cout << Solve(k) << endl;
    return 0;
}