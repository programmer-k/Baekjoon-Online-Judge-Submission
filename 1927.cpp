#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (min_heap.empty())
                cout << 0 << '\n';
            else
            {
                cout << min_heap.top() << '\n';
                min_heap.pop();
            }
        }
        else
        {
            min_heap.push(num);
        }
    }

    return 0;
}