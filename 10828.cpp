#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
stack<int> s;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if (str == "pop")
        {
            if (!s.empty())
            {
                cout << s.top() << '\n';
                s.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (str == "size")
        {
            cout << s.size() << '\n';
        }
        else if (str == "empty")
        {
            if (s.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (str == "top")
        {
            if (!s.empty())
                cout << s.top() << '\n';
            else
                cout << -1 << '\n';
        }
        else
        {
            int num;
            cin >> num;
            s.push(num);
        }
    }
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}
