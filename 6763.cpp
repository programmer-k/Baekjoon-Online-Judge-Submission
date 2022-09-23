#include <iostream>
using namespace std;

int main(void)
{
    int limit, speed;
    cin >> limit >> speed;
    if (speed <= limit)
        cout << "Congratulations, you are within the speed limit!" << '\n';
    else if (speed <= limit + 20)
        cout << "You are speeding and your fine is $" << 100 << ".\n";
    else if (speed <= limit + 30)
        cout << "You are speeding and your fine is $" << 270 << ".\n";
    else
        cout << "You are speeding and your fine is $" << 500 << ".\n";
    return 0;
}