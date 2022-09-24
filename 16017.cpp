#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2, num3, num4;
    cin >> num1 >> num2 >> num3 >> num4;
    if ((num1 == 8 || num1 == 9) && (num4 == 8 || num4 == 9) && num2 == num3)
        cout << "ignore\n";
    else
        cout << "answer\n";
    return 0;
}