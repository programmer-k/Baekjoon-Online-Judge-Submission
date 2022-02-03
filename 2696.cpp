#include <iostream>
#include <queue>
using namespace std;

int t, m;


void GetInput1()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
}

void Solve()
{
    int median;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    cin >> m;
    cin >> median;
    cout << m / 2 + 1 << '\n';
    cout << median << ' ';

    for (int i = 1; i < m; i++)
    {
        int input;
        cin >> input;

        if (input < median)
            max_heap.push(input);
        else
            min_heap.push(input);

        if (i % 2 == 0)
        {
            if (max_heap.size() > min_heap.size())
            {
                min_heap.push(median);
                median = max_heap.top();
                max_heap.pop();
            }
            else if (max_heap.size() < min_heap.size())
            {
                max_heap.push(median);
                median = min_heap.top();
                min_heap.pop();
            }

            if (i % 20 == 0)
                cout << '\n';

            cout << median << ' ';
        }


    }

    cout << '\n';
}

int main(void)
{
    GetInput1();
    for (int i = 0; i < t; i++)
    {
        Solve();
    }

    return 0;
}