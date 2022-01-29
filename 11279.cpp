#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int> max_heap;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (max_heap.empty())
                cout << 0 << '\n';
            else
            {
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
        else
        {
            max_heap.push(num);
        }
    }

    return 0;
}