#include <iostream>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int answers[5];
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> answers[i];
        if (answers[i] == t)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}