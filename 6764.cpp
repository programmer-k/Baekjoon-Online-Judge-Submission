#include <iostream>
using namespace std;

int main(void)
{
    int arr[4];
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    
    bool rising = true, diving = true, constant = true;
    for (int i = 1; i < 4; i++)
    {
        if (arr[i - 1] < arr[i])
        {
            diving = false;
            constant = false;
        }
        else if (arr[i - 1] > arr[i])
        {
            rising = false;
            constant = false;
        }
        else
        {
            rising = false;
            diving = false;
        }
    }

    if (rising)
        cout << "Fish Rising";
    else if (diving)
        cout << "Fish Diving";
    else if (constant)
        cout << "Fish At Constant Depth";
    else
        cout << "No Fish";
    return 0;
}