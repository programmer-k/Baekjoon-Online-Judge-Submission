#include <iostream>
using namespace std;

int main(void)
{
    int scores[5];
    for (int i = 0; i < 5; i++)
        cin >> scores[i];
    int total = 0;
    for (int i = 0; i < 5; i++)
        total += scores[i];
    cout << total << '\n';
    return 0;
}