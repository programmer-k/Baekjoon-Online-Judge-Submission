#include <iostream>
using namespace std;

int main(void)
{
    char ch;
    int cnt = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> ch;
        if (ch == 'W')
            cnt++;
    }
    if (cnt >= 5)
        cout << "1\n";
    else if (cnt >= 3)
        cout << "2\n";
    else if (cnt >= 1)
        cout << "3\n";
    else
        cout << "-1\n";
    return 0;
}