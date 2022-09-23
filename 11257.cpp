#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id, l1, l2, l3;
        cin >> id >> l1 >> l2 >> l3;
        cout << id << ' ' << l1 + l2 + l3 << ' ';
        if (l1 + l2 + l3 >= 55 && l1 >= 35 * 0.3 && l2 >= 25 * 0.3 && l3 >= 40 * 0.3)
            cout << "PASS\n";
        else
            cout << "FAIL\n";
    }
    return 0;
}