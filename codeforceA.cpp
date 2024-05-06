#include <iostream>
#include <string>
using namespace std;

int t;
int n, m;
string x, s;

int main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        cin >> x >> s;

        int cnt = 0;
        while (x.size() < s.size())
        {
            x += x;
            cnt++;
        }
        size_t result = x.find(s);
        if (result != string::npos)
            cout << cnt << '\n';
        else if ((x + x).find(s) != string::npos)
            cout << cnt + 1 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}