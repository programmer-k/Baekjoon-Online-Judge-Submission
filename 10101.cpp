#include <iostream>
using namespace std;

int main(void)
{
    int angle1, angle2, angle3;
    cin >> angle1 >> angle2 >> angle3;
    if (angle1 + angle2 + angle3 != 180)
        cout << "Error\n";
    else if (angle1 == angle2 && angle2 == angle3)
        cout << "Equilateral\n";
    else if (angle1 != angle2 && angle2 != angle3 && angle1 != angle3)
        cout << "Scalene\n";
    else
        cout << "Isosceles\n";
    return 0;
}