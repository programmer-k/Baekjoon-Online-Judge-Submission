#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

class Abs
{
    public:
    bool operator()(const int& val1, const int& val2) const
    {
        if (abs(val1) > abs(val2))
            return true;
        else if (abs(val1) < abs(val2))
            return false;
        else
            return val1 > val2;
    }
};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, Abs> abs_heap;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (abs_heap.empty())
                cout << 0 << '\n';
            else
            {
                cout << abs_heap.top() << '\n';
                abs_heap.pop();
            }
        }
        else
        {
            abs_heap.push(num);
        }
    }

    return 0;
}