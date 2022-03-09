#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> list;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        
        cin >> num;
        list.push_back({ num, 1 });

        cin >> num;
        list.push_back({ num, 0 });
    }
}

void Solve()
{
    sort(list.begin(), list.end());

    int maxCount = 0, currentCount = 0;
    for (unsigned int i = 0; i < list.size(); i++)
    {
        if (list[i].second)
            maxCount = max(maxCount, ++currentCount);
        else
            currentCount--;
    }

    cout << maxCount << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}