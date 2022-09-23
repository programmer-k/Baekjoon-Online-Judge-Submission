#include <iostream>
using namespace std;

int main(void)
{
    int z;
    cin >> z;
    for (int i = 0; i < z; i++)
    {
        int w, k;
        cin >> w >> k;
        cout << w * k / 2 << '\n';
    }
    return 0;
}