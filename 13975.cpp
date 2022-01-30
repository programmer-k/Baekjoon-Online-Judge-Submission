#include <iostream>
#include <queue>
using namespace std;

int t, k;

void GetInput1()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
}

void GetInput2(priority_queue<long long, vector<long long>, greater<long long>>& min_heap)
{
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        min_heap.push(temp);
    }
}

long long Calc(priority_queue<long long, vector<long long>, greater<long long>>& min_heap)
{
    long long total = 0;

    while (min_heap.size() > 1)
    {
        long long val1 = min_heap.top();
        min_heap.pop();

        long long val2 = min_heap.top();
        min_heap.pop();

        min_heap.push(val1 + val2);
        total += val1 + val2;
    }

    return total;
}

int main(void)
{
    GetInput1();
    for (int i = 0; i < t; i++)
    {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        GetInput2(min_heap);
        cout << Calc(min_heap) << '\n';
    }
    return 0;
}