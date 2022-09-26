#include <iostream>
using namespace std;

int main(void)
{
    int three1, two1, one1;
    int three2, two2, one2;
    cin >> three1 >> two1 >> one1;
    cin >> three2 >> two2 >> one2;
    if (three1 * 3 + two1 * 2 + one1 > three2 * 3 + two2 * 2 + one2)
        cout << "A\n";
    else if (three1 * 3 + two1 * 2 + one1 < three2 * 3 + two2 * 2 + one2)
        cout << "B\n";
    else
        cout << "T\n";
    return 0;
}