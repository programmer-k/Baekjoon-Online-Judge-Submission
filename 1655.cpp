#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int n;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
}

void Solve()
{
    int median;
    cin >> median;
    cout << median << '\n';

    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;

        if (num < median)
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        if (maxHeap.size() + 2 == minHeap.size())
        {
            maxHeap.push(median);
            median = minHeap.top();
            minHeap.pop();
        }
        else if (maxHeap.size() > minHeap.size())
        {
            minHeap.push(median);
            median = maxHeap.top();
            maxHeap.pop();
        }

        cout << median << '\n';
    }
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}