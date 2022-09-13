#include <iostream>
#include <algorithm>
using namespace std;

int n;
int red[1000], green[1000], blue[1000];
int redMinCost[1000], greenMinCost[1000], blueMinCost[1000];

// redMinCost[i] = min(greenMinCost[i - 1], blueMinCost[i - 1]) + red[i];
// Intuition: *MinCost[i]에 i번째 집에 *을 선택했을 때의 비용의 최소값을 저장이 되어 있다고 가정
// 따라서 이전 집에서 중복되지 않는 색 중에서 최소 값을 참조해야 함.

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> red[i] >> green[i] >> blue[i];
}

void Solve()
{
    redMinCost[0] = red[0];
    greenMinCost[0] = green[0];
    blueMinCost[0] = blue[0];

    for (int i = 1; i < n; i++)
    {
        redMinCost[i] = min(greenMinCost[i - 1], blueMinCost[i - 1]) + red[i];
        greenMinCost[i] = min(redMinCost[i - 1], blueMinCost[i - 1]) + green[i];
        blueMinCost[i] = min(redMinCost[i - 1], greenMinCost[i - 1]) + blue[i];
    }

    cout << min({ redMinCost[n - 1], greenMinCost[n - 1], blueMinCost[n - 1]}) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}