#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> min_heap;

void GetInput()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        min_heap.push(temp);
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;

            if (temp > min_heap.top())
            {
                min_heap.pop();
                min_heap.push(temp);
            }
        }
}

int main(void)
{
    GetInput();
    cout << min_heap.top() << '\n';
    return 0;
}