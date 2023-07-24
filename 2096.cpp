#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[100000][3];
int dpMin[2][3];
int dpMax[2][3];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> map[i][0] >> map[i][1] >> map[i][2];
}

void Solve()
{
    // Base case
    dpMax[0][0] = dpMin[0][0] = map[0][0];
    dpMax[0][1] = dpMin[0][1] = map[0][1];
    dpMax[0][2] = dpMin[0][2] = map[0][2];

    for (int i = 1; i < n; i++)
    {
        int currIdx = i % 2;
        int prevIdx = currIdx == 1 ? 0 : 1;
        
        // case 1: first column
        dpMax[currIdx][0] = max(dpMax[prevIdx][0], dpMax[prevIdx][1]) + map[i][0];
        dpMin[currIdx][0] = min(dpMin[prevIdx][0], dpMin[prevIdx][1]) + map[i][0];

        // case 2: second column
        dpMax[currIdx][1] = max({dpMax[prevIdx][0], dpMax[prevIdx][1], dpMax[prevIdx][2]}) + map[i][1];
        dpMin[currIdx][1] = min({dpMin[prevIdx][0], dpMin[prevIdx][1], dpMin[prevIdx][2]}) + map[i][1];

        // case 3: third column
        dpMax[currIdx][2] = max(dpMax[prevIdx][1], dpMax[prevIdx][2]) + map[i][2];
        dpMin[currIdx][2] = min(dpMin[prevIdx][1], dpMin[prevIdx][2]) + map[i][2];
    }

    int idx = (n - 1) % 2;
    cout << max({dpMax[idx][0], dpMax[idx][1], dpMax[idx][2]}) << ' ';
    cout << min({dpMin[idx][0], dpMin[idx][1], dpMin[idx][2]}) << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}