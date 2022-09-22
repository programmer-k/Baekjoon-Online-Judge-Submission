#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int length, width, height, n;
pair<int, int> cubes[20];

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> length >> width >> height >> n;

    for (int i = 0; i < n; i++)
        cin >> cubes[i].first >> cubes[i].second;
}

int Solve(int l, int w, int h)
{
    if (l == 0 || w == 0 || h == 0)
        return 0;

    int minimumLength = min({ l, w, h });

    // Find the largest cube that fits in.
    for (int i = log2(minimumLength); i >= 0; i--)
    {
        if (cubes[i].second == 0)
            continue;

        cubes[i].second--;
        int cubeSize = pow(2, cubes[i].first);
        int cube1 = Solve(l - cubeSize, cubeSize, h);
        int cube2 = Solve(cubeSize, cubeSize, h - cubeSize);
        int cube3 = Solve(l, w - cubeSize, h);
        if (cube1 != -1 && cube2 != -1 && cube3 != -1)
            return cube1 + cube2 + cube3 + 1;
        else
            return -1;
    }

    return -1;
}

int main(void)
{
    GetInput();
    cout << Solve(length, width, height) << '\n';
    return 0;
}