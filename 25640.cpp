#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str1;
    cin >> str1;
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str2;
        cin >> str2;
        if (str1 == str2)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
