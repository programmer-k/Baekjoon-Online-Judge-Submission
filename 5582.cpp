#include <iostream>
#include <string>
using namespace std;

string str1;
string str2;
int mem[4000][4000];

// mem[i][j]는 str1에서 i번째 문자열까지, str2에서 j번째 문자열까지 사용했을 때,
// 얻을 수 있는 가장 긴 공통 부분 문자열이다.

// 따라서, str1[i]와 str2[j]가 같다면, 1이 된다.
// 또한, 이전의 값도 참고해야 한다.

void GetInput()
{
    cin >> str1;
    cin >> str2;
}

void Solve()
{
    for (unsigned int i = 0; i < str1.length(); i++)
        if (str1[i] == str2[0])
            mem[i][0] = 1;
    
    for (unsigned int i = 0; i < str2.length(); i++)
        if (str2[i] == str1[0])
            mem[0][i] = 1;

    for (unsigned int i = 1; i < str1.length(); i++)
        for (unsigned int j = 1; j < str2.length(); j++)
            if (str1[i] == str2[j])
                mem[i][j] = mem[i - 1][j - 1] + 1;


    int maximum = -1;
    for (unsigned int i = 0; i < str1.length(); i++)
        for (unsigned int j = 0; j < str2.length(); j++)
            maximum = max(maximum, mem[i][j]);

    cout << maximum << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}