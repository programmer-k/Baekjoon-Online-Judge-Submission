#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] + arr[1] == arr[2])
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}