#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int scores[6];
    for (int i = 0; i < 6; i++)
        cin >> scores[i];
    
    int minimum1 = min({scores[0], scores[1], scores[2], scores[3]});
    int minimum2 = min(scores[4], scores[5]);
    int total = 0;
    for (int i = 0; i < 6; i++)
        total += scores[i];
    cout << total - minimum1 - minimum2 << '\n';
    return 0;
}