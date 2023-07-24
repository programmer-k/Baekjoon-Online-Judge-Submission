#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string str;
int mem[5001] = { 1, 1 };

// mem[i]는 i번째 숫자까지 읽었을 때 나올 수 있는 해석의 가짓 수. (1 <= i <= 5000)

void Solve()
{
    int len = str.length();
    str.insert(0, "?");
    
    // First number
    if (str[1] == '0')
    {
        cout << '0' << '\n';
        return;
    }

    for (int i = 2; i <= len; i++)
    {
        bool validOneDigit = true;
        bool validTwoDigits = true;

        // Valid one-digit number
        if (str[i] >= '1' && str[i] <= '9')
            mem[i] += mem[i - 1];
        else
            validOneDigit = false;

        // Valid two-digits number
        int num = (str[i - 1] - '0') * 10 + str[i] - '0';
        if (num >= 10 && num <= 26)
            mem[i] += mem[i - 2];
        else
            validTwoDigits = false;
        
        /*if (!validOneDigit && !validTwoDigits)
        {
            cout << 0 << '\n';
            return;
        }*/

        mem[i] %= 1000000;
    }

    cout << mem[len] << '\n';
}

int main(void)
{
    cin >> str;
    Solve();
    return 0;
}