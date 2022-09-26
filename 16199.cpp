#include <iostream>
using namespace std;

int main(void)
{
    int year1, month1, day1;
    cin >> year1 >> month1 >> day1;
    int year2, month2, day2;
    cin >> year2 >> month2 >> day2;
    if ((month1 < month2) || (month1 == month2 && day1 <= day2))
        cout << year2 - year1 << '\n';
    else
        cout << year2 - year1 - 1 << '\n';
    cout << year2 - year1 + 1 << '\n';
    cout << year2 - year1 << '\n';
    return 0;
}