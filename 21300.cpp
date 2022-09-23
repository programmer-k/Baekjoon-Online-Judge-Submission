#include <iostream>
using namespace std;

int main(void)
{
    int arr[6];
    for (int i = 0; i < 6; i++)
        cin >> arr[i];
    int total = 0;
    for (int i = 0; i < 6; i++)
        total += arr[i];
    cout << total * 5 << '\n';
    return 0;
}