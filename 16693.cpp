#include <iostream>
using namespace std;

int main(void)
{
    int a1, p1;
    cin >> a1 >> p1;
    int r1, p2;
    cin >> r1 >> p2;
    double area = r1 * r1 * 3.141592653589793238;
    if ((double) a1 / p1 < area / p2)
        cout << "Whole pizza\n";
    else
        cout << "Slice of pizza\n";
    return 0;
}