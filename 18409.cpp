#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int cnt = 0;
    string str;
    cin >> str;
    for (unsigned int j = 0; j < str.length(); j++)
    {
        if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u')
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}