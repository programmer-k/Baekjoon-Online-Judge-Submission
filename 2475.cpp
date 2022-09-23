#include <iostream>
using namespace std;

int main(void)
{
    int num;
    int answer = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        answer += num * num;
    }

    cout << answer % 10 << '\n';
    return 0;
}