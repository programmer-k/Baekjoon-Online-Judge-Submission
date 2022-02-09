#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int c, n, ans;
priority_queue<int, vector<int>, greater<int>> chicken_min_heap;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cow_min_heap_end;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cow_min_heap_start;

void GetInput()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> c >> n;

    for (int i = 0; i < c; i++)
    {
        int temp;
        cin >> temp;
        chicken_min_heap.push(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        cow_min_heap_start.push({ start, end });
    }
}

void Solve()
{
    while (!chicken_min_heap.empty())
    {
        int chicken = chicken_min_heap.top();

        while (!cow_min_heap_start.empty() && chicken >= cow_min_heap_start.top().first)
        {
            cow_min_heap_end.push({cow_min_heap_start.top().second, cow_min_heap_start.top().first});
            cow_min_heap_start.pop();
        }
        
        while (!cow_min_heap_end.empty() && chicken > cow_min_heap_end.top().first)
            cow_min_heap_end.pop();

        if (cow_min_heap_end.empty())
            chicken_min_heap.pop();
        else
        {
            ans++;
            chicken_min_heap.pop();
            cow_min_heap_end.pop();
        }
    }

    cout << ans << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}