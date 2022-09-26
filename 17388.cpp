#include <iostream>
using namespace std;

int main(void)
{
    int s, k, h;
    cin >> s >> k >> h;
    if (s + k + h >= 100)
        cout << "OK" << '\n';
    else if (s < k && s < h)
        cout << "Soongsil\n";
    else if (k < s && k < h)
        cout << "Korea\n";
    else
        cout << "Hanyang\n";
    return 0;
}