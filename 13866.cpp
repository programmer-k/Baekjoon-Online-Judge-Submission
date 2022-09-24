#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int arr[4];
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    sort(arr, arr + 4);
    cout << abs((arr[0] + arr[3]) - (arr[1] + arr[2])) << '\n';
    return 0;
}