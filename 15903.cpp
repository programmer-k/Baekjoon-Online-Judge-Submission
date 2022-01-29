#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> min_heap;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        min_heap.push(temp);
    }

    for (int i = 0; i < m; i++)
    {
        long long val1 = min_heap.top();
        min_heap.pop();

        long long val2 = min_heap.top();
        min_heap.pop();

        min_heap.push(val1 + val2);
        min_heap.push(val1 + val2);
    }

    long long total = 0;
    while (!min_heap.empty())
    {
        total += min_heap.top();
        min_heap.pop();
    }

    cout << total << '\n';
    return 0;
}