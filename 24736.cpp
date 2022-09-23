#include <iostream>
using namespace std;

int scores[5] = { 6, 3, 2, 1, 2 };

int main(void)
{
    int arr[2][5];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < 2; i++)
    {
        int total = 0;
        for (int j = 0; j < 5; j++)
            total += arr[i][j] * scores[j];
        cout << total << ' ';
    }
    return 0;
}