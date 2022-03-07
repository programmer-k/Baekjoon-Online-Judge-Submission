#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> list;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
}

void Solve()
{
    sort(list.begin(), list.end());

    int maxWeight = 0;
    for (unsigned int i = 0; i < list.size(); i++)
    {
        int currentMaxWeight = list[i] * (list.size() - i);
        maxWeight = max(maxWeight, currentMaxWeight);
    }

    cout << maxWeight << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}