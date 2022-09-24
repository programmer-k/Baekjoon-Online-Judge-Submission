#include <iostream>
using namespace std;

int main(void)
{
    char ch;
    int startTime[3], endTime[3];
    cin >> startTime[0] >> ch >> startTime[1] >> ch >> startTime[2];
    cin >> endTime[0] >> ch >> endTime[1] >> ch >> endTime[2];
    int start = startTime[2] + startTime[1] * 60 + startTime[0] * 60 * 60;
    int end = endTime[2] + endTime[1] * 60 + endTime[0] * 60 * 60;
    if (start > end)
        end += 24 * 60 * 60;
    cout << end - start << '\n';
    return 0;
}