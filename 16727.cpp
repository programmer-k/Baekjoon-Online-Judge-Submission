#include <iostream>
using namespace std;

int main(void)
{
    int p1, s1, s2, p2;
    cin >> p1 >> s1 >> s2 >> p2;
    if (p1 + p2 > s1 + s2)
        cout << "Persepolis\n";
    else if (p1 + p2 < s1 + s2)
        cout << "Esteghlal\n";
    else if (s1 > p2)
        cout << "Esteghlal\n";
    else if (s1 < p2)
        cout << "Persepolis\n";
    else
        cout << "Penalty\n";
    return 0;
}