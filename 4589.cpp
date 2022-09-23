#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    cout << "Gnomes:\n";
    for (int i = 0; i < n; i++)
    {
        int arr[3];
        for (int j = 0; j < 3; j++)
            cin >> arr[j];
        
        if ((arr[0] < arr[1] && arr[1] < arr[2]) || (arr[0] > arr[1] && arr[1] > arr[2]))
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
    return 0;
}