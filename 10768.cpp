#include <iostream>
using namespace std;

int main(void)
{
    int month, day;
    cin >> month >> day;
    if (month == 1 || month == 2 && day < 18)
        cout << "Before\n";
    else if (month == 2 && day == 18)
        cout << "Special\n";
    else
        cout << "After\n";
    return 0;
}